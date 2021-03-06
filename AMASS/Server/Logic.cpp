#include "Logic.h"
#include "AdvancedFileOperations.h"
using namespace std;

//CRUD

void init(vector<SCHOOL>& schools)
{
	TEACHER t1 = { 0,"Boiko","Zdravkov","Valchev","BZValchev@abv.bg" };
	TEACHER t2 = { 1,"Deyan","Penkov","Bakalov","DPBakalov@gmail.com" };
	TEACHER t3 = { 2,"Raina","Danailova","Simova","RDSimova@abv.bg" };
	TEACHER t4 = { 3,"Apostol","Borislavov","Yankov","ABYankov@titan.bg" };
	TEACHER t5 = { 4,"Vyara","Plamenova","Borisova","VPBorisova@titan.com" };

	STUDENT s1 = { 0,"Ralitsa", "Dragomirova", "Kishisheva", "RDKishisheva@abv.bg" };
	STUDENT s2 = { 1,"Dara", "Boikova", "Svetkova", "DBSvetkova@abv.bg" };
	STUDENT s3 = { 2,"Yosif", "Emilov", "Borisov", "YEBorisov@abv.bg" };
	STUDENT s4 = { 3,"Andon", "Atanasov", "Hristov", "AAHristov@abv.bg" };
	STUDENT s5 = { 4,"Yordanka", "Ivailova", "Blagoeva", "YIBlagoeva@abv.bg" };
	STUDENT s6 = { 5,"Tsvetan", "Penkov", "Manevski", "TPManevski@abv.bg" };

	TEAM te1 = { 0, "Chupacabras","example description",{0,0,0},STATUS::pendingApproval,{{"RDKishisheva@abv.bg", 1},{"AAHristov@abv.bg", 2}} };
	TEAM te2 = { 1, "Anti-Chupacabras","example description",{0,0,0},STATUS::pendingApproval,{{"DBSvetkova@abv.bg", 1},{"YEBorisov@abv.bg", 2}} };

	ROLE r1 = { 0, "Scrum Master" };
	ROLE r2 = { 1, "Backend Developer" };
	ROLE r3 = { 2, "Frontend Developer" };
	ROLE r4 = { 3, "QA" };
	ROLE r5 = { 4, "Documentation" };

	vector <TEACHER> teachers{ t1, t2, t3, t4, t5 };
	vector <STUDENT> students{ s1,s2,s3,s4,s5,s6 };
	vector<TEAM> teams{ te1,te2 };
	vector<ROLE> roles = { r1,r2,r3,r4,r5 };

	string name = "VCSPI";
	string city = "Burgas";
	string address = "Meden Rudnik 54";

	SCHOOL school{ 0,4, name, city, address, teachers, teams, students, roles };

	schools.push_back(school);
}

DATE getCurrentDate()
{
	DATE date;
	tm t;
	time_t now = time(0);
	localtime_s(&t, &now);
	date.day = t.tm_mday;
	date.month = t.tm_mon + 1;
	date.year = t.tm_year + 1900;
	return date;
}


void assignSchoolId(SCHOOL& school)
{
	COUNTERS ids = readRecord();
	school.id = ids.schoolId++;
	save(ids);
}

void assignTeamId(TEAM& team)
{
	COUNTERS ids = readRecord();
	team.id = ids.teamId++;
	save(ids);
}

void assignRoleId(ROLE& role)
{
	COUNTERS ids = readRecord();
	role.id = ids.roleId++;
	save(ids);
}

void assignTeacherId(TEACHER& teacher)
{
	COUNTERS ids = readRecord();
	teacher.id = ids.teacherId++;
	save(ids);
}

void assignStudentId(STUDENT& student)
{
	COUNTERS ids = readRecord();
	student.id = ids.studentId++;
	save(ids);
}

int findIfTeamHasTeacher(SCHOOL school, int teamId, int teacherId)
{

	for (int i = 0; i < school.teachers.size(); i++)
	{
		for (int j = 0; j < school.teachers[i].teamIds.size(); j++)
		{
			if (school.teachers[i].teamIds[j] == teamId and school.teachers[teacherId].id != school.teachers[i].id)
			{
				return i;
			}
		}
	}

	return -1;
}

int findSchoolById(vector<SCHOOL>& schools, int id)
{
	for (size_t i = 0; i < schools.size(); i++)
	{
		if (schools[i].id == id)
		{
			return i;
		}
	}
	return -1;
}

int findTeacherById(SCHOOL school, int teacherId)
{
	for (int i = 0; i < school.teachers.size(); i++)
	{
		if (school.teachers[i].id == teacherId)
			return i;
	}
	return -1;
}

