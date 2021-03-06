#pragma once
#include "../CommunicationLibrary/CommunicationLibrary.h"
#include "BasicFileOperations.h"
std::fstream initFile();
void readRecord(std::fstream& file, STUDENT& student);
void readRecord(std::fstream& file, TEACHER& teacher);
void readRecord(std::fstream& file, DATE& date);
void readRecord(std::fstream& file, TEAM_MEMBER& member);
void readRecord(std::fstream& file, TEAM& team);
void readRecord(std::fstream& file, SCHOOL& school);
void readDataBase(std::vector<SCHOOL>& schools);
void saveDataBase(std::vector<SCHOOL>& schools);
void save(std::fstream& file, ROLE role);
void save(std::fstream& file, STUDENT student);
void save(std::fstream& file, TEACHER teacher);
void save(std::fstream& file, DATE date);
void save(std::fstream& file, TEAM_MEMBER member);
void save(std::fstream& file, TEAM team);
void save(std::fstream& file, SCHOOL school);