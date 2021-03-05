#pragma once
#include "Libraries.h"
#include "../CommunicationLibrary/CommunicationLibrary.h"
using namespace std;

//CRUD

void init(vector<SCHOOL>& schools);
void createSchool(vector<SCHOOL>& schools, SCHOOL school);
void createStudent(vector<SCHOOL>& schools, int schoolId, STUDENT student);
void createTeacher(vector<SCHOOL>& schools, int schoolId, TEACHER teacher);
void createTeam(vector<SCHOOL>& schools, int schoolId, TEAM team);
void createSchool(vector<SCHOOL>& schools, SCHOOL school);
void deleteStudent(SCHOOL& school, int studentId);
