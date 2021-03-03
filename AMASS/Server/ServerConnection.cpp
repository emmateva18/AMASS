#include "ServerConnection.h"

void serverStart()
{
	asio::io_service io_service;
	asio::ip::tcp::acceptor acceptor_(io_service, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), 1234));
	asio::ip::tcp::socket socket_(io_service);
	acceptor_.accept(socket_);
}