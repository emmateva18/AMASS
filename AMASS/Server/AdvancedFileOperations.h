#pragma once
#include "ServerStructures.h"
void readRecord(std::fstream& file, STUDENT& student);
void readRecord(std::fstream& file, TEACHER& teacher);
void readRecord(std::fstream& file, DATE& date);
void readRecord(std::fstream& file, TEAM_MEMBER& member);
void readRecord(std::fstream& file, TEAM& team);
void readRecord(std::fstream& file, SCHOOL& school);
void readDataBase(std::fstream& file, std::vector<SCHOOL>& schools);
void saveDataBase(std::fstream& file, std::vector<SCHOOL> schools);