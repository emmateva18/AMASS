#include "ClientConnection.h"
using namespace std;

SCHOOL tableRequest(int id)
{
	asio::io_service io_service;
	asio::ip::tcp::socket socket_(io_service);
	socket_.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string(SERVER_IP), SERVER_PORT));
	SCHOOL school;
	writeInt(socket_, SYSTEM_CODE::sendSchool);
	writeInt(socket_, id);
	school.read(socket_);
	return school;
}

vector<SCHOOL> tableRequest()
{
	asio::io_service io_service;
	asio::ip::tcp::socket socket_(io_service);
	socket_.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string(SERVER_IP), SERVER_PORT));
	uint16_t size;
	writeInt(socket_, SYSTEM_CODE::readDB);
	readShortInt(socket_, size);
	SCHOOL school, empty;
	vector<SCHOOL> schools;
	for (uint16_t i = 0; i < size; i++)
	{
		school.read(socket_);
		schools.push_back(school);
		school = empty;
	}
	return schools;
}

void readRequest(SYSTEM_CODE code, ROLE& role)
{
	asio::io_service io_service;
	asio::ip::tcp::socket socket_(io_service);
	socket_.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string(SERVER_IP), SERVER_PORT));
	uint16_t size = 0;
	writeInt(socket_, code);
	readShortInt(socket_, size);
	role.read(socket_);
}
void readRequest(SYSTEM_CODE code, STUDENT& student)
{
	asio::io_service io_service;
	asio::ip::tcp::socket socket_(io_service);
	socket_.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string(SERVER_IP), SERVER_PORT));
	uint16_t size = 0;
	writeInt(socket_, code);
	readShortInt(socket_, size);
	student.read(socket_);
}
void readRequest(SYSTEM_CODE code, TEACHER& teacher)
{
	asio::io_service io_service;
	asio::ip::tcp::socket socket_(io_service);
	socket_.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string(SERVER_IP), SERVER_PORT));
	uint16_t size = 0;
	writeInt(socket_, code);
	readShortInt(socket_, size);
	teacher.read(socket_);
}
void readRequest(SYSTEM_CODE code, DATE& date)
{
	asio::io_service io_service;
	asio::ip::tcp::socket socket_(io_service);
	socket_.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string(SERVER_IP), SERVER_PORT));
	uint16_t size = 0;
	writeInt(socket_, code);
	readShortInt(socket_, size);
	date.read(socket_);
}
void readRequest(SYSTEM_CODE code, TEAM_MEMBER& member)
{
	asio::io_service io_service;
	asio::ip::tcp::socket socket_(io_service);
	socket_.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string(SERVER_IP), SERVER_PORT));
	uint16_t size = 0;
	writeInt(socket_, code);
	readShortInt(socket_, size);
	member.read(socket_);
}
void readRequest(SYSTEM_CODE code, TEAM& team)
{
	asio::io_service io_service;
	asio::ip::tcp::socket socket_(io_service);
	socket_.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string(SERVER_IP), SERVER_PORT));
	uint16_t size = 0;
	writeInt(socket_, code);
	readShortInt(socket_, size);
	team.read(socket_);
}
void readRequest(SYSTEM_CODE code, SCHOOL& school, int id)
{
	asio::io_service io_service;
	asio::ip::tcp::socket socket_(io_service);
	socket_.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string(SERVER_IP), SERVER_PORT));
	uint16_t size = 0;
	writeInt(socket_, code);
	readShortInt(socket_, size);
	school.read(socket_);
}
void readRequest(SYSTEM_CODE code, vector<SCHOOL>& school)
{
	asio::io_service io_service;
	asio::ip::tcp::socket socket_(io_service);
	socket_.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string(SERVER_IP), SERVER_PORT));
	uint16_t size = 0;
	writeInt(socket_, code);
	SCHOOL temp, empty;
	readShortInt(socket_, size);
	for (uint16_t i = 0; i < size; i++)
	{
		temp = staticRead(socket_, temp);
		school.push_back(temp);
		temp = empty;
	}
}

void readRequest(SYSTEM_CODE code, int& data)
{
	asio::io_service io_service;
	asio::ip::tcp::socket socket_(io_service);
	socket_.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string(SERVER_IP), SERVER_PORT));
	writeInt(socket_, code);
	writeInt(socket_, data);
}

