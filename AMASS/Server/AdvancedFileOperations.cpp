#include "AdvancedFileOperations.h"
using namespace std;

void read(fstream& file, STUDENT& student)
{
	readStr(file, student.firstName);
	readStr(file, student.middleName);
	readStr(file, student.surname);
	readStr(file, student.grade);
	readStr(file, student.email);
	readBool(file, student.isInTeam);
}

void read(fstream& file, TEACHER& teacher)
{
	readStr(file, teacher.firstName);
	readStr(file, teacher.middleName);
	readStr(file, teacher.surname);
	readStr(file, teacher.email);
	readVec(file, teacher.teamIds);
}

void read(fstream& file, DATE& date)
{
	readInt(file, date.day);
	readInt(file, date.month);
	readInt(file, date.year);
}

void read(fstream& file, TEAM_MEMBER& member)
{
	readStr(file, member.studentEmail);
	readInt(file, member.roleId);
}

void read(fstream& file, TEAM& team)
{
	readInt(file, team.id);
	readStr(file, team.name);
	readStr(file, team.desc);
	read(file, team.dateOfSetUp);

	int status;
	readInt(file, status);
	team.status = static_cast<STATUS>(status);

	int memberVecSize = 0;

	readInt(file, memberVecSize);
	for (int i = 0; i < memberVecSize; i++)
	{
		read(file, team.members[i]);
	}
}

void read(fstream& file, SCHOOL school)
{
	readStr(file, school.name);
	readStr(file, school.city);
	readStr(file, school.address);

	int teacherVecSize = 0;
	readInt(file, teacherVecSize);
	for (int i = 0; i < teacherVecSize; i++)
	{
		read(file, school.teachers[i]);
	}

	int teamsVecSize = 0;
	readInt(file, teamsVecSize);
	for (int i = 0; i < teamsVecSize; i++)
	{
		read(file, school.teams[i]);
	}

	int studentsVecSize = 0;
	readInt(file, studentsVecSize);
	for (int i = 0; i < studentsVecSize; i++)
	{
		read(file, school.students[i]);
	}
}

void readDataBase(fstream& file, vector<SCHOOL>& schools)
{
	file.seekg(0);
	int size = 0;
	readInt(file, size);
	for (int i = 0; i < size; i++)
	{
		read(file, schools[i]);
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