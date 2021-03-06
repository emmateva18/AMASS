#include "ServerConnection.h"
using namespace std;

void processRequest(asio::ip::tcp::socket& socket,vector<SCHOOL> schools)
{
	SYSTEM_CODE code;
	int temp;
	readInt(socket, temp);
	code = static_cast<SYSTEM_CODE>(temp);
	switch (code)
	{
		/*
		case sendRole:
			break;
		case sendStudent:
			break;
		case sendTeacher:
			break;
		case sendDate:
			break;
		case sendTeamMember:
			break;
		case sendTeam:
			break;
		case sendSchool:
			break;
		case sendString:
			break;
		case sendInt:
			break;
		case sendBool:
			break;
		case sendShortInt:
			break;
		case receiveRole:
			break;
		case receiveStudent:
			break;
		case receiveTeacher:
			break;
		case receiveDate:
			break;
		case receiveTeamMember:
			break;
		case receiveTeam:
			break;
		case receiveSchool:
			break;
		case receiveString:
			break;
		case receiveInt:
			break;
		case receiveBool:
			break;
		case receiveShortInt:
			break;
		case errorConnection:
			break;
		case crtRole: createRole()
			break;
		case crtStudent:
			break;

		case crtTeacher:
			break;
		case crtDate:
			break;
		case crtTeamMember:
			break;
		case crtTeam:
			break;*/
	case crtSchool:
		SCHOOL school;
		school.read(socket);
		createSchool(schools, school);
		cout << school.name;
		break;
		/*
		case readRole:
			break;
		case readStudent:
			break;
		case readTeacher:
			break;
		case readDate:
			break;
		case readTeamMember:
			break;
		case readTeam:
			break;
		case readSchool:
			break;
		case updRole:
			break;
		case updStudent:
			break;
		case updTeacher:
			break;
		case updDate:
			break;
		case updTeamMember:
			break;
		case updTeam:
			break;
		case updSchool:
			break;
		case dltRole:
			break;
		case dltStudent:
			break;
		case dltTeacher:
			break;
		case dltDate:
			break;
		case dltTeamMember:
			break;
		case dltTeam:
			break;
		case dltSchool:
			break;
		default:
			break;
		}*/
	}
}

void startServer(vector<SCHOOL> schools)
{
	asio::io_service io_service;
	asio::error_code ec;
	asio::ip::tcp::endpoint ep (asio::ip::tcp::v4(), 1234);
	asio::ip::tcp::acceptor acceptor_(io_service, ep.protocol());
	asio::ip::tcp::socket socket(io_service);
	acceptor_.bind(ep);

	while (1)
	{
		acceptor_.listen(100);
		acceptor_.accept(socket);
		processRequest(socket,schools);
		socket.close();
	}
}