void sendRequest(SYSTEM_CODE code, std::string data, int id)
{
	asio::io_service io_service;
	asio::ip::tcp::socket socket_(io_service);
	socket_.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string(SERVER_IP), SERVER_PORT));
	writeInt(socket_, code);
	writeStr(socket_, data);
	string result;
	if (id != -1)
	{
		writeInt(socket_, id);
	}
	readStr(socket_, result);
	std::cout << result;
	_getch();
}
void sendRequest(SYSTEM_CODE code, bool data, int id)
{
	asio::io_service io_service;
	asio::ip::tcp::socket socket_(io_service);
	socket_.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string(SERVER_IP), SERVER_PORT));
	writeInt(socket_, code);
	writeBool(socket_, data);
	if (id != -1)
	{
		writeInt(socket_, id);
	}
}
void sendRequest(SYSTEM_CODE code, int data, int id)
{
	asio::io_service io_service;
	asio::ip::tcp::socket socket_(io_service);
	socket_.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string(SERVER_IP), SERVER_PORT));
	writeInt(socket_, code);
	writeInt(socket_, data);
	if (id != -1)
	{
		writeInt(socket_, id);
	}
}
void sendRequest(SYSTEM_CODE code, uint16_t data)
{
	asio::io_service io_service;
	asio::ip::tcp::socket socket_(io_service);
	socket_.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string(SERVER_IP), SERVER_PORT));
	writeInt(socket_, code);
	writeShortInt(socket_, data);
}

void sendTeamRequest(SYSTEM_CODE code, int id)
{

	asio::io_service io_service;
	asio::ip::tcp::socket socket_(io_service);
	socket_.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string(SERVER_IP), SERVER_PORT));
	
	writeInt(socket_, code);
	writeInt(socket_, id);
	int MMC;
	string result;
	readInt(socket_, MMC);
	TEAM team = enterTeam(MMC);
	writeStr(socket_, team.name);
	writeStr(socket_, team.desc);
	readStr(socket_, result);
	cout << result;
	_getch();
}

//void sendUpdateTeacherRequest(int id,string )

void exitProgram()
{
	exit(0);
}

void requestCrtSch()
{
	SCHOOL school = enterSchool();
	sendRequest(SYSTEM_CODE::crtSchool, school, -1);
}

void requestReadDB()
{
	vector<SCHOOL> schools;
	readRequest(SYSTEM_CODE::readDB, schools);
	displaySchools(schools);
	cout <<  "Enter any key to continue";
	char a = _getch();
}



void getSchoolId()
{
	int id;
	requestReadDB();
	enterInt(id, "Please enter the ID of the school you wish to change: ");
	fstream f;
	f.open("schoolId.txt", ios::trunc | ios::in | ios::out);
	f << id;
	f.close();
}

int readSchoolId()
{
	fstream f;
	string temp;
	f.open("schoolId.txt", ios::in | ios::out);
	f >> temp;
	f.close();
	return stoi(temp);
}

void requestCrtTeacher()
{
	int schoolId = readSchoolId();
	TEACHER teacher = enterTeacher();
	sendRequest(SYSTEM_CODE::crtTeacher, teacher, schoolId);
}

void requestCrtTeam()
{
	int schoolId = readSchoolId();
	sendTeamRequest(SYSTEM_CODE::crtTeam, schoolId);
}

void requestCrtStudent()
{
	int schoolId = readSchoolId();
	STUDENT student = enterStudent();
	sendRequest(SYSTEM_CODE::crtStudent, student, schoolId);
}

void requestCrtRole()
{
	int schoolId = readSchoolId();
	ROLE role = enterRole();
	sendRequest(SYSTEM_CODE::crtRole, role, schoolId);
}

void requestDeleteSchool()
{
	//validate()
	int id = readSchoolId();
	sendRequest(SYSTEM_CODE::dltSchool, id, -1);
}

void requestDeleteTeam()
{
	
	int schoolId = readSchoolId(), teamid;
	SCHOOL school = tableRequest(schoolId);
	displayFullLine();
	displayTeamsInformation(school);
	enterInt(teamid, "Id of the team: ");
	sendRequest(SYSTEM_CODE::dltTeam, teamid, schoolId);
}

void requestDeleteRole()
{
	int id, schoolId = readSchoolId();
	SCHOOL school = tableRequest(schoolId);
	displayFullLine();
	displayRolesInformation(school);
	enterInt(id, "Id of the role you wish to delete: ");
	sendRequest(SYSTEM_CODE::dltRole, id, schoolId);
}

