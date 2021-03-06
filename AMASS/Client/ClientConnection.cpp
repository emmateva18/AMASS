#include "ClientConnection.h"
using namespace std;
asio::ip::tcp::socket connectToServer()
{
	asio::io_service io_service;
	asio::ip::tcp::socket socket_(io_service);
	socket_.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string("127.0.0.1"), 1234));
	return socket_;
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