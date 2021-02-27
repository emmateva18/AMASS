#include "Presentation.h"
#include "Libraries.h"

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