void requestDeleteStudent()
{
	int id, schoolId = readSchoolId();
	SCHOOL school = tableRequest(schoolId);
	displayFullLine();
	displayStudentsInformation(school);
	enterInt(id, "Id of the student you wish to delete: ");
	sendRequest(SYSTEM_CODE::dltStudent, id, schoolId);
}

void requestDeleteTeacher()
{
	int id, schoolId = readSchoolId();
	SCHOOL school = tableRequest(schoolId);
	displayFullLine();
	displayTeachersInformation(school);
	enterInt(id, "Id of the student you wish to delete: ");
	sendRequest(SYSTEM_CODE::dltTeacher, id, schoolId);
}

void requestInputMaxNumOfMem()
{
	int schoolId = readSchoolId();
	int num;
	vector<SCHOOL> schools = tableRequest();
	displayFullLine();
	listSchoolsDetails(schools);
	enterInt(num, "Enter the maximum number of members per team: ");
	sendRequest(SYSTEM_CODE::receiveMaxMemberCount, num,schoolId);
}

void requestUpdateSchoolName()
{
	int schoolId = readSchoolId();
	string name;
	enterString(name, "Enter the new name of the school: ");
	sendRequest(SYSTEM_CODE::updSchoolName, name, schoolId);
}

void requestUpdateSchoolAddress()
{
	int schoolId = readSchoolId();
	SCHOOL school = tableRequest(schoolId);
	displayFullLine();
	displaySchoolInformation(school);
	string name;
	enterString(name, "Enter the new address of the school: ");
	sendRequest(SYSTEM_CODE::updSchoolAddress, name, schoolId);
}

void requestUpdateSchoolCity()
{
	int schoolId = readSchoolId();
	SCHOOL school = tableRequest(schoolId);
	displayFullLine();
	displaySchoolInformation(school);
	string name;
	enterString(name, "Enter the new city of the school: ");
	sendRequest(SYSTEM_CODE::updSchoolCity, name, schoolId);
}

void requestUpdateTeacherFirstName()
{
	int schoolId = readSchoolId(), teacherId;
	SCHOOL school = tableRequest(schoolId);
	displayFullLine();
	displayTeachersInformation(school);

	asio::io_service io_service;
	asio::ip::tcp::socket socket_(io_service);
	socket_.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string(SERVER_IP), SERVER_PORT));

	writeInt(socket_, SYSTEM_CODE::updTeacherFirstName);
	string name;
	enterInt(teacherId, "Id of the teacher: ");
	enterString(name, "New first name of the teacher: ");
	writeStr(socket_, name);
	writeInt(socket_, teacherId);
	writeInt(socket_, schoolId);
	string result;
	readStr(socket_, result);
	std::cout << result;
	_getch();
}

void requestUpdateTeacherMiddleName()
{
	int schoolId = readSchoolId(), teacherId;
	SCHOOL school = tableRequest(schoolId);
	displayFullLine();
	displayTeachersInformation(school);

	asio::io_service io_service;
	asio::ip::tcp::socket socket_(io_service);
	socket_.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string(SERVER_IP), SERVER_PORT));
	writeInt(socket_, SYSTEM_CODE::updTeacherMiddleName);

	string name;
	enterInt(teacherId, "Id of the teacher: ");
	enterString(name, "New middle name of the teacher: ");
	writeStr(socket_, name);
	writeInt(socket_, teacherId);
	writeInt(socket_, schoolId);
	string result;
	readStr(socket_, result);
	std::cout << result;
	_getch();
}

void requestUpdateTeacherSurname()
{
	int schoolId = readSchoolId(), teacherId;
	SCHOOL school = tableRequest(schoolId);
	displayFullLine();
	displayTeachersInformation(school);

	asio::io_service io_service;
	asio::ip::tcp::socket socket_(io_service);
	socket_.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string(SERVER_IP), SERVER_PORT));
	writeInt(socket_, SYSTEM_CODE::updTeacherSurname);

	string name;
	enterInt(teacherId, "Id of the teacher: ");
	enterString(name, "New surname of the teacher: ");
	writeStr(socket_, name);
	writeInt(socket_, teacherId);
	writeInt(socket_, schoolId);
	string result;
	readStr(socket_, result);
	std::cout << result;
	_getch();
}

