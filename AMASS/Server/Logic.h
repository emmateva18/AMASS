#pragma once
#include "Libraries.h"
#include "../CommunicationLibrary/CommunicationLibrary.h"
using namespace std;

//CRUD

void init(vector<SCHOOL>& schools);

void createStudent(vector<SCHOOL>& schools, int schoolId, STUDENT student);
void createTeacher(vector<SCHOOL>& schools, int schoolId, TEACHER teacher);
void createTeam(vector<SCHOOL>& schools, int schoolId, TEAM team);
void createSchool(vector<SCHOOL>& schools, SCHOOL school);

void deleteStudent(SCHOOL& school, int studentId);
void deleteTeacher(SCHOOL& school, int teacherId);
void deleteRoles(SCHOOL& school, int teamId);
void deleteSchool(vector<SCHOOL>& schools, int schoolId);
void deleteTeam(SCHOOL& school, int teamId);