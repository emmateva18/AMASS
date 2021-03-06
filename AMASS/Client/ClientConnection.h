#pragma once
#include "../CommunicationLibrary/CommunicationLibrary.h"
#include "Presentation.h"
asio::ip::tcp::socket connectToServer();

template <typename T>
void sendRequest(SYSTEM_CODE code, T data)
{
	//asio::ip::tcp::socket socket = connectToServer();
	asio::io_service io_service;
	asio::ip::tcp::socket socket(io_service);
	socket.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string("127.0.0.1"), 1234));
	writeInt(socket, code);
	data.write(socket);
}
void sendRequest(SYSTEM_CODE code, std::string data);
void sendRequest(SYSTEM_CODE code, bool data);
void sendRequest(SYSTEM_CODE code, int data);
void sendRequest(SYSTEM_CODE code, uint16_t data);

//void processCrtSch()
void requestCrtSch();