int findStudentById(SCHOOL school, int studentId)
{
	for (size_t i = 0; i < school.students.size(); i++)
	{
		if (school.students[i].id == studentId)
		{
			return i;
		}
	}
	return -1;
}

int findTeamById(SCHOOL school, int teamId)
{
	for (size_t i = 0; i < school.teams.size(); i++)
	{
		if (school.teams[i].id == teamId)
		{
			return i;
		}
	}
	return -1;
}

int findRoleById(SCHOOL school, int roleId)
{
	for (size_t i = 0; i < school.roles.size(); i++)
	{
		if (school.roles[i].id == roleId)
		{
			return i;
		}
	}
	return -1;
}

int findStudentByEmail(SCHOOL school, string email)
{
	for (size_t i = 0; i < school.students.size(); i++)
	{
		if (school.students[i].email == email)
		{
			return i;
		}
	}
	return -1;
}

void setStudentIsInTeamToFalseIfNotInTeam(SCHOOL school, STUDENT& student)
{
	for (size_t i = 0; i < school.teams.size(); i++)
	{
		for (size_t j = 0; j < school.teams[i].members.size(); j++)
		{
			if (school.teams[i].members[j].studentEmail == student.email)
			{
				student.isInTeam = true;
				return;
			}
		}
	}

	student.isInTeam = false;
}

bool isUniqueRole(SCHOOL school, string role)
{
	for (int i = 0; i < school.roles.size(); i++)
	{
		if (school.roles[i].name == role)
			return 0;
	}
	return 1;
}

bool isUniqueSchoolName(vector<SCHOOL> schools, string name)
{
	for (int i = 0; i < schools.size(); i++)
	{
		if (schools[i].name == name)
			return 0;
	}
	return 1;
}

bool isUniqueEmail(SCHOOL school, string email)
{
	for (int i = 0; i < school.students.size();i++)
	{
		if (school.students[i].email == email)
			return 0;
	}
	for (int i = 0; i < school.teachers.size();i++)
	{
		if (school.teachers[i].email == email)
			return 0;
	}
	return 1;
}

bool canEditTeam(SCHOOL school,int teamId)
{
	int pos = findTeamById(school, teamId);
	if (school.teams[pos].status == STATUS::inUse)
		return 1;
	return 0;
}

bool isUniqueTeamName(SCHOOL school, string name)
{
	for (int i = 0; i < school.teams.size(); i++)
	{
		if (school.teams[i].name == name)
			return 0;
	}
	return 1;
}

bool hasTeamRepeatedRole(vector<TEAM_MEMBER> members)
{
	for (size_t i = 0; i < members.size() - 1; i++)
	{
		for (size_t j = i + 1; j < members.size(); j++)
		{
			if (members[i].roleId == members[j].roleId)
			{
				return true;
			}
		}
	}
	return false;
}

bool hasTeamReachedMaxMembers(SCHOOL school, TEAM team)
{
	return team.members.size() >= school.maxMemberCountPerTeam ? true : false;
}

void createStudent(SCHOOL& school, STUDENT student)
{
	assignStudentId(student);
	school.students.push_back(student);
}

void createTeacher(SCHOOL& school, TEACHER teacher)
{
	assignTeacherId(teacher);
	school.teachers.push_back(teacher);
}

void createTeam(SCHOOL& school, TEAM team)
{
	assignTeamId(team);
	team.dateOfSetUp = getCurrentDate();
	school.teams.push_back(team);
}

void createSchool(vector<SCHOOL>& schools, SCHOOL school)
{
	assignSchoolId(school);
	schools.push_back(school);
	saveDataBase(schools);
}

void createRole(SCHOOL& school, ROLE role)
{
	assignRoleId(role);
	school.roles.push_back(role);
}

void createTeamIdInTeacher(TEACHER& teacher, int teamId)
{
	teacher.teamIds.push_back(teamId);
}

void deleteStudent(SCHOOL& school, int studentId)
{
	for (size_t i = 0; i < school.students.size(); i++)
	{
		if (school.students[i].id == studentId)
		{
			school.students.erase(school.students.begin() + i);
			return;
		}
	}
}

void deleteTeacher(SCHOOL& school, int teacherId)
{
	for (size_t i = 0; i < school.teachers.size(); i++)
	{
		if (school.teachers[i].id == teacherId)
		{
			school.teachers.erase(school.teachers.begin() + i);
			return;
		}
	}
}

void deleteRoles(SCHOOL& school, int roleId)
{

	for (size_t i = 0; i < school.roles.size(); i++)
	{
		if (school.roles[i].id == roleId)
		{
			school.roles.erase(school.roles.begin() + i);
			return;
		}
	}
}

