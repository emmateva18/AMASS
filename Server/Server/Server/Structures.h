#pragma once
#include <string>
#include <vector>

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
};

struct TEACHER
{
	std::string firstName;
	std::string middleName;
	std::string surname;
	std::string email;
	// The teams' ids will be compared instead of wasting space for TEAM structs
	std::vector<int> teamIds = {};
};

struct DATE
{
	int day;
	int month;
	int year;
};

struct TEAM_MEMBER
{
	int teamId;
	std::string studentEmail;
	int roleId;
};

struct TEAM
{
	int id;
	std::string name;
	std::string desc;
	DATE dateOfSetUp;
	STATUS status = STATUS::pendingApproval;
	std::vector<TEAM_MEMBER> members;
};

struct SCHOOL
{
	std::string name;
	std::string city;
	std::string address;
	std::vector<TEACHER> teachers;
	std::vector<TEAM> teams;
	std::vector<STUDENT> students;
};