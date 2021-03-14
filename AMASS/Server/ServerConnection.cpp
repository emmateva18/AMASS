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
	case sendSchool: return "sendSchool";
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
	case sendDBSize: return "sendDBSize";
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
	case receiveMaxMemberCount: return "receiveMaxMemberCount";
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
	case updSchoolName: return "updateSchoolName";
		break;
	case updSchoolAddress: return "updateSchoolAddress";
		break;
	case updSchoolCity: return "updateSchoolCity";
		break;
	case updTeacherFirstName: return "updateTeacherFirstName";
		break;
	case updTeacherMiddleName: return "updateTeacherMiddleName";
		break;
	case updTeacherSurname: return "updateTeacherSurname";
		break;
	case updTeacherEmail: return "updateTeacherEmail";
		break;
	case updTeamName: return "updateTeamName";
		break;
	case updTeamDescription: return "updateTeamDescription";
		break;
	case updTeamStatus: return "updateTeamStatus";
		break;
	case updStudentEmail: return "updateStudentEmail";
		break;
	case updStudentFirstName: return "updateStudentFirstName";
		break;
	case updStudentMiddleName: return "updateStudentMiddleName";
		break;
	case updStudentSurname: return "updateStudentSurname";
		break;
	case updStudentClass: return "updateStudentClass";
		break;
	case updStudentIsInTeam: return "updateStudentIsInTeam";
		break;
	case updTeacherTeams: return "updateTeacherTeams";
		break;
	case updTeamMembers: return "updateTeamMembers";
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
	string errorMsg="";
	int temp;
	readInt(socket, temp);
	code = static_cast<SYSTEM_CODE>(temp);
	switch (code)
	{
	case sendSchool:
	{
		int schoolId;
		readInt(socket, schoolId);
		int pos = findSchoolById(schools,schoolId);
		schools[pos].write(socket);
		break;
	}
	case sendDBSize:
	{
		writeShortInt(socket, uint16_t(schools.size()));
		break;
	}
		case receiveMaxMemberCount:
		{
			int schoolId=0;
			int num;
			readInt(socket, num);
			readInt(socket, schoolId);
			int pos = findSchoolById(schools, schoolId);
			
			schools[pos].maxMemberCountPerTeam = num;
			saveDataBase(schools);
			break;
		}
		/*
		case errorConnection:
			break;*/
		case crtRole:
		{
			int schoolId;
			ROLE role;
			role.read(socket);
			readInt(socket, schoolId);
			int pos = findSchoolById(schools, schoolId);
			if (!isUniqueRole(schools[pos], role.name))
			{
				errorMsg = "There is already a role with that name!\n";
				writeStr(socket, errorMsg);
				break;
			}
			if (schools[pos].maxMemberCountPerTeam <= schools[pos].roles.size())
			{
				errorMsg = "You can't have more roles than available team members!\n";
				writeStr(socket, errorMsg);
				break;
			}
			createRole(schools[pos], role);
			saveDataBase(schools);
			writeStr(socket, "Operation Successful!\n");
			break;
		}
		case crtStudent:
		{
			int schoolId=0;
			STUDENT student;
			student.read(socket);
			readInt(socket, schoolId);
			int pos = findSchoolById(schools, schoolId);
			if (!isUniqueEmail(schools[pos], student.email))
			{
				errorMsg = "A person with that email already exists!\n";
				writeStr(socket, errorMsg);
				break;
			}
			createStudent(schools[pos],student);
			saveDataBase(schools);
			writeStr(socket, "Operation Successful!\n");
			break;
		}
		case crtTeacher:
		{
			TEACHER teacher;
			int schoolId;
			teacher.read(socket);
			readInt(socket, schoolId);
			int pos = findSchoolById(schools, schoolId);
			if (!isUniqueEmail(schools[pos], teacher.email))
			{
				errorMsg = "A person with that email already exists!\n";
				writeStr(socket, errorMsg);
				break;
			}
			createTeacher(schools[pos], teacher);
			saveDataBase(schools);
			writeStr(socket, "Operation Successful!\n");
			break;
		}
		case crtTeam:
		{
			TEAM team;
			string name, desc;
			int schoolId;
			readInt(socket, schoolId);
			int pos = findSchoolById(schools,schoolId);
			writeInt(socket, schools[pos].maxMemberCountPerTeam);
			readStr(socket, name);
			readStr(socket, desc);
			if (!isUniqueTeamName(schools[pos], name))
			{
				errorMsg = "There is already a team with that name!\n";
				writeStr(socket, errorMsg);
				break;
			}
			team.name = name;
			team.desc = desc;
			createTeam(schools[pos], team);
			saveDataBase(schools);
			writeStr(socket, "Operation successful!\n");
			break;
		}
	case crtSchool:
	{
		SCHOOL school;
		school.read(socket);
		if (!isUniqueSchoolName(schools, school.name))
		{
			errorMsg = "There is already a school with that name!\n";
			writeStr(socket, errorMsg);
			break;
		}
		if (school.maxMemberCountPerTeam < 1)
		{
			errorMsg = "Maximum number of team members should be greater than 0!\n";
			writeStr(socket, errorMsg);
			break;
		}
		createSchool(schools, school);
		saveDataBase(schools);
		writeStr(socket, "Operation successful!\n");
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
		int pos = findSchoolById(schools,id);
		schools[pos].write(socket);
		saveDataBase(schools);
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
	case updSchoolName:
	{
		int schoolId = 0;
		string name;
		readStr(socket, name);
		readInt(socket, schoolId);
		int pos = findSchoolById(schools, schoolId);
		if (!isUniqueSchoolName(schools, name))
		{
			errorMsg = "A school with that name already exists!\n";
			writeStr(socket, errorMsg);
			break;
		}
		schools[pos].name = name;
		saveDataBase(schools);
		writeStr(socket, "Operaition successful!\n");
		break;
	}
	case updSchoolAddress:
	{
		int schoolId = 0;
		string address;
		readStr(socket, address);
		readInt(socket, schoolId);
		int pos = findSchoolById(schools, schoolId);
		schools[pos].address = address;
		saveDataBase(schools);
		break;
	}
	case updSchoolCity:
	{
		int schoolId = 0;
		string city;
		readStr(socket, city);
		readInt(socket, schoolId);
		int pos = findSchoolById(schools, schoolId);
		schools[pos].city = city;
		saveDataBase(schools);
		break;
	}
	case updTeacherFirstName:
	{
		int schoolId = 0,teacherId;
		string name;
		readStr(socket, name);
		readInt(socket, teacherId);
		readInt(socket, schoolId);
		int pos = findSchoolById(schools, schoolId);
		int pos2 = findTeacherById(schools[pos], teacherId);
		if (pos2 == -1)
		{
			errorMsg = "No teacher with id ";
			errorMsg += to_string(teacherId);
			errorMsg += " found!\n";
			writeStr(socket, errorMsg);
			break;
		}
		updateTeacherFirstName(schools[pos].teachers[pos2], name);
		saveDataBase(schools);
		writeStr(socket, "Operaition successful!\n");
		break;
	}
	case updTeacherMiddleName:
	{
		int schoolId = 0, teacherId;
		string name;
		readStr(socket, name);
		readInt(socket, teacherId);
		readInt(socket, schoolId);
		int pos = findSchoolById(schools, schoolId);
		int pos2 = findTeacherById(schools[pos], teacherId);
		if (pos2 == -1)
		{
			errorMsg = "No teacher with id ";
			errorMsg += to_string(teacherId);
			errorMsg += " found!\n";
			writeStr(socket, errorMsg);
			break;
		}
		updateTeacherMiddleName(schools[pos].teachers[pos2], name);
		saveDataBase(schools);
		writeStr(socket, "Operaition successful!\n");
		break;
	}
	case updTeacherSurname:
	{
		int schoolId = 0, teacherId;
		string name;
		readStr(socket, name);
		readInt(socket, teacherId);
		readInt(socket, schoolId);
		int pos = findSchoolById(schools, schoolId);
		int pos2 = findTeacherById(schools[pos], teacherId);
		if (pos2 == -1)
		{
			errorMsg = "No teacher with id ";
			errorMsg += to_string(teacherId);
			errorMsg += " found!\n";
			writeStr(socket, errorMsg);
			break;
		}
		updateTeacherSurname(schools[pos].teachers[pos2], name);
		saveDataBase(schools);
		writeStr(socket, "Operaition successful!\n");
		break;
	}
	case updTeacherEmail:
	{
		int schoolId = 0, teacherId;
		string email;
		readStr(socket, email);
		readInt(socket, teacherId);
		readInt(socket, schoolId);
		int pos = findSchoolById(schools, schoolId);
		int pos2 = findTeacherById(schools[pos], teacherId);
		if (pos2 == -1)
		{
			errorMsg = "No teacher with id ";
			errorMsg += to_string(teacherId);
			errorMsg += " found!\n";
			writeStr(socket, errorMsg);
			break;
		}
		if (!isUniqueEmail(schools[pos], email))
		{
			errorMsg = "A person with that email already exists!\n";
			writeStr(socket, errorMsg);
			break;
		}
		updateTeacherEmail(schools[pos].teachers[pos2], email);
		saveDataBase(schools);
		writeStr(socket, "Operaition successful!\n");
		break;
	}
	case updTeamName:
	{
		int schoolId = 0, teamId;
		string name;
		readStr(socket, name);
		readInt(socket, teamId);
		readInt(socket, schoolId);
		int pos = findSchoolById(schools, schoolId);
		int pos2 = findTeamById(schools[pos], teamId);
		if (pos2 == -1)
		{
			errorMsg = "No team with id ";
			errorMsg += to_string(teamId);
			errorMsg += " found!\n";
			writeStr(socket, errorMsg);
			break;
		}
		if (!isUniqueTeamName(schools[pos], name))
		{
			errorMsg = "There is already a team with that name!\n";
			writeStr(socket, errorMsg);
			break;
		}
		updateTeamName(schools[pos].teams[pos2], name);
		saveDataBase(schools);
		writeStr(socket, "Operaition successful!\n");
		break;
	}
	case updTeamDescription:
	{
		int schoolId = 0, teamId;
		string desc;
		readStr(socket, desc);
		readInt(socket, teamId);
		readInt(socket, schoolId);
		int pos = findSchoolById(schools, schoolId);
		int pos2 = findTeamById(schools[pos], teamId);
		if (pos2 == -1)
		{
			errorMsg = "No team with id ";
			errorMsg += to_string(teamId);
			errorMsg += " found!\n";
			writeStr(socket, errorMsg);
			break;
		}
		updateTeamDesc(schools[pos].teams[pos2], desc);
		saveDataBase(schools);
		writeStr(socket, "Operaition successful!\n");
		break;
	}
	case updTeamStatus:
	{

		int schoolId = 0, teamId, status;
		readInt(socket, status);
		readInt(socket, teamId);
		readInt(socket, schoolId);
		int pos = findSchoolById(schools, schoolId);
		int pos2 = findTeamById(schools[pos], teamId);
		if (pos2 == -1)
		{
			errorMsg = "No team with id ";
			errorMsg += to_string(teamId);
			errorMsg += " found!\n";
			writeStr(socket, errorMsg);
			break;
		}
		if (status < 0 and status>3)
		{
			errorMsg = "You have to pick a value between 0 - 3!\n";
			writeStr(socket, errorMsg);
			break;
		}
		updateTeamStatus(schools[pos].teams[pos2], static_cast<STATUS>(status));
		if (status == STATUS::archived)
		{
			archiveTeam(schools[pos], teamId);
		}
		saveDataBase(schools);
		writeStr(socket, "Operaition successful!\n");
		break;
	}
	case updRole:
	{
		int schoolId = 0, roleId;
		string name;
		readInt(socket, roleId);
		readStr(socket, name);
		readInt(socket, schoolId);
		int pos = findSchoolById(schools, schoolId);
		int pos2 = findRoleById(schools[pos], roleId);
		if (pos2 == -1)
		{
			errorMsg = "No role with id ";
			errorMsg +=to_string(roleId);
			errorMsg += " found!\n";
			writeStr(socket, errorMsg);
			break;
		}
		if (!isUniqueRole(schools[pos], name))
		{
			errorMsg = "There is already a role with that name!\n";
			writeStr(socket, errorMsg);
			break;
		}
		schools[pos].roles[pos2].name = name;
		saveDataBase(schools);
		writeStr(socket, "Operation successful!\n");
		break;
	}
	case updStudentEmail:
	{
		int schoolId = 0, studentId;
		string email;
		readStr(socket, email);
		readInt(socket, studentId);
		readInt(socket, schoolId);
		int pos = findSchoolById(schools, schoolId);
		int pos2 = findStudentById(schools[pos], studentId);
		if (pos2 == -1)
		{
			errorMsg = "No student with id ";
			errorMsg += to_string(studentId);
			errorMsg += " found!\n";
			writeStr(socket, errorMsg);
			break;
		}
		if (!isUniqueEmail(schools[pos], email))
		{
			errorMsg = "A person with that email already exists!\n";
			writeStr(socket, errorMsg);
			break;
		}
		updateStudentEmail(schools[pos].students[pos2], email);
		saveDataBase(schools);
		writeStr(socket, "Operation succesful!\n");
		break;
	}
	case updStudentFirstName:
	{
		int schoolId = 0, studentId;
		string name;
		readStr(socket, name);
		readInt(socket, studentId);
		readInt(socket, schoolId);
		int pos = findSchoolById(schools, schoolId);
		int pos2 = findStudentById(schools[pos], studentId);
		if (pos2 == -1)
		{
			errorMsg = "No student with id ";
			errorMsg += to_string(studentId);
			errorMsg += " found!\n";
			writeStr(socket, errorMsg);
			break;
		}
		updateStudentFirstName(schools[pos].students[pos2], name);
		saveDataBase(schools);
		writeStr(socket, "Operation succesful!\n");
		break;
	}
	case updStudentMiddleName:
	{
		int schoolId = 0, studentId;
		string name;
		readStr(socket, name);
		readInt(socket, studentId);
		readInt(socket, schoolId);
		int pos = findSchoolById(schools, schoolId);
		int pos2 = findStudentById(schools[pos], studentId);
		if (pos2 == -1)
		{
			errorMsg = "No student with id ";
			errorMsg += to_string(studentId);
			errorMsg += " found!\n";
			writeStr(socket, errorMsg);
			break;
		}
		updateStudentMiddleName(schools[pos].students[pos2], name);
		saveDataBase(schools);
		writeStr(socket, "Operation succesful!\n");
		break;
	}
	case updStudentSurname:
	{
		int schoolId = 0, studentId;
		string name;
		readStr(socket, name);
		readInt(socket, studentId);
		readInt(socket, schoolId);
		int pos = findSchoolById(schools, schoolId);
		int pos2 = findStudentById(schools[pos], studentId);
		if (pos2 == -1)
		{
			errorMsg = "No student with id ";
			errorMsg += to_string(studentId);
			errorMsg += " found!\n";
			writeStr(socket, errorMsg);
			break;
		}
		updateStudentSurname(schools[pos].students[pos2], name);
		saveDataBase(schools);
		writeStr(socket, "Operation succesful!\n");
		break;
	}
	case updStudentClass:
	{
		int schoolId = 0, studentId;
		string name;
		readStr(socket, name);
		readInt(socket, studentId);
		readInt(socket, schoolId);
		int pos = findSchoolById(schools, schoolId);
		int pos2 = findStudentById(schools[pos], studentId);
		if (pos2 == -1)
		{
			errorMsg = "No student with id ";
			errorMsg += to_string(studentId);
			errorMsg += " found!\n";
			writeStr(socket, errorMsg);
			break;
		}
		updateStudentGrade(schools[pos].students[pos2], name);
		saveDataBase(schools);
		writeStr(socket, "Operation succesful!\n");
		break;
	}
	case updStudentIsInTeam:
	{
		int schoolId = 0, studentId;
		bool isInTeam;
		readBool(socket, isInTeam);
		readInt(socket, studentId);
		readInt(socket, schoolId);
		int pos = findSchoolById(schools, schoolId);
		int pos2 = findStudentById(schools[pos], studentId);
		if (pos2 == -1)
		{
			errorMsg = "No student with id ";
			errorMsg += to_string(studentId);
			errorMsg += " found!\n";
			writeStr(socket, errorMsg);
			break;
		}
		setStudentIsInTeam(schools[pos].students[pos2], isInTeam);
		saveDataBase(schools);
		writeStr(socket, "Operation succesful!\n");
		break;
	}
	case updTeacherTeams:
	{
		int schoolId,teacherId;
		vector<int> teamIds,empty;
		readVec(socket, teamIds);
		readInt(socket, teacherId);
		readInt(socket, schoolId);
		int pos = findSchoolById(schools, schoolId);
		int pos2 = findTeacherById(schools[pos], teacherId);
		if (pos2 == -1)
		{
			errorMsg = "No teacher with id ";
			errorMsg += to_string(teacherId);
			errorMsg += " found!\n";
			writeStr(socket, errorMsg);
			break;
		}
		for (int i = 0; i <teamIds.size(); i++)
		{
			int pos3 = findTeamById(schools[pos], teamIds[i]);
			if (schools[pos].teams[pos3].status != STATUS::inUse)
			{
				errorMsg = "The team can't be altered unless its status is set to 'In Use'!\n";
				writeStr(socket, errorMsg);
				break;
			}
		}
		if (teamIds.size() == 0)
		{
			schools[pos].teachers[pos2].teamIds = empty;
			errorMsg = "Operation successful!\n";
			writeStr(socket, errorMsg);
			break;
		}
		if (teamIds.size()<= schools[pos].teams.size())
		{
			for (size_t i = 0; i < teamIds.size(); i++)
			{
				if (findTeamById(schools[pos], teamIds[i]) != -1)
				{
					if (findIfTeamHasTeacher(schools[pos], teamIds[i]) == -1)
					{
						schools[pos].teachers[pos2].teamIds.push_back(teamIds[i]);
					}
					else
					{
						errorMsg += "Team with id: ";
						errorMsg += to_string(teamIds[i]);
						errorMsg += " already has a teacher!";
						break;
					}
				}
				else
				{
					errorMsg = "No team with id: ";
					errorMsg += to_string(teamIds[i]);
					errorMsg += " found!";
					break;
				}
			}
		}
		else
		{
			errorMsg = "There are less than ";
			errorMsg += to_string(teamIds.size());
			errorMsg += " teams in existance at this school!";
			break;
		}
		if(errorMsg=="")
			errorMsg="Operation successful!";
		writeStr(socket, errorMsg);
		saveDataBase(schools);
		break;
	}
	case updTeamMembers:
	{
		int schoolId,size,pos3,teamId;
		vector<TEAM_MEMBER> members,empty,oldMembers;
		TEAM_MEMBER member,temp;
		readInt(socket, teamId);
		readInt(socket, size);
		readInt(socket, schoolId);
		int pos = findSchoolById(schools, schoolId);
		int pos2 = findTeamById(schools[pos], teamId);
		if (pos2 == -1)
		{
			errorMsg = "No team with id ";
			errorMsg += to_string(teamId);
			errorMsg += " found!\n";
			writeStr(socket, errorMsg);
			break;
		}
		if (!canEditTeam(schools[pos], teamId))
		{
			errorMsg = "Cannot edit this team, because its is not 'In Use'\n";
			writeStr(socket, errorMsg);
			break;
		}
		if(size==0)
		{ 
			for (int i = 0; i < oldMembers.size(); i++)
			{
				int pos3 = findStudentByEmail(schools[pos], oldMembers[i].studentEmail);
				schools[pos].students[pos3].isInTeam = false;
			}
			schools[pos].teams[pos2].members = empty;
			writeStr(socket, "Operation Successful!");
			saveDataBase(schools);
			break;
		}
		if (size<0 or size>schools[pos].maxMemberCountPerTeam)
		{
			errorMsg += "There can't be more than ";
			errorMsg += to_string(schools[pos].maxMemberCountPerTeam);
			errorMsg += " members per team!";
			writeStr(socket, errorMsg);
			break;
		}
		for (int i = 0; i < size; i++)
		{
			member.read(socket);
			members.push_back(member);
			member = temp;
		}
		oldMembers = schools[pos].teams[pos2].members;
		schools[pos].teams[pos2].members = empty;
		if (size <= schools[pos].maxMemberCountPerTeam)
		{
			if (!hasTeamRepeatedRole(members))
			{
				for (int i = 0; i < size; i++)
				{
					for(int i=0;i<oldMembers.size();i++)
					{
						pos3 = findStudentByEmail(schools[pos], oldMembers[i].studentEmail);
						schools[pos].students[pos3].isInTeam = false;
					}
					pos3 = findStudentByEmail(schools[pos], members[i].studentEmail);
					if (pos3!=-1)
					{
						if (schools[pos].students[pos3].isInTeam)
						{
							errorMsg = "Student with email ";
							errorMsg += schools[pos].students[pos3].email;
							errorMsg += " is already in a team\n";
							schools[pos].teams[pos2].members = oldMembers;
							for (int i = 0; i < oldMembers.size(); i++)
							{
								pos3 = findStudentByEmail(schools[pos], oldMembers[i].studentEmail);
								schools[pos].students[pos3].isInTeam = true;
							}
							writeStr(socket, errorMsg);
							break;
						}
					}
					else
					{
						errorMsg = "No student with email ";
						errorMsg += members[i].studentEmail;
						errorMsg += " exists!\n";
						schools[pos].teams[pos2].members = oldMembers;
						for (int i = 0; i < oldMembers.size(); i++)
						{
							pos3 = findStudentByEmail(schools[pos], oldMembers[i].studentEmail);
							schools[pos].students[pos3].isInTeam = true;
						}
						writeStr(socket, errorMsg);
						break;
					}
					if (findRoleById(schools[pos], members[i].roleId) == -1)
					{
						errorMsg = "No role with id ";
						errorMsg += to_string(members[i].roleId);
						errorMsg += " found!\n";
						schools[pos].teams[pos2].members = oldMembers;
						for (int i = 0; i < oldMembers.size(); i++)
						{
							pos3 = findStudentByEmail(schools[pos], oldMembers[i].studentEmail);
							schools[pos].students[pos3].isInTeam = true;
						}
						writeStr(socket, errorMsg);
						break;
					}
				}
			}
			else
			{
				errorMsg = "You can't have members with duplicated roles!\n";
				schools[pos].teams[pos2].members = oldMembers;
				for (int i = 0; i < oldMembers.size(); i++)
				{
					pos3 = findStudentByEmail(schools[pos], oldMembers[i].studentEmail);
					schools[pos].students[pos3].isInTeam = true;
				}
				writeStr(socket, errorMsg);
				break;
			}
		}
		else
		{
			errorMsg = "There can't be more than ";
			errorMsg += to_string(schools[pos].maxMemberCountPerTeam);
			errorMsg += " members in a team\n";
			schools[pos].teams[pos2].members = oldMembers;
			for (int i = 0; i < oldMembers.size(); i++)
			{
				pos3 = findStudentByEmail(schools[pos], oldMembers[i].studentEmail);
				schools[pos].students[pos3].isInTeam = true;
			}
			writeStr(socket, errorMsg);
			break;
		}
		if (errorMsg == "")
		{
			schools[pos].teams[pos2].members = members;
			for (int i = 0; i < size; i++)
			{
				pos3 = findStudentByEmail(schools[pos], members[i].studentEmail);
				schools[pos].students[pos3].isInTeam = true;
			}
			for (int i = 0; i < size; i++)
			{
				pos3 = findStudentByEmail(schools[pos], members[i].studentEmail);
				setStudentIsInTeamToFalseIfNotInTeam(schools[pos], schools[pos].students[pos2]);
			}
			errorMsg = "Operation successful!\n";
			saveDataBase(schools);
		}
		writeStr(socket, errorMsg);
		break;
	}
	case dltRole:
	{
		int schoolId = 0,roleId;
		readInt(socket, roleId);
		readInt(socket, schoolId);
		int pos = findSchoolById(schools, schoolId);
		int pos2 = findRoleById(schools[pos], roleId);
		if (pos2 == -1)
		{
			errorMsg = "No role with id ";
			errorMsg += to_string(roleId);
			errorMsg += " found!\n";
			writeStr(socket, errorMsg);
			break;
		}
		deleteRoles(schools[pos], roleId);
		saveDataBase(schools);
		writeStr(socket, "Operation successful!\n");
		break;
	}
	case dltStudent:
	{
		int schoolId = 0, studentId;
		readInt(socket, studentId);
		readInt(socket, schoolId);
		int pos = findSchoolById(schools, schoolId);
		int pos2 = findStudentById(schools[pos], studentId);
		if (pos2 == -1)
		{
			errorMsg = "No student with id ";
			errorMsg += to_string(studentId);
			errorMsg += " found!\n";
			writeStr(socket, errorMsg);
			break;
		}
		deleteStudent(schools[pos], studentId);
		saveDataBase(schools);
		writeStr(socket, "Operation successful!\n");
		break;
	}
	case dltTeacher:
	{
		int schoolId = 0, teacherId;
		readInt(socket, teacherId);
		readInt(socket, schoolId);
		int pos = findSchoolById(schools, schoolId);
		int pos2 = findTeacherById(schools[pos], teacherId);
		if (pos2 == -1)
		{
			errorMsg = "No teacher with id ";
			errorMsg += to_string(teacherId);
			errorMsg += " found!\n";
			writeStr(socket, errorMsg);
			break;
		}
		deleteTeacher(schools[pos], teacherId);
		saveDataBase(schools);
		writeStr(socket, "Operation successful!\n");
		break;
	}
	case dltTeamMember:
		break;
	case dltTeam:
	{
		int schoolId,teamId;
		readInt(socket, teamId);
		readInt(socket, schoolId);
		int pos = findSchoolById(schools, schoolId);
		int pos2 = findTeamById(schools[pos], teamId);
		if (pos2 == -1)
		{
			errorMsg = "No team with id ";
			errorMsg += to_string(teamId);
			errorMsg += " found!\n";
			writeStr(socket, errorMsg);
			break;
		}
		deleteTeam(schools[pos], teamId);
		saveDataBase(schools);
		writeStr(socket, "Operation successful!\n");
		break;
	}
	case dltSchool:
		int id;
		readInt(socket, id);
		deleteSchool(schools, id);
		saveDataBase(schools);
		writeStr(socket, "Operation successful!\n");
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
		try {
			acceptor_.listen(100);
			acceptor_.accept(socket);
			processRequest(socket, schools);
			socket.close();
		}
		catch (exception& e)
		{
			cout << "Internal Server error: " << e.what();
			break;
		}
	}
}