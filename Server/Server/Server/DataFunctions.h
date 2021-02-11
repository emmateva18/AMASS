#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void saveStr(std::fstream& file, std::string str);
void readStr(std::fstream& file, std::string& str);
void saveBool(std::fstream& file, bool a);
void saveInt(std::fstream& file, int a);
void saveVec(std::fstream& file, std::vector<int> vec);
void saveVec(std::fstream& file, std::vector<std::string> vec);