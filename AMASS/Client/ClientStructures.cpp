#include "ClientStructures.h"
/*void ROLE::write(asio::ip::tcp::socket socket)
{
	saveInt(socket, id);
	saveStr(socket, name);
}

void STUDENT::write(asio::ip::tcp::socket socket)
{
	saveInt(socket, id);
	saveStr(socket, firstName);
	saveStr(socket, middleName);
	saveStr(socket, surname);
	saveStr(socket, grade);
	saveStr(socket, email);
	saveBool(socket, isInTeam);
}

void TEACHER::write(asio::ip::tcp::socket socket)
{
	saveInt(socket, id);
	saveStr(socket, firstName);
	saveStr(socket, middleName);
	saveStr(socket, surname);
	saveStr(socket, email);
	saveVec(socket, teamIds);
}

void DATE::write(asio::ip::tcp::socket socket)
{
	saveInt(socket, day);
	saveInt(socket, month);
	saveInt(socket, year);
}

void TEAM_MEMBER::write(asio::ip::tcp::socket socket)
{
	saveStr(socket, studentEmail);
	saveInt(socket, roleId);
}

void TEAM::write(asio::ip::tcp::socket socket)
{
	saveInt(socket, id);
	saveStr(socket, name);
	saveStr(socket, desc);
	dateOfSetUp.save(socket);
	saveInt(socket, status);

	uint16_t size = (uint16_t)members.size();
	socket.write((const char*)&size, sizeof(size));

	for (uint16_t i = 0; i < size; i++)
	{
		members[i].save(socket);
	}
}

void SCHOOL::write(asio::ip::tcp::socket socket)
{
	saveInt(socket, id);
	saveStr(socket, name);
	saveStr(socket, city);
	saveStr(socket, address);

	uint16_t sizeTachers = (uint16_t)teachers.size();
	uint16_t sizeTeams = (uint16_t)teams.size();
	uint16_t sizeStudents = (uint16_t)students.size();

	socket.write((const char*)&sizeTachers, sizeof(sizeTachers));
	for (uint16_t i = 0; i < sizeTachers; i++)
	{
		teachers[i].save(socket);
	}

	socket.write((const char*)&sizeTeams, sizeof(sizeTeams));
	for (uint16_t i = 0; i < sizeTeams; i++)
	{
		teams[i].save(socket);
	}

	socket.write((const char*)&sizeStudents, sizeof(sizeStudents));
	for (uint16_t i = 0; i < sizeStudents; i++)
	{
		students[i].save(socket);
	}
}*/