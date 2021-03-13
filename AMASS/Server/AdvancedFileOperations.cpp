#include "AdvancedFileOperations.h"
using namespace std;
fstream initFile()
{
	fstream file;
	file.open("data.dat", ios::in | ios::out | ios::binary | ios::trunc);
	return file;
}

void readRecord(fstream& file, ROLE& role)
{
	readInt(file, role.id);
	readStr(file, role.name);
}

void readRecord(fstream& file, STUDENT& student)
{
	readInt(file, student.id);
	readStr(file, student.firstName);
	readStr(file, student.middleName);
	readStr(file, student.surname);
	readStr(file, student.grade);
	readStr(file, student.email);
	readBool(file, student.isInTeam);
}

void readRecord(fstream& file, TEACHER& teacher)
{
	readInt(file, teacher.id);
	readStr(file, teacher.firstName);
	readStr(file, teacher.middleName);
	readStr(file, teacher.surname);
	readStr(file, teacher.email);
	readVec(file, teacher.teamIds);
}

void readRecord(fstream& file, DATE& date)
{
	readInt(file, date.day);
	readInt(file, date.month);
	readInt(file, date.year);
}

void readRecord(fstream& file, TEAM_MEMBER& member)
{
	readStr(file, member.studentEmail);
	readInt(file, member.roleId);
}

void readRecord(fstream& file, TEAM& team)
{
	readInt(file, team.id);
	readStr(file, team.name);
	readStr(file, team.desc);
	readRecord(file, team.dateOfSetUp);

	int status;
	readInt(file, status);
	team.status = static_cast<STATUS>(status);

	uint16_t memberVecSize = 0;
	TEAM_MEMBER member;
	readShortInt(file, memberVecSize);
	for (int i = 0; i < memberVecSize; i++)
	{
		readRecord(file, member);
		team.members.push_back(member);
	}
}

void readRecord(fstream& file, SCHOOL& school)
{
	readInt(file, school.id);
	readInt(file, school.maxMemberCountPerTeam);
	readStr(file, school.name);
	readStr(file, school.city);
	readStr(file, school.address);

	uint16_t itemCount=0;

	TEACHER teacher;
	readShortInt(file, itemCount);
	for (int i = 0; i < itemCount; i++)
	{
		readRecord(file, teacher);
		school.teachers.push_back(teacher);
	}

	TEAM team, emptyTeam;
	readShortInt(file, itemCount);
	for (int i = 0; i < itemCount; i++)
	{
		readRecord(file, team);
		school.teams.push_back(team);
		team = emptyTeam;
	}

	STUDENT student;
	readShortInt(file, itemCount);
	for (int i = 0; i < itemCount; i++)
	{
		readRecord(file, student);
		school.students.push_back(student);
	}

	ROLE role;
	readShortInt(file, itemCount);
	for (int i = 0; i < itemCount; i++)
	{
		readRecord(file, role);
		school.roles.push_back(role);
	}
}

COUNTERS readRecord()
{
	COUNTERS ids;
	fstream file;
	file.open("ids.dat", ios::in|ios::out|ios::binary);
	readInt(file, ids.roleId);
	readInt(file, ids.schoolId);
	readInt(file, ids.studentId);
	readInt(file, ids.teacherId);
	readInt(file, ids.teamId);
	file.close();
	return ids;
}

void readDataBase(vector<SCHOOL>& schools)
{
	fstream file;
	file.open("data.dat", ios::in | ios::out | ios::binary);
	SCHOOL school;
	static const struct SCHOOL emptySchool;
	file.seekg(0);
	uint16_t size = 0;
	readShortInt(file, size);
	for (int i = 0; i < int(size); i++)
	{
		readRecord(file, school);
		schools.push_back(school);
		school = emptySchool;
	}
	file.close();
}

void saveDataBase(vector<SCHOOL>& schools)
{
	fstream file;
	file.open("data.dat", ios::in | ios::out | ios::binary | ios::trunc);
	file.seekp(0);
	uint16_t size = (uint16_t)schools.size();
	file.write((const char*)&size, sizeof(size));
	for (size_t i = 0; i < schools.size(); i++)
	{
		save(file, schools[i]);
	}
	file.close();
}

void save(std::fstream& file, ROLE role)
{
	saveInt(file, role.id);
	saveStr(file, role.name);
}

void save(std::fstream& file, STUDENT student)
{
	saveInt(file, student.id);
	saveStr(file, student.firstName);
	saveStr(file, student.middleName);
	saveStr(file, student.surname);
	saveStr(file, student.grade);
	saveStr(file, student.email);
	saveBool(file, student.isInTeam);
}

void save(std::fstream& file, TEACHER teacher)
{
	saveInt(file, teacher.id);
	saveStr(file, teacher.firstName);
	saveStr(file, teacher.middleName);
	saveStr(file, teacher.surname);
	saveStr(file, teacher.email);
	saveVec(file, teacher.teamIds);
}

void save(std::fstream& file, DATE date)
{
	saveInt(file, date.day);
	saveInt(file, date.month);
	saveInt(file, date.year);
}

void save(std::fstream& file, TEAM_MEMBER member)
{
	saveStr(file, member.studentEmail);
	saveInt(file, member.roleId);
}

void save(std::fstream& file, TEAM team)
{
	saveInt(file, team.id);
	saveStr(file, team.name);
	saveStr(file, team.desc);
	save(file, team.dateOfSetUp);
	saveInt(file, team.status);

	uint16_t size = (uint16_t)team.members.size();
	file.write((const char*)&size, sizeof(size));

	for (uint16_t i = 0; i < size; i++)
	{
		save(file, team.members[i]);
	}
}

void save(std::fstream& file, SCHOOL school)
{
	saveInt(file, school.id);
	saveInt(file, school.maxMemberCountPerTeam);
	saveStr(file, school.name);
	saveStr(file, school.city);
	saveStr(file, school.address);

	uint16_t size= (uint16_t)school.teachers.size();
	saveShortInt(file, size);
	for (uint16_t i = 0; i < size; i++)
	{
		save(file, school.teachers[i]);
	}

	size = (uint16_t)school.teams.size();
	saveShortInt(file, size);
	for (uint16_t i = 0; i < size; i++)
	{
		save(file, school.teams[i]);
	}

	size = (uint16_t)school.students.size();
	saveShortInt(file, size);
	for (uint16_t i = 0; i < size; i++)
	{
		save(file, school.students[i]);
	}

	size = (uint16_t)school.roles.size();
	saveShortInt(file, size);
	for (uint16_t i = 0; i < size; i++)
	{
		save(file, school.roles[i]);
	}
}
void save(COUNTERS ids)
{
	fstream file;
	file.open("ids.dat", ios::in | ios::out | ios::binary|ios::trunc);
	saveInt(file, ids.roleId);
	saveInt(file, ids.schoolId);
	saveInt(file, ids.studentId);
	saveInt(file, ids.teacherId);
	saveInt(file, ids.teamId);
	file.close();
}