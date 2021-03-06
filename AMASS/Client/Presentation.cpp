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
		case archived:
			return "Archived";
		default:
			return "";
	}
}

STUDENT enterStudent()
{
	STUDENT student;

	cout << "Enter student's data: " << endl;

	enterString(student.firstName, "First name: ");
	enterString(student.middleName, "Middle name: ");
	enterString(student.surname, "Surname: ");
	enterGrade(student.grade, "Grade: ");
	enterEmail(student.email, "Email: ");

	return student;
}

TEACHER enterTeacher()
{
	TEACHER teacher;

	cout << "Enter teacher's data: " << endl;

	enterString(teacher.firstName, "First name: ");
	enterString(teacher.middleName, "Middle name: ");
	enterString(teacher.surname, "Surname: ");
	enterEmail(teacher.email, "Email: ");

	return teacher;
}

TEAM enterTeam(int maxPlayerPerTeam)
{
	TEAM team;
	TEAM_MEMBER member;

	cout << "Enter team's data: " << endl;

	clearInputStream();

	cout << "Name: ";
	getline(cin, team.name);
	cout << "Description: ";
	getline(cin, team.desc);

	return team;
}

ROLE enterRole()
{
	ROLE role;
	cout << "Enter data for the role: " << endl;

	enterString(role.name, "Name: ");
	return role;
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

void clearInputStream()
{
	int gc = cin.rdbuf()->in_avail();
	if (gc)
	{
		cin.ignore(gc);
	}
}

SCHOOL enterSchool()
{
	SCHOOL school;

	cout << "Enter data for the school: " << endl;

	clearInputStream();

	cout << "Name: ";
	getline(cin, school.name);
	cout << "City: ";
	getline(cin, school.city);
	cout << "Address: ";
	getline(cin, school.address);

	school.id = INT_MAX;

	bool isValid = false;

	do
	{
		enterInt(school.maxMemberCountPerTeam, "Max members per team: ");
		if (school.maxMemberCountPerTeam < 0 || school.maxMemberCountPerTeam > 5)
		{
			cout << "Invalid range (1 - 4)" << endl << "Please try again!" << endl;
		}
		else
		{
			isValid = true;
		}
	} while (!isValid);

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

int enterTeamStatus()
{
	cout << "0. Pending Approval" << endl;;
	cout << "1. In Use" << endl;
	cout << "2. Not Active" << endl;
	cout << "3. Archived" << endl;

	int choice;

	do
	{
		enterInt(choice, "Enter option: ");
		if (choice >= 0 && choice <= 3)
		{
			return choice;
		}
		else
		{
			cout << "Invalid option, please try again!" << endl;
		}
	} while (true);
}

vector<int> assignStudentInTeamMenu(SCHOOL& school)
{
	vector<int> result;
	int teamId;
	int studentId;

	enterInt(teamId, "Enter team's id: ");
	enterInt(studentId, "Enter student's id: ");

	result.push_back(teamId);
	result.push_back(studentId);

	return result;
}

void displayCriteriaTeachersWithNoTeams(SCHOOL school)
{
	for (size_t i = 0; i < school.teachers.size(); i++)
	{
		if (school.teachers[i].teamIds.empty())
		{
			cout << school.teachers[i].firstName << " " << school.teachers[i].middleName << " " << school.teachers[i].surname << endl;
		}
	}
}

void displayCriteriaStudentsWithNoTeam(SCHOOL school)
{
	for (size_t i = 0; i < school.students.size(); i++)
	{
		if (!school.students[i].isInTeam)
		{
			cout << school.students[i].firstName << " " << school.students[i].middleName <<" "<< school.students[i].surname << endl;
		}
	}
}

void displayCriteriaTeamByStatus(SCHOOL school, STATUS status)
{
	for (size_t i = 0; i < school.teams.size(); i++)
	{
		if (school.teams[i].status == status)
		{
			cout << school.teams[i].name << endl;
		}
	}
}

void listSchoolsDetails(vector<SCHOOL> schools)
{
	for (size_t i = 0; i < schools.size(); i++)
	{
		listSchoolDetails(schools[i]);
	}
}

void listSchoolDetails(SCHOOL school)
{
	cout << school.id << " " << school.name << endl;
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

void displaySchoolHeading()
{
	cout << "| " << setw(5) << left << "ID" << "| "
		<< setw(71) << left << "NAME" << "| "
		<< setw(40) << left << "CITY" << "| "
		<< setw(59) << left << "ADDRESS" << "| "
		<< setw(17) << left << "MAX_PLAYER_COUNT"
		<< "| " << endl;
}

void displaySchoolInformation(SCHOOL school)
{
	displaySchoolHeading();

	cout << "| " << setw(5) << " "
		<< setw(73) << "| "
		<< setw(42) << "| "
		<< setw(61) << "| "
		<< setw(19) << "| "
		<< "|" << endl;

	cout << "| " << setw(5) << left << school.id << "| " << setw(71) << school.name << "| "
		<< setw(40) << school.city << "| " << setw(59) << school.address << "| "
		<< setw(17) << school.maxMemberCountPerTeam << "| " << endl;
	displayFullLine();
}

void displayTeacherHeading()
{
	cout << "| " << setw(5) << left << "ID" << "| "
		<< setw(80) << left << "NAME" << "| "
		<< setw(80) << left << "EMAIL" << "| "
		<< setw(29) << left << "TEAM IDS" << "| " << endl;
}

void displayTeachersInformation(SCHOOL school)
{
	displayTeacherHeading();

	cout << "| " << setw(5) << " "
		<< setw(82) << "| "
		<< setw(82) << "| "
		<< setw(31) << "| "
		<< "|" << endl;

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

void displayTeamsHeading()
{

	cout << "| " << setw(5) << left << "ID" << "| " << setw(20) << left << "NAME" << "| "
		<< setw(80) << left << "DESCRIPTION" << "| " << setw(14) << left << "DATE_OF_SETUP" << "| "
		<< setw(17) << "STATUS" << "| " << setw(8) << "ROLE_ID" << "| " << setw(44) << "STUDENT_EMAILS" << "| " << endl;
}

void displayTeamsInformation(SCHOOL school)
{
	displayTeamsHeading();

	cout << "| " << setw(5) << " "
		<< setw(22) << "| "
		<< setw(82) << "| "
		<< setw(16) << "| "
		<< setw(19) << "| "
		<< setw(10) << "| "
		<< setw(46) << "| "
		<< "|" << endl;

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

void displayStudentHeading()
{
	cout << "| " << setw(5) << left << "ID" << "| " << setw(75) << left << "NAME" << "| "
		<< setw(20) << left << "GRADE" << "| " << setw(75) << left << "EMAIL" << "| "
		<< setw(17) << "IS_IN_TEAM" << "| " << endl;
}

void displayStudentsInformation(SCHOOL school)
{
	displayStudentHeading();

	cout << "| " << setw(5) << " "
		<< setw(77) << "| "
		<< setw(22) << "| "
		<< setw(77) << "| "
		<< setw(19) << "| "
		<< "|" << endl;

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

void displayRoleHeading()
{
	cout << "| " << setw(5) << left << "ID" << "| " << setw(193) << left << "NAME" << "| " << endl;
}

void displayRolesInformation(SCHOOL school)
{
	displayRoleHeading();

	cout << "| " << setw(5) << " "
		<< setw(195) << "| "
		<< "|" << endl;

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

void displaySchoolTitle()
{
	cout << "| " << setw(101) << right << "SCHOOL" << setw(100) << "|" << endl;
}

void displayTeacherTitle()
{
	cout << "| " << setw(101) << right << "TEACHERS" << setw(100) << "|" << endl;
}

void displayTeamTitle()
{
	cout << "| " << setw(101) << right << "TEAMS" << setw(100) << "|" << endl;
}

void displayStudentTitle()
{
	cout << "| " << setw(101) << right << "STUDENTS" << setw(100) << "|" << endl;
}

void displayRoleTitle()
{
	cout << "| " << setw(101) << right << "ROLES" << setw(100) << "|" << endl;
}

void displaySchoolStructure(SCHOOL school)
{
	displayFullLine();
	displaySchoolInformation(school);

	displayTeacherTitle();
	displayTeachersInformation(school);

	displayTeamTitle();
	displayTeamsInformation(school);
	
	displayStudentTitle();
	displayStudentsInformation(school);

	displayRoleTitle();
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

bool isStringInputValid(string input)
{
	if (input[0] == ' ')
	{
		return false;
	}

	for (size_t i = 0; i < input.size(); i++)
	{
		// checks if the element is not a letter
		if (!isalpha(input[i]))
		{
			return false;
		}

	}

	return true;
}

void enterString(string& str, string text)
{
	bool isValid = false;

	while (!isValid)
	{
		cout << text;
		cin >> str;

		if (isStringInputValid(str))
		{
			isValid = true;
		}
		else
		{
			cout << "Invalid characters, please try again!" << endl;
		}
	}
}

int tryReadInt()
{
	int input;
	cin >> input;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		throw "Invalid int input!";
	}
	else
	{
		return input;
	}
}

void enterInt(int& variable, string text)
{
	bool isValid = false;

	while (!isValid)
	{
		try
		{
			cout << text;
			variable = tryReadInt();
			isValid = true;
		}
		catch (const char* ex)
		{
			cout << "Exeption: " << ex << endl;
			cout << "Please try again!" << endl;
		}
	}
}

void enterEmail(string& email, string text)
{
	bool isValid = false;

	while (!isValid)
	{
		cout << text;
		cin >> email;

		if (email.find('@') != string::npos && email.find('.') != string::npos)
		{
			isValid = true;
		}
		else
		{
			cout << "You have entered invalid email address, please try again!" << endl;
		}
	}

}

void enterGrade(string& grade, string text)
{

	while (true)
	{
		cout << text;
		cin >> grade;

		if (grade.size() == 2)
		{

			if (int(grade[0]) >= 49 && int(grade[0]) <= 57)
			{
				if (int(grade[1]) >= 65 && int(grade[1]) <= 90)
				{
					return;
				}
			}
		}

		if (grade.size() == 3)
		{
			if (int(grade[0]) >= 49 && int(grade[0]) <= 57 && int(grade[1]) >= 48 && int(grade[1]) <= 57)
			{

				if (int(grade[2]) >= 65 && int(grade[2]) <= 90)
				{
					return;
				}
			}
		}
		cout << "Invalid grade details, please try again!" << endl;
	}
}

void enterBool(bool& boolean, string text)
{
	bool isValid = false;
	string temp;

	while (!isValid)
	{
		cout << text;
		cin >> temp;

		if (temp == "1")
		{
			boolean = true;
			isValid = true;
		}
		else if (temp == "0")
		{
			boolean = false;
			isValid = true;
		}
		else
		{
			cout << "Invalid input, please try again!" << endl;
		}

	}
}

void enterVectorOfIntegers(vector<int>& vec)
{
	int temp;
	int n;

	// < 0
	enterInt(n, "Enter how much elements you will enter: ");

	while (n--)
	{
		enterInt(temp, "Enter element: ");
		vec.push_back(temp);
	}
}

string initAMASS()
{
	char sq;
	sq = 178;
	string tripleSq;
	tripleSq += sq; tripleSq += sq; tripleSq += sq;
	string sqWithSpace;
	sqWithSpace += " "; sqWithSpace += sq;
	string pixelArt;
	pixelArt += " "; pixelArt += tripleSq; pixelArt += "  "; pixelArt += sq; pixelArt += "   "; pixelArt += sq; pixelArt += "  "; pixelArt += tripleSq; pixelArt += "   "; pixelArt += tripleSq; pixelArt += "  "; pixelArt += tripleSq; pixelArt += "\n";
	pixelArt += sq; pixelArt += "   "; pixelArt += sq; pixelArt += sqWithSpace; pixelArt += sq; pixelArt += sqWithSpace; pixelArt += sq; pixelArt += sqWithSpace; pixelArt += "   ";  pixelArt += sq; pixelArt += sqWithSpace; pixelArt += "    "; pixelArt += sq; pixelArt += "\n";
	pixelArt += tripleSq; pixelArt += sq; pixelArt += sq; pixelArt += sqWithSpace; pixelArt += sqWithSpace; pixelArt += sqWithSpace; pixelArt += sqWithSpace; pixelArt += tripleSq; pixelArt += sq;  pixelArt += " "; pixelArt += sqWithSpace;  pixelArt += sq; pixelArt += "  "; pixelArt += sqWithSpace; pixelArt += sq; pixelArt += "\n";
	pixelArt += sq; pixelArt += "   "; pixelArt += sq; pixelArt += sqWithSpace; pixelArt += "   "; pixelArt += sq; pixelArt += sqWithSpace; pixelArt += "   "; pixelArt += sq; pixelArt += "    "; pixelArt += sq; pixelArt += "    "; pixelArt += sq; pixelArt += "\n";
	pixelArt += sq; pixelArt += "   "; pixelArt += sq; pixelArt += sqWithSpace; pixelArt += "   "; pixelArt += sq; pixelArt += sqWithSpace; pixelArt += "   "; pixelArt += sq; pixelArt += " "; pixelArt += tripleSq; pixelArt += "  "; pixelArt += tripleSq; pixelArt += "\n";
	return pixelArt;
}