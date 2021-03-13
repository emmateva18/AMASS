#include "ClientConnection.h"
using namespace std;

void readRequest(SYSTEM_CODE code, ROLE& role)
{
	asio::io_service io_service;
	asio::ip::tcp::socket socket_(io_service);
	socket_.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string(SERVER_IP), SERVER_PORT));
	uint16_t size = 0;
	writeInt(socket_, code);
	readShortInt(socket_, size);
	role.read(socket_);
}
void readRequest(SYSTEM_CODE code, STUDENT& student)
{
	asio::io_service io_service;
	asio::ip::tcp::socket socket_(io_service);
	socket_.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string(SERVER_IP), SERVER_PORT));
	uint16_t size = 0;
	writeInt(socket_, code);
	readShortInt(socket_, size);
	student.read(socket_);
}
void readRequest(SYSTEM_CODE code, TEACHER& teacher)
{
	asio::io_service io_service;
	asio::ip::tcp::socket socket_(io_service);
	socket_.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string(SERVER_IP), SERVER_PORT));
	uint16_t size = 0;
	writeInt(socket_, code);
	readShortInt(socket_, size);
	teacher.read(socket_);
}
void readRequest(SYSTEM_CODE code, DATE& date)
{
	asio::io_service io_service;
	asio::ip::tcp::socket socket_(io_service);
	socket_.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string(SERVER_IP), SERVER_PORT));
	uint16_t size = 0;
	writeInt(socket_, code);
	readShortInt(socket_, size);
	date.read(socket_);
}
void readRequest(SYSTEM_CODE code, TEAM_MEMBER& member)
{
	asio::io_service io_service;
	asio::ip::tcp::socket socket_(io_service);
	socket_.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string(SERVER_IP), SERVER_PORT));
	uint16_t size = 0;
	writeInt(socket_, code);
	readShortInt(socket_, size);
	member.read(socket_);
}
void readRequest(SYSTEM_CODE code, TEAM& team)
{
	asio::io_service io_service;
	asio::ip::tcp::socket socket_(io_service);
	socket_.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string(SERVER_IP), SERVER_PORT));
	uint16_t size = 0;
	writeInt(socket_, code);
	readShortInt(socket_, size);
	team.read(socket_);
}
void readRequest(SYSTEM_CODE code, SCHOOL& school, int id)
{
	asio::io_service io_service;
	asio::ip::tcp::socket socket_(io_service);
	socket_.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string(SERVER_IP), SERVER_PORT));
	uint16_t size = 0;
	writeInt(socket_, code);
	readShortInt(socket_, size);
	school.read(socket_);
}
void readRequest(SYSTEM_CODE code, vector<SCHOOL>& school)
{
	asio::io_service io_service;
	asio::ip::tcp::socket socket_(io_service);
	socket_.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string(SERVER_IP), SERVER_PORT));
	uint16_t size = 0;
	writeInt(socket_, code);
	SCHOOL temp, empty;
	readShortInt(socket_, size);
	for (uint16_t i = 0; i < size; i++)
	{
		temp = staticRead(socket_, temp);
		school.push_back(temp);
		temp = empty;
	}
}

void readRequest(SYSTEM_CODE code, int& data)
{
	asio::io_service io_service;
	asio::ip::tcp::socket socket_(io_service);
	socket_.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string(SERVER_IP), SERVER_PORT));
	writeInt(socket_, code);
	writeInt(socket_, data);
}

void sendRequest(SYSTEM_CODE code, std::string data, int id)
{
	asio::io_service io_service;
	asio::ip::tcp::socket socket_(io_service);
	socket_.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string(SERVER_IP), SERVER_PORT));
	writeInt(socket_, code);
	writeStr(socket_, data);
	if (id != -1)
	{
		writeInt(socket_, id);
	}
}
void sendRequest(SYSTEM_CODE code, bool data, int id)
{
	asio::io_service io_service;
	asio::ip::tcp::socket socket_(io_service);
	socket_.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string(SERVER_IP), SERVER_PORT));
	writeInt(socket_, code);
	writeBool(socket_, data);
	if (id != -1)
	{
		writeInt(socket_, id);
	}
}
void sendRequest(SYSTEM_CODE code, int data, int id)
{
	asio::io_service io_service;
	asio::ip::tcp::socket socket_(io_service);
	socket_.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string(SERVER_IP), SERVER_PORT));
	writeInt(socket_, code);
	writeInt(socket_, data);
	if (id != -1)
	{
		writeInt(socket_, id);
	}
}
void sendRequest(SYSTEM_CODE code, uint16_t data)
{
	asio::io_service io_service;
	asio::ip::tcp::socket socket_(io_service);
	socket_.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string(SERVER_IP), SERVER_PORT));
	writeInt(socket_, code);
	writeShortInt(socket_, data);
}

