#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void saveStr(std::fstream& file, std::string str);
void readStr(std::fstream& file, std::string& str);
void saveInt(std::fstream& file, int a);