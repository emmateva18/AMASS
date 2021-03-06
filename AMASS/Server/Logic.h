#pragma once
#include "Libraries.h"
#include "../CommunicationLibrary/CommunicationLibrary.h"
using namespace std;

//CRUD

void init(vector<SCHOOL>& schools);

void createRole(SCHOOL& school, ROLE role);
void createStudent(SCHOOL& school, STUDENT student);
void createTeacher(SCHOOL& school, TEACHER teacher);
void createTeam(SCHOOL& school, TEAM team);
void createSchool(vector<SCHOOL>& schools, SCHOOL school);

void deleteStudent(SCHOOL& school, int studentId);
void deleteTeacher(SCHOOL& school, int teacherId);
void deleteRoles(SCHOOL& school, int teamId);
void deleteSchool(vector<SCHOOL>& schools, int schoolId);
void deleteTeam(SCHOOL& school, int teamId);