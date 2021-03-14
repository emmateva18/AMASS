#pragma once
//#include "../CommunicationLibrary/CommunicationLibrary.h"
#include "Presentation.h"
asio::ip::tcp::socket connectToServer();

template <typename T>
void sendRequest(SYSTEM_CODE code, T data, int schoolId)
{
	asio::io_service io_service;
	asio::ip::tcp::socket socket(io_service);
	socket.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string(SERVER_IP), SERVER_PORT));
	writeInt(socket, code);
	std::string result;
	data.write(socket);
	if (schoolId != -1)
	{
		writeInt(socket, schoolId);
	}
	readStr(socket, result);
	std::cout << result;
	_getch();
}
void tableRequest(asio::ip::tcp::socket& socket, SYSTEM_CODE code, SCHOOL& school, int id);


void readRequest(SYSTEM_CODE code, ROLE& role);
void readRequest(SYSTEM_CODE code, STUDENT& student);
void readRequest(SYSTEM_CODE code, TEACHER& teacher);
void readRequest(SYSTEM_CODE code, DATE& date);
void readRequest(SYSTEM_CODE code, TEAM_MEMBER& member);
void readRequest(SYSTEM_CODE code, TEAM& team);
void readRequest(SYSTEM_CODE code, SCHOOL& school, int id);
void readRequest(SYSTEM_CODE code, std::vector<SCHOOL>& schools);

void sendRequest(SYSTEM_CODE code, std::string data);
void sendRequest(SYSTEM_CODE code, bool data);
void sendRequest(SYSTEM_CODE code, int data, int id);
void sendRequest(SYSTEM_CODE code, uint16_t data);

void sendTeamRequest(SYSTEM_CODE code, int id);

void exitProgram();
void requestCrtSch();
void requestReadDB();
void getSchoolId();
int readSchoolId();
void requestCrtTeacher();
void requestCrtTeam();
void requestCrtStudent();
void requestCrtRole();
void requestDeleteSchool();
void requestDeleteTeam();
void requestDeleteRole();
void requestDeleteStudent();
void requestDeleteTeacher();
void requestInputMaxNumOfMem();
void requestUpdateSchoolName();
void requestUpdateSchoolAddress();
void requestUpdateSchoolCity();
void requestUpdateTeacherFirstName();
void requestUpdateTeacherMiddleName();
void requestUpdateTeacherSurname();
void requestUpdateTeacherEmail();
void requestUpdateTeacherTeams();
void requestUpdateTeamName();
void requestUpdateTeamDescription();
void requestUpdateTeamStatus();
void requestUpdateTeamMembers();
void requestUpdateStudentEmail();
void requestUpdateStudentFirstName();
void requestUpdateStudentMiddleName();
void requestUpdateStudentSurname();
void requestUpdateStudentClass();
void requestUpdateStudentIsInTeam();
void requestUpdateRoleName();

void requestDisplayTeachersWithNoTeams();
void requestDisplayStudentsWithNoTeams();
void requestDisplayTeamsStatusPA();
void requestDisplayTeamsStatusIU();
void requestDisplayTeamsStatusA();
void requestDisplayTeamsStatusNA();