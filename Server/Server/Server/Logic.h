#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Structures.h"
using namespace std;

//CRUD

void init(vector<SCHOOL>& schools);
void createSchool(vector<SCHOOL>& schools, SCHOOL school);
string statusToString(STATUS status);
void displaySchool(SCHOOL school, int id);