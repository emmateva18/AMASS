#pragma once
#include <string>
#include <vector>
enum Status
{
	inUse,
	notActive,
	notArchived,
	pendingApproval
};
struct ROLE
{
	int id=0;
	std::string name="teamless";
};
struct STUDENT //name and surname, class, role which the student prefers to carry out in the team, email.
{
	std::string firstName;
	std::string middleName;
	std::string surname;
	std::string grade; // As in class
	std::string email;
	ROLE role;
	bool isInTeam = false;
};
struct TEACHER
{
	std::string firstName;
	std::string middleName;
	std::string surname;
	std::string email;
	//String will be compared to team names instead of wasting space for TEAM structs
	std::vector<string> teams = {};
};
struct DATE
{
	int day;
	int month;
	int year;
};
struct TEAM
{
	std::string name;
	std::string desc;
	DATE dateOfSetUp;
	Status status;
	std::vector<STUDENT> students;
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