void requestUpdateTeacherEmail()
{
	int schoolId = readSchoolId(), teacherId;
	SCHOOL school = tableRequest(schoolId);
	displayFullLine();
	displayTeachersInformation(school);

	asio::io_service io_service;
	asio::ip::tcp::socket socket_(io_service);
	socket_.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string(SERVER_IP), SERVER_PORT));
	writeInt(socket_, SYSTEM_CODE::updTeacherEmail);

	string email;
	enterInt(teacherId, "Id of the teacher: ");
	enterEmail(email, "New email of the teacher: ");
	writeStr(socket_, email);
	writeInt(socket_, teacherId);
	writeInt(socket_, schoolId);
	string result;
	readStr(socket_, result);
	std::cout << result;
	_getch();
}

void requestUpdateTeacherTeams()
{
	int schoolId = readSchoolId(), teacherId;
	SCHOOL school = tableRequest(schoolId);
	string result;
	displayFullLine();
	displayTeachersInformation(school);
	cout << endl;
	displayFullLine();
	displayTeamsInformation(school);

	asio::io_service io_service;
	asio::ip::tcp::socket socket_(io_service);
	socket_.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string(SERVER_IP), SERVER_PORT));
	writeInt(socket_, SYSTEM_CODE::updTeacherTeams);

	enterInt(teacherId, "Enter the id of the teacher you wish to change: ");
	vector<int> teamIds;
	enterVectorOfIntegers(teamIds);
	writeVec(socket_, teamIds);
	writeInt(socket_, teacherId);
	writeInt(socket_, schoolId);
	readStr(socket_, result);
	cout << result;
	_getch();
}

void requestUpdateTeamName()
{
	int schoolId = readSchoolId(), teamId;
	SCHOOL school = tableRequest(schoolId);
	displayFullLine();
	displayTeamsInformation(school);

	asio::io_service io_service;
	asio::ip::tcp::socket socket_(io_service);
	socket_.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string(SERVER_IP), SERVER_PORT));
	writeInt(socket_, SYSTEM_CODE::updTeamName);

	string name;
	enterInt(teamId, "Id of the team: ");
	enterString(name, "New name of the team: ");
	writeStr(socket_, name);
	writeInt(socket_, teamId);
	writeInt(socket_, schoolId);
}

void requestUpdateTeamDescription()
{
	int schoolId = readSchoolId(), teamId;
	SCHOOL school = tableRequest(schoolId);
	displayFullLine();
	displayTeamsInformation(school);

	asio::io_service io_service;
	asio::ip::tcp::socket socket_(io_service);
	socket_.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string(SERVER_IP), SERVER_PORT));
	writeInt(socket_, SYSTEM_CODE::updTeamDescription);

	string name;
	enterInt(teamId, "Id of the team: ");
	enterString(name, "New description of the team: ");
	writeStr(socket_, name);
	writeInt(socket_, teamId);
	writeInt(socket_, schoolId);
}

void requestUpdateTeamStatus()
{
	int schoolId = readSchoolId(), teamId, status;
	SCHOOL school = tableRequest(schoolId);
	displayFullLine();
	displayTeamsInformation(school);

	asio::io_service io_service;
	asio::ip::tcp::socket socket_(io_service);
	socket_.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string(SERVER_IP), SERVER_PORT));
	writeInt(socket_, SYSTEM_CODE::updTeamStatus);

	enterInt(teamId, "Id of the team: ");
	status = enterTeamStatus();
	writeInt(socket_, status);
	writeInt(socket_, teamId);
	writeInt(socket_, schoolId);
}

void requestUpateTeamMembers()
{
	int schoolId = readSchoolId(), teamId;
	SCHOOL school = tableRequest(schoolId);
	displayFullLine();
	displayTeamsInformation(school);
	displayFullLine();
	displayStudentsInformation(school);
	displayFullLine();
	displayRolesInformation(school);

	asio::io_service io_service;
	asio::ip::tcp::socket socket_(io_service);
	socket_.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string(SERVER_IP), SERVER_PORT));
	writeInt(socket_, SYSTEM_CODE::updTeamMembers);

	int choice, roleId;
	string email, result;
	TEAM_MEMBER member, temp;
	enterInt(teamId, "Enter the team whose members you wish to alter: ");
	enterInt(choice, "Enter new amount of members: ");
	writeInt(socket_, teamId);
	writeInt(socket_, choice);
	writeInt(socket_, schoolId);
	for (int i = 0; i < choice; i++)
	{
		enterEmail(email, "Email of student " + to_string(i+1)+" :");
		enterInt(roleId, "Role of student " + to_string(i + 1) + " :");
		member.studentEmail = email;
		member.roleId = roleId;
		member.write(socket_);
		member = temp;
	}
	readStr(socket_, result);
	cout << result;
	_getch();
}

