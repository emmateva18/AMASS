#pragma once
#include "../CommunicationLibrary/CommunicationLibrary.h"

void displaySchool(SCHOOL school, int id);
void displayTeacher(TEACHER teacher, int id);
void displayTeam(TEAM team);
std::string statusToString(STATUS status);

STUDENT enterStudent();
TEACHER enterTeacher();
SCHOOL enterSchool();
TEAM enterTeam(int maxPlayerPerTeam);
void enterRecords(std::function<void()> callback, std::string text);