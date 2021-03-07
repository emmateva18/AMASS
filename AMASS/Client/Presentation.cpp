#include "Presentation.h"
#include "Libraries.h"
#include <functional>
#include <iomanip>

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

void displaySchool(SCHOOL school)
{
	cout << "School " << school.id << " details:" << endl;
	cout << "Name: " << school.name << endl;
	cout << "City: " << school.city << endl;
	cout << "Adress: " << school.address << endl;

	cout << "List of the teachers: " << endl;

	for (size_t i = 0; i < school.teachers.size(); i++)
	{
		displayTeacher(school.teachers[i], school.id);
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

				if (callback)
				{
					callback();
				}
			}
		}

	} while (!isRecordValid);
}

SCHOOL enterSchool()
{
	SCHOOL school;

	cout << "Enter school's name: ";
	getline(cin, school.name);
	cout << "Enter school's city: ";
	getline(cin, school.city);
	cout << "Enter school's address: ";
	getline(cin, school.address);

	school.id = INT_MAX;
	school.maxMemberCountPerTeam = INT_MAX;
	school.teachers.clear();
	school.students.clear();
	school.teams.clear();
	school.roles.clear();

	/*enterRecords([&]() {
		school.students.push_back(enterStudent());
		}, "teacher");

	cout << "Enter the count of max players per team: ";
	cin >> school.maxMemberCountPerTeam;

	enterRecords([&]() {
		school.teams.push_back(enterTeam(school.maxMemberCountPerTeam));
		}, "team");

	enterRecords([&]() {
		school.students.push_back(enterStudent());
		}, "student");*/

		// enter roles

	return school;
}

void displayFullLine()
{
	cout << "|";
	displayString("-", 150);
	cout << "|";
	cout << endl;
}

void displayString(string str, int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << str;
	}
}

void displaySchoolInformation(SCHOOL school)
{
	displayFullLine();
	cout << "|" << setw(5) << left << "ID" << "|" << setw(50) << left << "NAME" << "|"
		<< setw(30) << left << "CITY" << "|" << setw(41) << left << "ADDRESS" << "|"
		<< setw(20) << left << "MAX_PLAYER_COUNT" << "|" << endl;
	//displayFullLine();

	cout << "|" << setw(5) << school.id << "|" << setw(50) << school.name << "|"
		<< setw(30) << school.city << "|" << setw(41) << school.address << "|"
		<< setw(20) << school.maxMemberCountPerTeam << "|" << endl;
	displayFullLine();
}

void displayTeachersInformation(SCHOOL school)
{
	displayFullLine();

	cout << "|" << setw(5) << left << "ID" << "|" << setw(59) << left << "NAME" << "|"
		<< setw(58) << left << "EMAIL" << "|" << setw(25) << left << "TEAM IDS" << "|" << endl;

	displayFullLine();

	for (size_t i = 0; i < school.teachers.size(); i++)
	{
		displayTeacherInformation(school.teachers[i]);
	}

	displayFullLine();
}

string nameToString(string fName, string mName, string surname)
{
	return fName + " " + mName + " " + surname;
}

string vectorIntToString(vector<int> vec)
{
	string result;

	for (size_t i = 0; i < vec.size(); i++)
	{
		result += to_string(vec[i]);
		result += " ";
	}

	return result;
}

string dateOfSetupToString(DATE date)
{
	string result;

	result += to_string(date.day);
	result += "/";
	result += to_string(date.month);
	result += "/";
	result += to_string(date.year);

	return result;
}

void displayTeacherInformation(TEACHER teacher)
{
	string name = nameToString(teacher.firstName, teacher.middleName, teacher.surname);
	string teamIds = vectorIntToString(teacher.teamIds);

	cout << "|" << setw(5) << teacher.id << "|" << setw(59) << name << "|"
		<< setw(58) << teacher.email << "|" << setw(25) << teamIds << "|" << endl;
}

void displayTeamsInformation(SCHOOL school)
{
	displayFullLine();

	cout << "|" << setw(5) << left << "ID" << "|" << setw(30) << left << "NAME" << "|"
		<< setw(50) << left << "DESCRIPTION" << "|" << setw(15) << left << "DATE_OF_SETUP" << "|"
		<< setw(16) << "STATUS" << "|" << setw(8) << "ROLE_ID" << "|" << setw(20) << "STUDENT_EMAILS" << "|" << endl;

	displayFullLine();
}

void displayTeacherInformation(TEAM team)
{
	string date = dateOfSetupToString(team.dateOfSetUp);
	string status = statusToString(team.status);
	//string roleIds = vectorIntToString(team.members)

	cout << "|" << setw(5) << left << team.id << "|" << setw(30) << left << team.name << "|"
		<< setw(50) << left << team.desc << "|" << setw(15) << left << date << "|"
		<< setw(16) << status << "|" << setw(8) << "ROLE_ID" << "|" << setw(20) << "STUDENT_EMAILS" << "|" << endl;
}

void displaySchoolWithTable(SCHOOL school)
{
	displayFullLine();

	cout << "|" << setw(75) << "SCHOOL" << setw(76) << "|" << endl;
	displaySchoolInformation(school);

	cout << "|" << setw(75) << right << "TEACHERS" << setw(76) << "|" << endl;
	displayTeachersInformation(school);

	cout << "|" << setw(75) << right << "TEAMS" << setw(76) << "|" << endl;
	displayTeamsInformation(school);
}
