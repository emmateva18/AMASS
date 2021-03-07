#include "Presentation.h"
#include "Libraries.h"
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
			if (callback)
			{
				for (int i = 0; i < recordCount; i++)
				{
					cout << "Enter data for " << text << " [" << i << "]: " << endl;

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
	displayString("-", 201);
	cout << "|";
	cout << endl;
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

string teamMemberRoleIdsToString(TEAM team)
{
	string result;

	for (size_t i = 0; i < team.members.size(); i++)
	{
		result += to_string(team.members[i].roleId);
		result += " ";
	}

	return result;
}

string studentEmailsToString(TEAM team)
{
	string result;

	for (size_t i = 0; i < team.members.size(); i++)
	{
		result += team.members[i].studentEmail;
		result += " ";
	}

	return result;
}

string isInTeamToString(bool isInTeam)
{
	return isInTeam ? "true" : "false";
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
	//displayFullLine();
	cout << "| " << setw(5) << left << "ID" << "| " << setw(71) << left << "NAME" << "| "
		<< setw(40) << left << "CITY" << "| " << setw(59) << left << "ADDRESS" << "| "
		<< setw(17) << left << "MAX_PLAYER_COUNT" << "| " << endl;
	displayFullLine();

	cout << "| " << setw(5) << school.id << "| " << setw(71) << school.name << "| "
		<< setw(40) << school.city << "| " << setw(59) << school.address << "| "
		<< setw(17) << school.maxMemberCountPerTeam << "| " << endl;
	displayFullLine();
}

void displayTeachersInformation(SCHOOL school)
{
	//displayFullLine();

	cout << "| " << setw(5) << left << "ID" << "| " << setw(80) << left << "NAME" << "| "
		<< setw(80) << left << "EMAIL" << "| " << setw(29) << left << "TEAM IDS" << "| " << endl;

	displayFullLine();

	for (size_t i = 0; i < school.teachers.size(); i++)
	{
		displayTeacherInformation(school.teachers[i]);
	}

	displayFullLine();
}

void displayTeacherInformation(TEACHER teacher)
{
	string name = nameToString(teacher.firstName, teacher.middleName, teacher.surname);
	string teamIds = vectorIntToString(teacher.teamIds);

	cout << "| " << setw(5) << teacher.id << "| " << setw(80) << name << "| "
		<< setw(80) << teacher.email << "| " << setw(29) << teamIds << "| " << endl;
}

void displayTeamsInformation(SCHOOL school)
{
	//displayFullLine();

	cout << "| " << setw(5) << left << "ID" << "| " << setw(20) << left << "NAME" << "| "
		<< setw(80) << left << "DESCRIPTION" << "| " << setw(14) << left << "DATE_OF_SETUP" << "| "
		<< setw(17) << "STATUS" << "| " << setw(8) << "ROLE_ID" << "| " << setw(44) << "STUDENT_EMAILS" << "| " << endl;

	displayFullLine();

	for (size_t i = 0; i < school.teams.size(); i++)
	{
		displayTeamInformation(school.teams[i]);
	}

	displayFullLine();
}

void displayTeamInformation(TEAM team)
{
	string date = dateOfSetupToString(team.dateOfSetUp);
	string status = statusToString(team.status);
	string roleIds = teamMemberRoleIdsToString(team);
	string emails = studentEmailsToString(team);


	cout << "| " << setw(5) << left << team.id << "| " << setw(20) << left << team.name << "| "
		<< setw(80) << left << team.desc << "| " << setw(14) << left << date << "| "
		<< setw(17) << status << "| " << setw(8) << roleIds << "| " << setw(44) << emails << "| " << endl;

}

void displayStudentsInformation(SCHOOL school)
{
	//displayFullLine();

	cout << "| " << setw(5) << left << "ID" << "| " << setw(75) << left << "NAME" << "| "
		<< setw(20) << left << "GRADE" << "| " << setw(75) << left << "EMAIL" << "| "
		<< setw(17) << "IS_IN_TEAM" << "| " << endl;

	displayFullLine();

	for (size_t i = 0; i < school.students.size(); i++)
	{
		displayStudentInformation(school.students[i]);
	}

	displayFullLine();
}

void displayStudentInformation(STUDENT student)
{
	string name = nameToString(student.firstName, student.middleName, student.surname);
	string isInTeam = isInTeamToString(student.isInTeam);

	cout << "| " << setw(5) << left << student.id << "| " << setw(75) << left << name << "| "
		<< setw(20) << left << student.grade << "| " << setw(75) << left << student.email << "| "
		<< setw(17) << isInTeam << "| " << endl;
}

void displayRolesInformation(SCHOOL school)
{
	//displayFullLine();

	cout << "| " << setw(5) << left << "ID" << "| " << setw(193) << left << "NAME" << "| " << endl;

	displayFullLine();

	for (size_t i = 0; i < school.roles.size(); i++)
	{
		displayRoleInformation(school.roles[i]);
	}

	displayFullLine();
}

void displayRoleInformation(ROLE role)
{
	cout << "| " << setw(5) << left << role.id << "| " << setw(193) << left << role.name << "|" << endl;

}

void displaySchoolStructure(SCHOOL school)
{
	displayFullLine();

	cout << "| " << setw(101) << right << "SCHOOL" << setw(100) << "|" << endl;
	displaySchoolInformation(school);

	cout << "| " << setw(101) << right << "TEACHERS" << setw(100) << "|" << endl;
	displayTeachersInformation(school);

	cout << "| " << setw(101) << right << "TEAMS" << setw(100) << "|" << endl;
	displayTeamsInformation(school);

	cout << "| " << setw(101) << right << "STUDENTS" << setw(100) << "|" << endl;
	displayStudentsInformation(school);

	cout << "| " << setw(101) << right << "ROLES" << setw(100) << "|" << endl;
	displayRolesInformation(school);
}

void displaySchools(vector<SCHOOL> schools)
{
	for (size_t i = 0; i < schools.size(); i++)
	{
		displaySchoolStructure(schools[i]);
		cout << endl << endl << endl << endl << endl << endl << endl;
	}
}