void readIntBuffer(int& data)
{
	asio::io_service io_service;
	asio::ip::tcp::socket socket_(io_service);
	socket_.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string(SERVER_IP), SERVER_PORT));
	readInt(socket_, data);
}

void sendTeamRequest(SYSTEM_CODE code, int id)
{
	asio::io_service io_service;
	asio::ip::tcp::socket socket_(io_service);
	socket_.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string(SERVER_IP), SERVER_PORT));
	writeInt(socket_, code);
	writeInt(socket_, id);
	int MMC;
	readInt(socket_, MMC);
	TEAM team = enterTeam(MMC);
	team.write(socket_);
}

void exitProgram()
{
	exit(0);
}

void requestCrtSch()
{
	SCHOOL school = enterSchool();
	sendRequest(SYSTEM_CODE::crtSchool, school, -1);
}

void requestReadDB()
{
	vector<SCHOOL> schools;
	readRequest(SYSTEM_CODE::readDB, schools);
	displaySchools(schools);
}



void getSchoolId()
{
	int id;
	requestReadDB();
	enterInt(id, "Please enter the ID of the school you wish to change");
	fstream f;
	f.open("schoolId.txt", ios::trunc | ios::in | ios::out);
	f << id;
	f.close();
}

int readSchoolId()
{
	fstream f;
	string temp;
	f.open("schoolId.txt", ios::in | ios::out);
	f >> temp;
	f.close();
	return stoi(temp);
}

void requestCrtTeacher()
{
	int schoolId = readSchoolId();
	TEACHER teacher = enterTeacher();
	sendRequest(SYSTEM_CODE::crtTeacher, teacher, schoolId);
}

void requestCrtTeam()
{
	int schoolId = readSchoolId();
	sendTeamRequest(SYSTEM_CODE::crtTeam, schoolId);
}

void requestCrtStudent()
{
	int schoolId = readSchoolId();
	STUDENT student = enterStudent();
	sendRequest(SYSTEM_CODE::crtStudent, student, schoolId);
}

void requestCrtRole()
{
	int schoolId = readSchoolId();
	ROLE role = enterRole();
	sendRequest(SYSTEM_CODE::crtRole, role, schoolId);
}

void requestDeleteSchool()
{
	//validate()
	int id;
	cin >> id;
	sendRequest(SYSTEM_CODE::dltSchool, id, -1);
}

void requestDeleteTeam()
{
	requestReadDB();
	int id, teamId;
	cin >> id;
	sendRequest(SYSTEM_CODE::readSchool, id, -1);
}

void requestDeleteRole()
{
	int id, schoolId = readSchoolId();
	enterInt(id, "Id of the role you wish to delete: ");
	sendRequest(SYSTEM_CODE::dltRole, id, schoolId);
}

void requestDeleteStudent()
{
	int id, schoolId = readSchoolId();
	enterInt(id, "Id of the student you wish to delete: ");
	sendRequest(SYSTEM_CODE::dltStudent, id, schoolId);
}

void requestInputMaxNumOfMem()
{
	int schoolId = readSchoolId();
	int num;
	enterInt(num, "Enter the maximum number of members per team: ");
	sendRequest(SYSTEM_CODE::receiveMaxMemberCount, num,schoolId);
}

void requestUpdateSchoolName()
{
	int schoolId = readSchoolId();
	string name;
	enterString(name, "Enter the new name of the school: ");
	sendRequest(SYSTEM_CODE::updSchoolName, name, schoolId);
}

void requestUpdateSchoolAddress()
{
	int schoolId = readSchoolId();
	string name;
	enterString(name, "Enter the new address of the school: ");
	sendRequest(SYSTEM_CODE::updSchoolAddress, name, schoolId);
}

void requestUpdateSchoolCity()
{
	int schoolId = readSchoolId();
	string name;
	enterString(name, "Enter the new city of the school: ");
	sendRequest(SYSTEM_CODE::updSchoolCity, name, schoolId);
}

