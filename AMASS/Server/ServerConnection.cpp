#include "ServerConnection.h"
using namespace std;

void processRequest()
{

}

void startServer()
{
	asio::io_service io_service;
	asio::error_code ec;
	asio::ip::tcp::endpoint ep (asio::ip::tcp::v4(), 1234);
	asio::ip::tcp::acceptor acceptor_(io_service, ep.protocol());
	asio::ip::tcp::socket sock(io_service);
	acceptor_.bind(ep);

	while (1)
	{
		acceptor_.listen(100);
		acceptor_.accept(sock);
		ROLE role = { 0,"aaa" };
		SYSTEM_CODE code;
		readRequest(sock, code, role);
		cout << role.name;
		sock.close();
	}
}