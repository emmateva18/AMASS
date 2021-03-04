// CommunicationLibrary.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include "CommunicationLibrary.h"

using namespace std;

typedef unsigned char byte;

void writeShortInt(asio::ip::tcp::socket& socket, uint16_t num)
{
	asio::write(socket, asio::buffer((const char*)&num, sizeof(uint16_t)));
}

void writeStr(asio::ip::tcp::socket& socket, string str)
{
	uint16_t size = (uint16_t)str.size();
	byte* buffer = (byte*)str.c_str();
	writeShortInt(socket, size);
	asio::write(socket, asio::buffer(buffer, size));
}

void writeInt(asio::ip::tcp::socket& socket, int integer)
{
	asio::write(socket, asio::buffer((const char*)&integer, sizeof(int)));
}

void writeBool(asio::ip::tcp::socket& socket, bool a)
{
	asio::write(socket, asio::buffer((const char*)&a, sizeof(bool)));
}

void writeVec(asio::ip::tcp::socket& socket, vector<int> vec)
{
	uint16_t size = (uint16_t)vec.size();
	asio::write(socket,asio::buffer((const char*)&size, sizeof(size)));
	for (size_t i = 0; i < vec.size(); i++)
	{
		writeInt(socket, vec[i]);
	}
}

void writeVec(asio::ip::tcp::socket& socket, vector<string> vec)
{
	uint16_t size = (uint16_t)vec.size();
	asio::write(socket, asio::buffer((const char*)&size, sizeof(size)));
	for (size_t i = 0; i < vec.size(); i++)
	{
		writeStr(socket, vec[i]);
	}
}

void readStr(asio::ip::tcp::socket& socket, string& str)
{
	uint16_t size;
	readShortInt(socket, size);

	asio::streambuf buf;
	size_t bytesRead = asio::read(socket, buf, asio::transfer_exactly(size));

	if (bytesRead != size)
	{
		throw std::length_error("Incorrect number of bytes for type int!");
	}

	std::istream is(&buf);
	char* temp = new char[size];
	is.read(temp, size);
	str = "";
	for (uint16_t i = 0; i < size; i++)
		str += temp[i];
	delete[] temp;
}

void readInt(asio::ip::tcp::socket& socket, int& num)
{
	asio::streambuf buf;
	size_t bytesRead = asio::read(socket, buf, asio::transfer_exactly(sizeof(int)));

	if (bytesRead != sizeof(int))
	{
		throw std::length_error("Incorrect number of bytes for type int!");
	}

	std::istream is(&buf);
	is.read((char*)&num, sizeof(int));
}

void readShortInt(asio::ip::tcp::socket& socket, uint16_t& num)
{
	asio::streambuf buf;
	size_t bytesRead = asio::read(socket, buf, asio::transfer_exactly(sizeof(uint16_t)));

	if (bytesRead != sizeof(uint16_t))
	{
		throw std::length_error("Incorrect number of bytes for type short int!");
	}

	std::istream is(&buf);
	is.read((char*)&num, sizeof(uint16_t));
}

void readBool(asio::ip::tcp::socket& socket, bool& a)
{
	asio::streambuf buf;
	size_t bytesRead = asio::read(socket, buf, asio::transfer_exactly(sizeof(bool)));

	if (bytesRead != sizeof(bool))
	{
		throw std::length_error("Incorrect number of bytes for type int!");
	}

	std::istream is(&buf);
	is.read((char*)&a, sizeof(bool));
}

void readVec(asio::ip::tcp::socket& socket, vector<string>& vec)
{
	uint16_t size = 0;
	string temp;
	asio::streambuf buf;
	//socket.read((char*)&size, sizeof(uint16_t));
	readShortInt(socket, size);
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
	asio::streambuf buf;
	//socket.read((char*)&size, sizeof(uint16_t));
	readShortInt(socket, size);
	for (uint16_t i = 0; i < size; i++)
	{
		readInt(socket, temp);
		vec.push_back(temp);
	}
}