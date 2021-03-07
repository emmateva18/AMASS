#include "ClientConnection.h"
using namespace std;
asio::ip::tcp::socket connectToServer()
{
	asio::io_service io_service;
	asio::ip::tcp::socket socket_(io_service);
	socket_.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string("127.0.0.1"), 1234));
	return socket_;
}

void readRequest(SYSTEM_CODE code, ROLE& role)
{
	asio::io_service io_service;
	asio::ip::tcp::socket socket_(io_service);
	socket_.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string("127.0.0.1"), 1234));
	uint16_t size = 0;
	writeInt(socket_, code);
	readShortInt(socket_, size);
	role.read(socket_);
}
void readRequest(SYSTEM_CODE code, STUDENT& student)
{
	asio::io_service io_service;
	asio::ip::tcp::socket socket_(io_service);
	socket_.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string("127.0.0.1"), 1234));
	uint16_t size = 0;
	writeInt(socket_, code);
	readShortInt(socket_, size);
	student.read(socket_);
}
void readRequest(SYSTEM_CODE code, TEACHER& teacher)
{
	asio::io_service io_service;
	asio::ip::tcp::socket socket_(io_service);
	socket_.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string("127.0.0.1"), 1234));
	uint16_t size = 0;
	writeInt(socket_, code);
	readShortInt(socket_, size);
	teacher.read(socket_);
}
void readRequest(SYSTEM_CODE code, DATE& date)
{
	asio::io_service io_service;
	asio::ip::tcp::socket socket_(io_service);
	socket_.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string("127.0.0.1"), 1234));
	uint16_t size = 0;
	writeInt(socket_, code);
	readShortInt(socket_, size);
	date.read(socket_);
}
void readRequest(SYSTEM_CODE code, TEAM_MEMBER& member)
{
	asio::io_service io_service;
	asio::ip::tcp::socket socket_(io_service);
	socket_.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string("127.0.0.1"), 1234));
	uint16_t size = 0;
	writeInt(socket_, code);
	readShortInt(socket_, size);
	member.read(socket_);
}
void readRequest(SYSTEM_CODE code, TEAM& team)
{
	asio::io_service io_service;
	asio::ip::tcp::socket socket_(io_service);
	socket_.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string("127.0.0.1"), 1234));
	uint16_t size = 0;
	writeInt(socket_, code);
	readShortInt(socket_, size);
	team.read(socket_);
}
void readRequest(SYSTEM_CODE code, SCHOOL& school)
{
	asio::io_service io_service;
	asio::ip::tcp::socket socket_(io_service);
	socket_.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string("127.0.0.1"), 1234));
	uint16_t size = 0;
	writeInt(socket_, code);
	readShortInt(socket_, size);
	school.read(socket_);
}
void readRequest(SYSTEM_CODE code, vector<SCHOOL>& school)
{
	asio::io_service io_service;
	asio::ip::tcp::socket socket_(io_service);
	socket_.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string("127.0.0.1"), 1234));
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

void sendRequest(SYSTEM_CODE code, std::string data, vector<SCHOOL> schools)
{
	asio::ip::tcp::socket socket = connectToServer();
	writeInt(socket, code);
	writeStr(socket, data);
}
void sendRequest(SYSTEM_CODE code, bool data)
{
	asio::ip::tcp::socket socket = connectToServer();
	writeInt(socket, code);
	writeBool(socket, data);
}
void sendRequest(SYSTEM_CODE code, int data)
{
	asio::ip::tcp::socket socket = connectToServer();
	writeInt(socket, code);
	writeInt(socket, data);
}
void sendRequest(SYSTEM_CODE code, uint16_t data)
{
	asio::ip::tcp::socket socket = connectToServer();
	writeInt(socket, code);
	writeShortInt(socket, data);
}

/*void processCrtSch()
{
	SCHOOL school = enterSchool();
	sendRequest(SYSTEM_CODE::crtSchool, school);
}*/

void requestCrtSch()
{
	SCHOOL school = enterSchool();
	sendRequest(SYSTEM_CODE::crtSchool, school);
}

void requestReadDB()
{
	vector<SCHOOL> schools;
	readRequest(SYSTEM_CODE::readDB,schools);
	for(size_t i=0;i<schools.size();i++)
		displaySchool(schools[i]);
}