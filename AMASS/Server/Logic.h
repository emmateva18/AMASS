#pragma once
#include "Libraries.h"
#include "../CommunicationLibrary/CommunicationLibrary.h"
using namespace std;

//CRUD

void init(vector<SCHOOL>& schools);

void createRole(SCHOOL& school, ROLE role, std::fstream& file);
void createStudent(SCHOOL& school, STUDENT student, std::fstream& file);
void createTeacher(SCHOOL& school, TEACHER teacher, std::fstream& file);
void createTeam(SCHOOL& school, TEAM team, std::fstream& file);
void createSchool(vector<SCHOOL>& schools, SCHOOL school);

void deleteStudent(SCHOOL& school, int studentId, std::fstream& file);
void deleteTeacher(SCHOOL& school, int teacherId, std::fstream& file);
void deleteRoles(SCHOOL& school, int teamId, std::fstream& file);
void deleteSchool(vector<SCHOOL>& schools, int schoolId, std::fstream& file);
void deleteTeam(SCHOOL& school, int teamId, std::fstream& file);