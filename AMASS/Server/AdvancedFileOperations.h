#pragma once
#include "Structures.h"
void read(std::fstream& file, STUDENT& student);
void read(std::fstream& file, TEACHER& teacher);
void read(std::fstream& file, DATE& date);
void read(std::fstream& file, TEAM_MEMBER& member);
void read(std::fstream& file, TEAM& team);
void read(std::fstream& file, SCHOOL school);
void readDataBase(std::fstream& file, std::vector<SCHOOL>& schools);
void saveDataBase(std::fstream& file, std::vector<SCHOOL> schools);