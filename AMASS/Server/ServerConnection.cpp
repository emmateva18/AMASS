#include "ServerConnection.h"

using namespace std;

string getCurrentHour()
{
	DATE date;
	tm t;
	time_t now = time(0);
	localtime_s(&t, &now);
	string temp;
	if (t.tm_hour < 10)
		temp += "0";
	temp = to_string(t.tm_hour);
	temp += ":";
	if (t.tm_min < 10)
		temp += "0";
	temp += to_string(t.tm_min);
	temp += ":";
	if (t.tm_sec < 10)
		temp += "0";
	temp += to_string(t.tm_sec);
	return temp;
}

string codeToString(SYSTEM_CODE code)
{
	switch (code)
	{
	case ok: return "ok";
		break;
	case sendRole: return "sendRole";
		break;
	case sendStudent: return "sendStudent";
		break;
	case sendTeacher: return "sendTeacher";
		break;
	case sendDate: return "sendDate";
		break;
	case sendTeamMember: return "sendTeamMember";
		break;
	case sendTeam: return "sendTeam";
		break;
	case sendSchool: return "sendSchool";
		break;
	case sendString: return "sendString";
		break;
	case sendInt: return "sendInt";
		break;
	case sendBool: return "sendBool";
		break;
	case sendShortInt: return "sendShortInt";
		break;
	case receiveRole: return "receiveRole";
		break;
	case receiveStudent: return "receiveStudent";
		break;
	case receiveTeacher: return "receiveTeacher";
		break;
	case receiveDate: return "receiveDate";
		break;
	case receiveTeamMember: return "receiveTeamMember";
		break;
	case receiveTeam: return "receiveTeam";
		break;
	case receiveSchool: return "receiveSchool";
		break;
	case receiveString: return "receiveString";
		break;
	case receiveInt: return "receiveInt";
		break;
	case receiveBool: return "receiveBool";
		break;
	case receiveShortInt: return "receiveShortInt";
		break;
	case errorConnection: return "errorConnection";
		break;
	case crtRole: return "createRole";
		break;
	case crtStudent: return "createStudent";
		break;
	case crtTeacher: return "createTeacher";
		break;
	case crtDate: return "createDate";
		break;
	case crtTeamMember: return "createTeamMember";
		break;
	case crtTeam: return "createTeam";
		break;
	case crtSchool: return "createSchool";
		break;
	case readRole: return "readRole";
		break;
	case readStudent: return "readStudent";
		break;
	case readTeacher: return "readTeacher";
		break;
	case readDate: return "readDate";
		break;
	case readTeamMember: return "readTeamMember";
		break;
	case readTeam: return "readTeam";
		break;
	case readSchool: return "readSchool";
		break;
	case readDB: return "Extract all info from DB";
		break;
	case updRole: return "updateRole";
		break;
	case updStudent: return "updateStudent";
		break;
	case updTeacher: return "updateTeacher";
		break;
	case updDate: return "updateDate";
		break;
	case updTeamMember: return "updateTeamMember";
		break;
	case updTeam: return "updateTeam";
		break;
	case updSchool: return "updateSchool";
		break;
	case dltRole: return "deleteRole";
		break;
	case dltStudent: return "deleteStudent";
		break;
	case dltTeacher: return "deleteTeacher";
		break;
	case dltDate: return "deleteDate";
		break;
	case dltTeamMember: return "deleteTeamMember";
		break;
	case dltTeam: return "deleteTeam";
		break;
	case dltSchool: return "deleteSchool";
		break;
	}
}

void logRecord(asio::ip::tcp::socket& socket, SYSTEM_CODE code)
{
	fstream file;
	file.open("logs.txt", ios::app);
	DATE date = getCurrentDate();
	string log = "<";
	log += to_string(date.day);
	log += '.';
	log += to_string(date.month);
	log += '.';
	log += to_string(date.year);
	log += " ";
	log += getCurrentHour();
	log += "> Log[i] CODE[";
	log += to_string(code);
	log += "] OP[";
	log += codeToString(code);
	log += "] IP: ";
	log += socket.remote_endpoint().address().to_string();
	cout << log << endl;
	file << log << endl;
	file.close();
}

void processRequest(asio::ip::tcp::socket& socket, vector<SCHOOL>& schools)
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
		*/
		case crtTeacher:
		{
			TEACHER teacher;
			int schoolId;
			teacher.read(socket);
			readInt(socket, schoolId);
			createTeacher(schools[schoolId], teacher);
			saveDataBase(schools);
			break;
		}
		/*
		case crtDate:
			break;
		case crtTeamMember:
			break;
		case crtTeam:
			break;*/
	case crtSchool:
	{
		SCHOOL school;
		school.read(socket);
		createSchool(schools, school);
		break;
	}
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
		break;*/
	case readSchool:
	{
		int id;
		readInt(socket, id);
		SCHOOL school;
		findSchoolById(schools, school, id);
		school.write(socket);
		break;
	}

	case readDB:
	{
		uint16_t size = (uint16_t)schools.size();
		writeShortInt(socket, size);
		for (size_t i = 0; i < schools.size(); i++)
		{
			schools[i].write(socket);
		}
		break;
	}
	/*
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
	*/
	case dltSchool:
		int id;
		readInt(socket, id);
		deleteSchool(schools, id);
		break;
		/*
		default:
			break;
		}*/
	}
	logRecord(socket, code);
}

void startServer(vector<SCHOOL> schools)
{
	asio::io_service io_service;
	asio::error_code ec;
	asio::ip::tcp::endpoint ep(asio::ip::tcp::v4(), SERVER_PORT);
	asio::ip::tcp::acceptor acceptor_(io_service, ep.protocol());
	asio::ip::tcp::socket socket(io_service);
	acceptor_.bind(ep);

	cout << "Server has been started! Waiting for client requests..." << endl;

	while (1)
	{
		acceptor_.listen(100);
		acceptor_.accept(socket);
		processRequest(socket, schools);
		socket.close();
	}
}