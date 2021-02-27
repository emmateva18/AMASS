#include "Logic.h"

using namespace std;

//CRUD

void init(vector<SCHOOL>& schools)
{
	TEACHER t1 = { "Petur","Ognqnov","Georgiev","POGeorgiev@abv.bg" };
	TEACHER t2 = { "Gosho","Dizela","Petrov","dizela@gmail.com" };
	TEACHER t3 = { "Vankata","Dunera","Vulchev","ILYDuner@abv.bg" };
	TEACHER t4 = { "Eren","Grisha","Jaeger","fighter@titan.bg" };
	TEACHER t5 = { "Levi","Kenny","Ackermann","scouts@titan.com" };

	STUDENT s1 = { "Georgi","Georgiev","Georgiev","10A","GG@abv.bg" };
	STUDENT s2 = { "Staiko","Binev","Pogriev","8A","SBP@abv.bg" };
	STUDENT s3 = { "Ivan","Usrefov","Milanov","9G","IUM@abv.bg" };
	STUDENT s4 = { "Stoicho","Breika","Petrov","8G","SBP@abv.bg" };
	STUDENT s5 = { "Ivan","Ivanov","Ivanov","10B","III@abv.bg" };
	STUDENT s6 = { "Mitko","Mitkov","Mitkov","9V","MMM@abv.bg" };

	TEAM te1 = { 0, "Chupacabras","example description lorem eipsum take up space",{0,0,0},STATUS::pendingApproval,{{"GG@abv.bg", 1},{"SBP@abv.bg", 2}} };
	TEAM te2 = { 1, "Anti-Chupacabras","example description lorem eipsum take up space",{0,0,0},STATUS::pendingApproval,{{"IUM@abv.bg", 1},{"SBP@abv.bg", 2}} };
	TEAM te3 = { 2, "We exist too","example description lorem eipsum take up space",{0,0,0},STATUS::pendingApproval,{{"III@abv.bg", 1},{"MMM@abv.bg", 2}} };

	vector <TEACHER> teachers{ t1, t2, t3, t4, t5 };
	vector <STUDENT> students{ s1,s2,s3,s4,s5,s6 };
	vector<TEAM> teams{ te1,te2,te3 };

	string name = "PGKPI";
	string city = "Burgas";
	string address = "Meden Rudnik 54";

	SCHOOL school{ name,city,address,teachers,teams,students };

	schools.push_back(school);
}

void createSchool(vector<SCHOOL>& schools, SCHOOL school)
{
	schools.push_back(school);
	//saveData(schools);
}

string statusToString(STATUS status)
{
	switch (status)
	{
		// may change the strings later
	case pendingApproval:
		return "Pending Approval";
	case inUse:
		return "In Use";
	case notActive:
		return "Not Active";
	case notArchived:
		return "Not Archived";
	default:
		return "";
	}
}

void displayTeacher(TEACHER teacher, int id)
{
	cout << "Teacher " << id + 1 << ":" << endl;
	cout << "First Name: " << teacher.firstName << endl;
	cout << "Middle  Name: " << teacher.middleName << endl;
	cout << "Surname: " << teacher.surname << endl;
	cout << "E-mail: " << teacher.email << endl;
	cout << "List of team ids he participates: " << endl;

	for (size_t i = 0; i < teacher.teamIds.size(); i++)
	{
		cout << teacher.teamIds[i] << endl;
		// display team's name by its id
	}
}

void displayTeam(TEAM team)
{
	cout << "Team's id: " << team.id << endl;
	cout << "Name: " << team.name << endl;
	// make description on several lines, instead of 1
	cout << "Description: " << team.desc << endl;
	cout << "Date of set up:" << endl;
	// may change the format later
	cout << team.dateOfSetUp.day << "/"
		<< team.dateOfSetUp.month << "/"
		<< team.dateOfSetUp.year <<
		" (dd/mm/yyyy)" << endl;
	cout << "Status: " << statusToString(team.status) << endl;

	cout << "List of team members:" << endl;

	for (size_t j = 0; j < team.members.size(); j++)
	{
		cout << "Student " << j + 1 << ":" << endl;
		cout << "Email: " << team.members[j].studentEmail << endl;
		// display student's role by id
	}
}

void displaySchool(SCHOOL school, int id)
{
	cout << "School " << id << " details:" << endl;
	cout << "Name: " << school.name << endl;
	cout << "City: " << school.city << endl;
	cout << "Adress: " << school.address << endl;

	cout << "List of the teachers: " << endl;

	for (size_t i = 0; i < school.teachers.size(); i++)
	{
		displayTeacher(school.teachers[i], id);
	}

	cout << "List of the teams:" << endl;

	for (size_t i = 0; i < school.teams.size(); i++)
	{
		displayTeam(school.teams[i]);
	}
}