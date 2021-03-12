#pragma once
#include "../CommunicationLibrary/CommunicationLibrary.h"

std::string statusToString(STATUS status);

std::string nameToString(std::string fName, std::string mName, std::string surname);
std::string vectorIntToString(std::vector<int> vec);

STUDENT enterStudent();
TEACHER enterTeacher();
SCHOOL enterSchool();
TEAM enterTeam(int maxPlayerPerTeam);
void enterRecords(std::function<void()> callback, std::string text);

bool isStringInputValid(std::string input); 
void enterString(std::string& str, std::string text);
int tryReadInt();
void enterInt(int& variable, std::string text);
void enterEmail(std::string& email, std::string text);

void displayCriteriaTeachersWithNoTeams(SCHOOL school);
void displayCriteriaStudentsWithNoTeam(SCHOOL school);
void displayCriteriaTeamByStatus(SCHOOL school, STATUS status);

void displayFullLine();
void displayString(std::string str, int count);
void displaySchoolInformation(SCHOOL school);
void displayTeachersInformation(SCHOOL school);
void displayTeacherInformation(TEACHER teacher);
void displayTeamsInformation(SCHOOL school);
void displayTeamInformation(TEAM team);
void displayStudentsInformation(SCHOOL school);
void displayStudentInformation(STUDENT student);
void displayRolesInformation(SCHOOL school);
void displayRoleInformation(ROLE role);
void displaySchoolStructure(SCHOOL school);
void displaySchools(std::vector<SCHOOL> schools);