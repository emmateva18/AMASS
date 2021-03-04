// CommunicationLibrary.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include "CommunicationLibrary.h"

using namespace std;

typedef unsigned char byte;

void saveStr(asio::ip::tcp::socket& socket, string str)
{
	uint16_t size = (uint16_t)str.size();
	byte* buffer = (byte*)str.c_str();
	//socket.write((const char*)&size, sizeof(size));
	//socket.write((const char*)buffer, (uint16_t)size);
	asio::write(socket, asio::buffer(buffer, size));
}

void saveInt(asio::ip::tcp::socket& socket, int integer)
{
	asio::write(socket, asio::buffer((const char*)&integer, sizeof(int)));
}

void saveBool(asio::ip::tcp::socket& socket, bool a)
{
	asio::write(socket, asio::buffer((const char*)&a, sizeof(bool)));
}
/*
void saveVec(asio::ip::tcp::socket& socket, vector<int> vec)
{
	uint16_t size = (uint16_t)vec.size();
	socket.write((const char*)&size, sizeof(size));
	for (size_t i = 0; i < vec.size(); i++)
	{
		saveInt(socket, vec[i]);
	}
}

void saveVec(asio::ip::tcp::socket& socket, vector<string> vec)
{
	uint16_t size = (uint16_t)vec.size();
	socket.write((const char*)&size, sizeof(size));
	for (size_t i = 0; i < vec.size(); i++)
	{
		saveStr(socket, vec[i]);
	}
}
*/
void readStr(asio::ip::tcp::socket& socket, string& str, int size)
{
	asio::streambuf buf;
	asio::read(socket, buf, asio::transfer_exactly(size));
	string test(asio::buffers_begin(buf.data()), asio::buffers_end(buf.data()));
	str = test;
}

void readInt(asio::ip::tcp::socket& socket, int& num)
{
	asio::streambuf buf;
	size_t bytesRead = asio::read(socket, buf, asio::transfer_exactly(sizeof(int)));
	
	if (bytesRead != sizeof(int)) 
	{
		throw std::length_error("Incorrect number of bytes for type int!");
	}

	//string temp(asio::buffers_begin(buf.data()), asio::buffers_end(buf.data()));
	std::istream is(&buf);
	is.read((char*)&num, sizeof(int));
	// PG was here
}

void readShortInt(asio::ip::tcp::socket& socket, uint16_t& num)
{
	asio::streambuf buf;
	asio::read(socket, buf, asio::transfer_exactly(sizeof(uint16_t)));
	string temp(asio::buffers_begin(buf.data()), asio::buffers_end(buf.data()));
	num = uint16_t(stoi(temp));
}

void readBool(asio::ip::tcp::socket& socket, bool& a)
{
	asio::streambuf buf;
	asio::read(socket, buf, asio::transfer_exactly(sizeof(bool)));
	string temp(asio::buffers_begin(buf.data()), asio::buffers_end(buf.data()));
	a = bool(stoi(temp));
}
/*
void readVec(asio::ip::tcp::socket& socket, vector<string>& vec)
{
	uint16_t size = 0;
	string temp;
	socket.read((char*)&size, sizeof(uint16_t));
	for (uint16_t i = 0; i < size; i++)
	{
		readStr(socket, temp);
		vec.push_back(temp);
	}
}

void readVec(asio::ip::tcp::socket& socket, vector<int>& vec)
{
	uint16_t size = 0;
	int temp;
	socket.read((char*)&size, sizeof(uint16_t));
	for (uint16_t i = 0; i < size; i++)
	{
		readInt(socket, temp);
		vec.push_back(temp);
	}
}*/