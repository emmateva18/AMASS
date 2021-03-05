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
	asio::write(socket, asio::buffer((const char*)&size, sizeof(size)));
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

void ROLE::write(asio::ip::tcp::socket& socket)
{
	writeInt(socket, id);
	writeStr(socket, name);
}

void STUDENT::write(asio::ip::tcp::socket& socket)
{
	writeInt(socket, id);
	writeStr(socket, firstName);
	writeStr(socket, middleName);
	writeStr(socket, surname);
	writeStr(socket, grade);
	writeStr(socket, email);
	writeBool(socket, isInTeam);
}

void TEACHER::write(asio::ip::tcp::socket& socket)
{
	writeInt(socket, id);
	writeStr(socket, firstName);
	writeStr(socket, middleName);
	writeStr(socket, surname);
	writeStr(socket, email);
	writeVec(socket, teamIds);
}

void DATE::write(asio::ip::tcp::socket& socket)
{
	writeInt(socket, day);
	writeInt(socket, month);
	writeInt(socket, year);
}

void TEAM_MEMBER::write(asio::ip::tcp::socket& socket)
{
	writeStr(socket, studentEmail);
	writeInt(socket, roleId);
}

void TEAM::write(asio::ip::tcp::socket& socket)
{
	writeInt(socket, id);
	writeStr(socket, name);
	writeStr(socket, desc);
	dateOfSetUp.write(socket);
	writeInt(socket, status);

	uint16_t size = (uint16_t)members.size();
	writeShortInt(socket, size);

	for (uint16_t i = 0; i < size; i++)
	{
		members[i].write(socket);
	}
}

void SCHOOL::write(asio::ip::tcp::socket& socket)
{
	writeInt(socket, id);
	writeStr(socket, name);
	writeStr(socket, city);
	writeStr(socket, address);

	uint16_t size = (uint16_t)teachers.size();
	writeShortInt(socket, size);
	for (uint16_t i = 0; i < size; i++)
	{
		teachers[i].write(socket);
	}

	size = (uint16_t)teams.size();
	writeShortInt(socket, size);
	for (uint16_t i = 0; i < size; i++)
	{
		teams[i].write(socket);
	}

	size = (uint16_t)students.size();
	writeShortInt(socket, size);
	for (uint16_t i = 0; i < size; i++)
	{
		students[i].write(socket);
	}
}

void ROLE::read(asio::ip::tcp::socket& socket)
{
	readInt(socket, id);
	readStr(socket, name);
}

void STUDENT::read(asio::ip::tcp::socket& socket)
{
	readInt(socket, id);
	readStr(socket, firstName);
	readStr(socket, middleName);
	readStr(socket, surname);
	readStr(socket, grade);
	readStr(socket, email);
	readBool(socket, isInTeam);
}

void TEACHER::read(asio::ip::tcp::socket& socket)
{
	readInt(socket, id);
	readStr(socket, firstName);
	readStr(socket, middleName);
	readStr(socket, surname);
	readStr(socket, email);
	readVec(socket, teamIds);
}

void DATE::read(asio::ip::tcp::socket& socket)
{
	readInt(socket, day);
	readInt(socket, month);
	readInt(socket, year);
}

void TEAM_MEMBER::read(asio::ip::tcp::socket& socket)
{
	readStr(socket, studentEmail);
	readInt(socket, roleId);
}

void TEAM::read(asio::ip::tcp::socket& socket)
{
	readInt(socket, id);
	readStr(socket, name);
	readStr(socket, desc);
	dateOfSetUp.read(socket);
	int tempStatus;
	readInt(socket, tempStatus);
	status = static_cast<STATUS>(tempStatus);

	uint16_t size = (uint16_t)members.size();
	readShortInt(socket, size);

	for (uint16_t i = 0; i < size; i++)
	{
		members[i].read(socket);
	}
}

void SCHOOL::read(asio::ip::tcp::socket& socket)
{
	readInt(socket, id);
	readInt(socket, maxMemberCountPerTeam);
	readStr(socket, name);
	readStr(socket, city);
	readStr(socket, address);

	uint16_t size = (uint16_t)teachers.size();
	readShortInt(socket, size);
	for (uint16_t i = 0; i < size; i++)
	{
		teachers[i].read(socket);
	}

	size = (uint16_t)teams.size();
	readShortInt(socket, size);
	for (uint16_t i = 0; i < size; i++)
	{
		teams[i].read(socket);
	}

	size = (uint16_t)students.size();
	readShortInt(socket, size);
	for (uint16_t i = 0; i < size; i++)
	{
		students[i].read(socket);
	}

	size = (uint16_t)roles.size();
	readShortInt(socket, size);
	for (uint16_t i = 0; i < size; i++)
	{
		roles[i].read(socket);
	}
}