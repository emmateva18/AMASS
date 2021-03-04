#pragma once
#include "..\Server\Libraries.h"
#include <asio.hpp>
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
	//void write(asio::ip::tcp::socket socket);
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
	//void write(asio::ip::tcp::socket socket);
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
	//void write(asio::ip::tcp::socket socket);
};

struct DATE
{
	int day;
	int month;
	int year;
	//void write(asio::ip::tcp::socket socket);
};

struct TEAM_MEMBER
{
	std::string studentEmail;
	int roleId;
	//void write(asio::ip::tcp::socket socket);
};

struct TEAM
{
	int id;
	std::string name;
	std::string desc;
	DATE dateOfSetUp;
	STATUS status = STATUS::pendingApproval;
	std::vector<TEAM_MEMBER> members;
	//void write(asio::ip::tcp::socket socket);
};

struct SCHOOL
{
	int id;
	std::string name;
	std::string city;
	std::string address;
	std::vector<TEACHER> teachers;
	std::vector<TEAM> teams;
	std::vector<STUDENT> students;
	//void write(asio::ip::tcp::socket socket);
};