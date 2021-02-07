#pragma once
#include <string>
#include <vector>
enum Status
{
	inUse,
	notActive,
	notArchived
};
struct ROLE
{
	int id;
	std::string name;
};
struct STUDENT //name and surname, class, role which the student prefers to carry out in the team, email.
{
	std::string name;
	std::string surname;
	std::string grade; // As in class
	std::string email;
	Status status;
	ROLE role;
};
struct TEACHER
{
	std::string name;
	std::string surname;
	std::string email;
	std::vector<TEAM> teams;
};
struct TEAM
{
	std::string name;
	std::string desc;
	std::string dateOfSetUp;
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