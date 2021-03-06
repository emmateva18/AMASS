#include "Logic.h"
#include "AdvancedFileOperations.h"
using namespace std;

//CRUD

void init(vector<SCHOOL>& schools)
{
	TEACHER t1 = { 0,"Petur","Ognqnov","Georgiev","POGeorgiev@abv.bg" };
	TEACHER t2 = { 1,"Gosho","Dizela","Petrov","dizela@gmail.com" };
	TEACHER t3 = { 2,"Vankata","Dunera","Vulchev","ILYDuner@abv.bg" };
	TEACHER t4 = { 3,"Eren","Grisha","Jaeger","fighter@titan.bg" };
	TEACHER t5 = { 4,"Levi","Kenny","Ackermann","scouts@titan.com" };

	STUDENT s1 = { 0,"Georgi","Georgiev","Georgiev","10A","GG@abv.bg" };
	STUDENT s2 = { 1,"Staiko","Binev","Pogriev","8A","SBP@abv.bg" };
	STUDENT s3 = { 2,"Ivan","Usrefov","Milanov","9G","IUM@abv.bg" };
	STUDENT s4 = { 3,"Stoicho","Breika","Petrov","8G","SBP@abv.bg" };
	STUDENT s5 = { 4,"Ivan","Ivanov","Ivanov","10B","III@abv.bg" };
	STUDENT s6 = { 5,"Mitko","Mitkov","Mitkov","9V","MMM@abv.bg" };

	TEAM te1 = { 0, "Chupacabras","example description lorem eipsum take up space",{0,0,0},STATUS::pendingApproval,{{"GG@abv.bg", 1},{"SBP@abv.bg", 2}} };
	TEAM te2 = { 1, "Anti-Chupacabras","example description lorem eipsum take up space",{0,0,0},STATUS::pendingApproval,{{"IUM@abv.bg", 1},{"SBP@abv.bg", 2}} };
	TEAM te3 = { 2, "We exist too","example description lorem eipsum take up space",{0,0,0},STATUS::pendingApproval,{{"III@abv.bg", 1},{"MMM@abv.bg", 2}} };

	ROLE r1 = { 0, "Scrum Master" };
	ROLE r2 = { 1, "Backend Developer" };
	ROLE r3 = { 2, "Frontend Developer" };
	ROLE r4 = { 3, "QA" };
	ROLE r5 = { 4, "Documentation" };

	vector <TEACHER> teachers{ t1, t2, t3, t4, t5 };
	vector <STUDENT> students{ s1,s2,s3,s4,s5,s6 };
	vector<TEAM> teams{ te1,te2,te3 };
	vector<ROLE> roles = { r1,r2,r3,r4,r5 };

	string name = "PGKPI";
	string city = "Burgas";
	string address = "Meden Rudnik 54";

	SCHOOL school{ 0,5, name, city, address, teachers, teams, students };

	schools.push_back(school);
}

void createStudent(SCHOOL& school, STUDENT student, fstream& file)
{
	school.students.push_back(student);
}

void createTeacher(SCHOOL& school, TEACHER teacher, fstream& file)
{
	school.teachers.push_back(teacher);
}

void createTeam(SCHOOL& school, TEAM team, fstream& file)
{
	school.teams.push_back(team);
}

void createSchool(vector<SCHOOL>& schools, SCHOOL school, fstream& file)
{
	schools.push_back(school);
	saveDataBase(file, schools);
}

void createRole(SCHOOL& school, ROLE role, fstream& file)
{
	school.roles.push_back(role);
}

void deleteStudent(SCHOOL& school, int studentId, fstream& file)
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

void deleteTeacher(SCHOOL& school, int teacherId, fstream& file)
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

void deleteRoles(SCHOOL& school, int teamId, fstream& file)
{
	
	for (size_t i = 0; i < school.roles.size(); i++)
	{
		if (school.roles[i].id == teamId)
		{
			school.roles.erase(school.roles.begin() + i);
			return;
		}
	}
}

void deleteSchool(vector<SCHOOL>& schools, int schoolId, fstream& file)
{

	for (size_t i = 0; i < schools.size(); i++)
	{
		if (schools[i].id == schoolId)
		{
			schools.erase(schools.begin() + i);
		}
	}
}

void deleteTeam(SCHOOL& school, int teamId, fstream& file)
{

	for (size_t i = 0; i < school.teams.size(); i++)
	{
		if (school.teams[i].id == teamId)
		{
			school.teams.erase(school.teams.begin() + i);
		}
	}
}