void deleteSchool(vector<SCHOOL>& schools, int schoolId)
{

	for (size_t i = 0; i < schools.size(); i++)
	{
		if (schools[i].id == schoolId)
		{
			schools.erase(schools.begin() + i);
		}
	}
	saveDataBase(schools);
}

void deleteTeam(SCHOOL& school, int teamId)
{

	for (size_t i = 0; i < school.teams.size(); i++)
	{
		if (school.teams[i].id == teamId)
		{
			school.teams.erase(school.teams.begin() + i);
		}
	}
}

void deleteTeamIdInTeacher(TEACHER& teacher, int teamIdIndex)
{
	teacher.teamIds.erase(teacher.teamIds.begin() + teamIdIndex);
}

// STUDENT

void updateStudentFirstName(STUDENT& student, string newFirstName)
{
	student.firstName = newFirstName;
}

void updateStudentMiddleName(STUDENT& student, string newMiddleName)
{
	student.middleName = newMiddleName;
}

void updateStudentSurname(STUDENT& student, string newSurname)
{
	student.surname = newSurname;
}

void updateStudentGrade(STUDENT& student, string newGrade)
{
	student.grade = newGrade;
}

void updateStudentEmail(STUDENT& student, string newEmail)
{
	student.email = newEmail;
}

void setStudentIsInTeam(STUDENT& student, bool isInTeam)
{
	student.isInTeam = isInTeam;
}


// TEACHER

void updateTeacherFirstName(TEACHER& teacher, string newFirstName)
{
	teacher.firstName = newFirstName;
}

void updateTeacherMiddleName(TEACHER& teacher, string newMiddleName)
{
	teacher.middleName = newMiddleName;
}

void updateTeacherSurname(TEACHER& teacher, string newSurname)
{
	teacher.surname = newSurname;
}

void updateTeacherEmail(TEACHER& teacher, string newEmail)
{
	teacher.email = newEmail;
}

void updateTeamIdInTeacher(TEACHER& teacher, int teamIdIndex, int newId)
{
	teacher.teamIds[teamIdIndex] = newId;
}

// TEAM

void updateTeamName(TEAM& team, string newName)
{
	team.name = newName;
}

void updateTeamDesc(TEAM& team, string newDesc)
{
	team.desc = newDesc;
}

void updateTeamDayOfSetUp(TEAM& team, int newDay)
{
	team.dateOfSetUp.day = newDay;
}

void updateTeamMonthOfSetUp(TEAM& team, int newMonth)
{
	team.dateOfSetUp.month = newMonth;
}

void updateTeamYearOfSetUp(TEAM& team, int newYear)
{
	team.dateOfSetUp.year = newYear;
}

void updateTeamStatus(TEAM& team, STATUS newStatus)
{
	team.status = newStatus;
}

// SCHOOL

void updateSchoolName(SCHOOL& school, string newName)
{
	school.name = newName;
}

void updateSchoolCity(SCHOOL& school, string newCity)
{
	school.city = newCity;
}

void archiveTeam(SCHOOL& school, int teamId)
{
	int pos = findTeamById(school, teamId);
	for (int i = 0; i < school.teams[pos].members.size(); i++)
	{
		int pos2 = findStudentByEmail(school, school.teams[pos].members[i].studentEmail);
		school.students[pos2].isInTeam = false;
	}
}

void updateSchoolAdress(SCHOOL& school, string newAddress)
{
	school.address = newAddress;
}

void updateRolesAfterDeletion(SCHOOL& school,int roleId)
{
	int pos = findRoleById(school,roleId);
	for (int i = 0; i < school.teams.size(); i++)
	{
		for (int j = 0; j < school.teams[i].members.size(); j++)
		{
			if (school.teams[i].members[j].roleId == roleId)
			{
				school.teams[i].members[j].roleId = -1;
			}
		}
	}
}

void updateTeacherAfterTeamDeletion(SCHOOL& school, int teamId)
{
	for (int i = 0; i < school.teachers.size();i++)
	{
		for (int j = 0; j < school.teachers[i].teamIds.size(); j++)
		{
			if (school.teachers[i].teamIds[j] == teamId)
				school.teachers[i].teamIds[j] = -1;
		}
	}
}

void updateTeamAfterStudentDeletion(SCHOOL& school, string studentEmail)
{
	for (int i = 0; i < school.teams.size(); i++)
	{
		for (int j = 0; j < school.teams[i].members.size(); j++)
		{
			if (school.teams[i].members[j].studentEmail == studentEmail)
			{
				school.teams[i].members[j].studentEmail = "DELETED";
				school.teams[i].members[j].roleId = -1;
			}
		}
	}
}