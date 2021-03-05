#pragma once
#include "Libraries.h"
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
	void write(asio::ip::tcp::socket& socket);
	void read(asio::ip::tcp::socket& socket);
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
	void write(asio::ip::tcp::socket& socket);
	void read(asio::ip::tcp::socket& socket);
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
	void write(asio::ip::tcp::socket& socket);
	void read(asio::ip::tcp::socket& socket);
};

struct DATE
{
	int day;
	int month;
	int year;
	void write(asio::ip::tcp::socket& socket);
	void read(asio::ip::tcp::socket& socket);
};

struct TEAM_MEMBER
{
	std::string studentEmail;
	int roleId;
	void write(asio::ip::tcp::socket& socket);
	void read(asio::ip::tcp::socket& socket);
};

struct TEAM
{
	int id;
	std::string name;
	std::string desc;
	DATE dateOfSetUp;
	STATUS status = STATUS::pendingApproval;
	std::vector<TEAM_MEMBER> members;
	void write(asio::ip::tcp::socket& socket);
	void read(asio::ip::tcp::socket& socket);
};

struct SCHOOL
{
	int id;
	int maxMemberCountPerTeam;
	std::string name;
	std::string city;
	std::string address;
	std::vector<TEACHER> teachers;
	std::vector<TEAM> teams;
	std::vector<STUDENT> students;
	std::vector<ROLE> roles;
	void write(asio::ip::tcp::socket& socket);
	void read(asio::ip::tcp::socket& socket);
};

void writeShortInt(asio::ip::tcp::socket& socket, uint16_t num);
void writeStr(asio::ip::tcp::socket& socket, std::string str);
void writeInt(asio::ip::tcp::socket& socket, int integer);
void writeBool(asio::ip::tcp::socket& socket, bool a);
void writeVec(asio::ip::tcp::socket& socket, std::vector<int> vec);
void writeVec(asio::ip::tcp::socket& socket, std::vector<std::string> vec);
void readStr(asio::ip::tcp::socket& socket, std::string& str);
void readInt(asio::ip::tcp::socket& socket, int& num);
void readShortInt(asio::ip::tcp::socket& socket, uint16_t& num);
void readBool(asio::ip::tcp::socket& socket, bool& a);
void readVec(asio::ip::tcp::socket& socket, std::vector<std::string>& vec);
void readVec(asio::ip::tcp::socket& socket, std::vector<int>& vec);