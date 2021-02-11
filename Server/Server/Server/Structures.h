#pragma once
#include <string>
#include <vector>
#include "DataFunctions.h"
#include <fstream>

enum STATUS
{
	pendingApproval,
	inUse,
	notActive,
	notArchived
};

struct ROLE
{
	int id = -1;
	std::string name = "teamless";

	void save(std::fstream& file)
	{
		saveInt(file, id);
		saveStr(file, name);
	}
};

// Name and surname, class, role which the student prefers to carry out in the team, email.
struct STUDENT 
{
	std::string firstName;
	std::string middleName;
	std::string surname;
	// As in class
	std::string grade; 
	std::string email;
	bool isInTeam = false;

	void save(std::fstream& file)
	{
		saveStr(file, firstName);
		saveStr(file, middleName);
		saveStr(file, surname);
		saveStr(file, grade);
		saveStr(file, email);
		saveBool(file, isInTeam);
	}
};

struct TEACHER
{
	std::string firstName;
	std::string middleName;
	std::string surname;
	std::string email;
	// The teams' ids will be compared instead of wasting space for TEAM structs
	std::vector<int> teamIds = {};

	void save(std::fstream& file)
	{
		saveStr(file, firstName);
		saveStr(file, middleName);
		saveStr(file, surname);
		saveStr(file, email);
		saveVec(file, teamIds);
	}
};

struct DATE
{
	int day;
	int month;
	int year;

	void save(std::fstream& file)
	{
		saveInt(file, day);
		saveInt(file, month);
		saveInt(file, year);
	}
};

struct TEAM_MEMBER
{
	std::string studentEmail;
	int roleId;

	void save(std::fstream& file)
	{
		saveStr(file, studentEmail);
		saveInt(file, roleId);
	}
};

struct TEAM
{
	int id;
	std::string name;
	std::string desc;
	DATE dateOfSetUp;
	STATUS status = STATUS::pendingApproval;
	std::vector<TEAM_MEMBER> members;

	void save(std::fstream& file)
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
};

struct SCHOOL
{
	std::string name;
	std::string city;
	std::string address;
	std::vector<TEACHER> teachers;
	std::vector<TEAM> teams;
	std::vector<STUDENT> students;

	void save(std::fstream& file)
	{
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
};