#include "Presentation.h"
#include "Libraries.h"
#include <functional>

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

STUDENT enterStudent()
{
	STUDENT student;

	cout << "Enter student's first name: ";
	cin >> student.firstName;
	cout << "Enter student's middle name: ";
	cin >> student.middleName;
	cout << "Enter student's surname: ";
	cin >> student.surname;
	cout << "Enter student's grade: ";
	cin >> student.grade;
	cout << "Enter student's email: ";
	cin >> student.email;

	return student;
}

TEACHER enterTeacher()
{
	TEACHER teacher;

	cout << "First name: ";
	cin >> teacher.firstName;
	cout << "Middle name: ";
	cin >> teacher.middleName;
	cout << "Surname: ";
	cin >> teacher.surname;
	cout << "Email: ";
	cin >> teacher.email;

	return teacher;
}

TEAM enterTeam(int maxPlayerPerTeam)
{
	TEAM team;

	cout << "Enter team's name: ";
	cin >> team.name;
	cout << "Enter team's description: ";
	cin.ignore();
	getline(cin, team.desc);

	// date of set up

	int playerCount;
	bool pass = true;

	do
	{
		cout << "Enter the count of the members: ";
		cin >> playerCount;

		if (playerCount > maxPlayerPerTeam || playerCount < 0)
		{
			cout << "The entered number doesn't match the criteria (1 - 5)" << endl;
			cout << "Try again!" << endl;
			pass = false;
		}
		else
		{
			for (int i = 0; i < playerCount; i++)
			{
				cout << "Enter data for student " << i + 1 << endl;
				cout << "Email: ";
				cin >> team.members[i].studentEmail;
				cout << "Role id: ";
				cin >> team.members[i].roleId;
			}
		}

	} while (!pass);

	return team;
}

void enterRecords(std::function<void()> callback, string text)
{
	int recordCount;
	bool isRecordValid = true;

	do
	{
		cout << "Enter the count of " << text << "s: ";
		cin >> recordCount;

		if (recordCount < 0)
		{
			cout << "The entered count doesn't match the criteria ( > 0)" << endl;
			cout << "Try again!" << endl;
			isRecordValid = false;
		}
		else
		{
			for (int i = 0; i < recordCount; i++)
			{
				cout << "Enter data for " << text << " [" << i << "]: " << endl;

				callback();
			}
		}

	} while (!isRecordValid);
}

SCHOOL enterSchool()
{
	SCHOOL school;

	cout << "Enter school's name: ";
	cin >> school.name;
	cout << "Enter school's city: ";
	cin >> school.city;
	cout << "Enter school's address: ";
	cin >> school.address;

	enterRecords([&]() {
		school.students.push_back(enterStudent());
		}, "teacher");

	cout << "Enter the count of max players per team: ";
	cin >> school.maxMemberCountPerTeam;

	enterRecords([&]() {
		school.teams.push_back(enterTeam(school.maxMemberCountPerTeam));
		}, "team");

	enterRecords([&]() {
		school.students.push_back(enterStudent());
		}, "student");

	// enter roles

	return school;
}