void requestUpdateStudentEmail()
{
	int schoolId = readSchoolId(), studentId;
	SCHOOL school = tableRequest(schoolId);
	displayFullLine();
	displayStudentsInformation(school);

	asio::io_service io_service;
	asio::ip::tcp::socket socket_(io_service);
	socket_.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string(SERVER_IP), SERVER_PORT));
	writeInt(socket_, SYSTEM_CODE::updStudentEmail);

	enterInt(studentId, "Id of the team: ");
	string email;
	enterEmail(email, "New email of the student");
	writeStr(socket_, email);
	writeInt(socket_, studentId);
	writeInt(socket_, schoolId);
}

void requestUpdateStudentFirstName()
{
	int schoolId = readSchoolId(), studentId;
	SCHOOL school = tableRequest(schoolId);
	displayFullLine();
	displayStudentsInformation(school);

	asio::io_service io_service;
	asio::ip::tcp::socket socket_(io_service);
	socket_.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string(SERVER_IP), SERVER_PORT));
	writeInt(socket_, SYSTEM_CODE::updStudentFirstName);

	enterInt(studentId, "Id of the student: ");
	string name;
	enterString(name, "New first name of the student: ");
	writeStr(socket_, name);
	writeInt(socket_, studentId);
	writeInt(socket_, schoolId);
}
void requestUpdateStudentMiddleName()
{
	int schoolId = readSchoolId(), studentId;
	SCHOOL school = tableRequest(schoolId);
	displayFullLine();
	displayStudentsInformation(school);

	asio::io_service io_service;
	asio::ip::tcp::socket socket_(io_service);
	socket_.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string(SERVER_IP), SERVER_PORT));
	writeInt(socket_, SYSTEM_CODE::updStudentMiddleName);

	enterInt(studentId, "Id of the student: ");
	string name;
	enterString(name, "New middle name of the student: ");
	writeStr(socket_, name);
	writeInt(socket_, studentId);
	writeInt(socket_, schoolId);
}
void requestUpdateStudentSurname()
{
	int schoolId = readSchoolId(), studentId;
	SCHOOL school = tableRequest(schoolId);
	displayFullLine();
	displayStudentsInformation(school);

	asio::io_service io_service;
	asio::ip::tcp::socket socket_(io_service);
	socket_.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string(SERVER_IP), SERVER_PORT));
	writeInt(socket_, SYSTEM_CODE::updStudentSurname);

	enterInt(studentId, "Id of the student: ");
	string name;
	enterString(name, "New surname of the student: ");
	writeStr(socket_, name);
	writeInt(socket_, studentId);
	writeInt(socket_, schoolId);
}
void requestUpdateStudentClass()
{
	int schoolId = readSchoolId(), studentId;
	SCHOOL school = tableRequest(schoolId);
	displayFullLine();
	displayStudentsInformation(school);

	asio::io_service io_service;
	asio::ip::tcp::socket socket_(io_service);
	socket_.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string(SERVER_IP), SERVER_PORT));
	writeInt(socket_, SYSTEM_CODE::updStudentClass);

	enterInt(studentId, "Id of the student: ");
	string name;
	enterGrade(name, "New class of the student: ");
	writeStr(socket_, name);
	writeInt(socket_, studentId);
	writeInt(socket_, schoolId);
}

void requestUpdateStudentIsInTeam()
{
	int schoolId = readSchoolId(), studentId;
	SCHOOL school = tableRequest(schoolId);
	displayFullLine();
	displayStudentsInformation(school);

	asio::io_service io_service;
	asio::ip::tcp::socket socket_(io_service);
	socket_.connect(asio::ip::tcp::endpoint(asio::ip::address::from_string(SERVER_IP), SERVER_PORT));
	writeInt(socket_, SYSTEM_CODE::updStudentIsInTeam);

	enterInt(studentId, "Id of the student: ");
	bool isInTeam;
	enterBool(isInTeam,"Enter wether the student is in a team (0 = false, 1 = true): ");
	writeBool(socket_, isInTeam);
	writeInt(socket_, studentId);
	writeInt(socket_, schoolId);
}