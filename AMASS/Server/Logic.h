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
void createTeamIdInTeacher(TEACHER& teacher, int teamId);

void deleteStudent(SCHOOL& school, int studentId);
void deleteTeacher(SCHOOL& school, int teacherId);
void deleteRoles(SCHOOL& school, int teamId);
void deleteSchool(vector<SCHOOL>& schools, int schoolId);
void deleteTeam(SCHOOL& school, int teamId);
void deleteTeamIdInTeacher(TEACHER& teacher, int teamIdIndex);

void updateStudentFirstName(STUDENT& student, string newFirstName);
void updateStudentMiddleName(STUDENT& student, string newMiddleName);
void updateStudentSurname(STUDENT& student, string newSurname);
void updateStudentGrade(STUDENT& student, string newGrade);
void updateStudentEmail(STUDENT& student, string newEmail);
void updateTeacherFirstName(TEACHER& teacher, string newFirstName);
void updateTeacherMiddleName(TEACHER& teacher, string newMiddleName);
void updateTeacherSurname(TEACHER& teacher, string newSurname);
void updateTeacherEmail(TEACHER& teacher, string newEmail);
void updateTeamIdInTeacher(TEACHER& teacher, int teamIdIndex, int newId);