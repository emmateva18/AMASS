#pragma once
#include "Libraries.h"
#include "BasicFileOperations.h"

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
	void save(std::fstream& file);
};

// Name and surname, class, role which the student prefers to carry out in the team, email.
struct STUDENT
{
	int id;
	std::string firstName;
	std::string middleName;
	std::string surname;
	// As in class
	std::string grade;
	std::string email;
	bool isInTeam = false;
	void save(std::fstream& file);
};

struct TEACHER
{
	int id;
	std::string firstName;
	std::string middleName;
	std::string surname;
	std::string email;
	// The teams' ids will be compared instead of wasting space for TEAM structs
	std::vector<int> teamIds = {};
	void save(std::fstream& file);
};

struct DATE
{
	int day;
	int month;
	int year;
	void save(std::fstream& file);
};

struct TEAM_MEMBER
{
	std::string studentEmail;
	int roleId;
	void save(std::fstream& file);
};

struct TEAM
{
	int id;
	std::string name;
	std::string desc;
	DATE dateOfSetUp;
	STATUS status = STATUS::pendingApproval;
	std::vector<TEAM_MEMBER> members;
	void save(std::fstream& file);
};

struct SCHOOL
{
	int id;
	std::string name;
	std::string city;
	std::string address;
	std::vector<TEACHER> teachers;
	int maxPlayerCountPerTeam;
	std::vector<TEAM> teams;
	std::vector<STUDENT> students;
	std::vector<ROLE> roles;
	void save(std::fstream& file);
};