#include "ServerStructures.h"
void ROLE::save(std::fstream& file)
{
	saveInt(file, id);
	saveStr(file, name);
}

void STUDENT::save(std::fstream& file)
{
	saveInt(file, id);
	saveStr(file, firstName);
	saveStr(file, middleName);
	saveStr(file, surname);
	saveStr(file, grade);
	saveStr(file, email);
	saveBool(file, isInTeam);
}

void TEACHER::save(std::fstream& file)
{
	saveInt(file, id);
	saveStr(file, firstName);
	saveStr(file, middleName);
	saveStr(file, surname);
	saveStr(file, email);
	saveVec(file, teamIds);
}

void DATE::save(std::fstream& file)
{
	saveInt(file, day);
	saveInt(file, month);
	saveInt(file, year);
}

void TEAM_MEMBER::save(std::fstream& file)
{
	saveStr(file, studentEmail);
	saveInt(file, roleId);
}

void TEAM::save(std::fstream& file)
{
	saveInt(file, id);
	saveStr(file, name);
	saveStr(file, desc);
	dateOfSetUp.save(file);
	saveInt(file, status);

	uint16_t size = (uint16_t)members.size();
	file.write((const char*)&size, sizeof(size));

	for (uint16_t i = 0; i < size; i++)
	{
		members[i].save(file);
	}
}

void SCHOOL::save(std::fstream& file)
{
	saveInt(file, id);
	saveStr(file, name);
	saveStr(file, city);
	saveStr(file, address);

	uint16_t sizeTachers = (uint16_t)teachers.size();
	uint16_t sizeTeams = (uint16_t)teams.size();
	uint16_t sizeStudents = (uint16_t)students.size();

	file.write((const char*)&sizeTachers, sizeof(sizeTachers));
	for (uint16_t i = 0; i < sizeTachers; i++)
	{
		teachers[i].save(file);
	}

	file.write((const char*)&sizeTeams, sizeof(sizeTeams));
	for (uint16_t i = 0; i < sizeTeams; i++)
	{
		teams[i].save(file);
	}

	file.write((const char*)&sizeStudents, sizeof(sizeStudents));
	for (uint16_t i = 0; i < sizeStudents; i++)
	{
		students[i].save(file);
	}
}