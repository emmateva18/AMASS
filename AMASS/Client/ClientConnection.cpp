#include "ClientConnection.h"
using namespace std;
void Connect()
{
	asio::io_context context;
	asio::ip::tcp::endpoint ep(asio::ip::make_address("127.0.0.1"), 1234);
	asio::ip::tcp::socket socket(context);
	socket.connect(ep);
	string request = "request test";
	socket.write_some(asio::buffer(request.data(), request.size()));
}