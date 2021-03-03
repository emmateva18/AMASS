#include "AdvancedFileOperations.h"
using namespace std;

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

	TEAM team;
	readShortInt(file, itemCount);
	for (int i = 0; i < itemCount; i++)
	{
		readRecord(file, team);
		school.teams.push_back(team);
	}

	STUDENT student;
	readShortInt(file, itemCount);
	for (int i = 0; i < itemCount; i++)
	{
		readRecord(file, student);
		school.students.push_back(student);
	}
}

void readDataBase(fstream& file, vector<SCHOOL>& schools)
{
	SCHOOL school;
	file.seekg(0);
	uint16_t size = 0;
	readShortInt(file, size);
	for (int i = 0; i < int(size); i++)
	{
		readRecord(file, school);
		schools.push_back(school);
	}
}

void saveDataBase(fstream& file, vector<SCHOOL> schools)
{
	uint16_t size = (uint16_t)schools.size();
	file.write((const char*)&size, sizeof(size));
	for (size_t i = 0; i < schools.size(); i++)
	{
		schools[i].save(file);
	}
}