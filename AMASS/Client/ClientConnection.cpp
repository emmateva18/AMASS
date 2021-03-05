#include "ClientConnection.h"
using namespace std;
void Connect()
{
	asio::io_service io_service;
	asio::ip::tcp::socket socket(io_service);
	socket.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string("127.0.0.1"), 1234));
	ROLE role = { 0,"role" };
	writeRequest(socket, SYSTEM_CODE::sendRole, role);
}