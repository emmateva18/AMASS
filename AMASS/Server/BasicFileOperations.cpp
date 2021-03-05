#include "BasicFileOperations.h"

using namespace std;

typedef unsigned char byte;

void saveStr(fstream& file, string str)
{
	uint16_t size = (uint16_t)str.size();
	byte* buffer = (byte*)str.c_str();
	file.write((const char*)&size, sizeof(size));
	file.write((const char*)buffer, (uint16_t)size);
}

void saveBool(fstream& file, bool a)
{
	file.write((const char*)&a, sizeof(bool));
}

void saveInt(fstream& file, int integer)
{
	file.write((const char*)&integer, sizeof(int));
}

void saveShortInt(fstream& file, uint16_t num)
{
	file.write((const char*)&num, sizeof(uint16_t));
}

void saveVec(fstream& file, vector<int> vec)
{
	uint16_t size = (uint16_t)vec.size();
	file.write((const char*)&size, sizeof(size));
	for (size_t i = 0; i < vec.size(); i++)
	{
		saveInt(file, vec[i]);
	}
}

void saveVec(fstream& file, vector<string> vec)
{
	uint16_t size = (uint16_t)vec.size();
	file.write((const char*)&size, sizeof(size));
	for (size_t i = 0; i < vec.size(); i++)
	{
		saveStr(file, vec[i]);
	}
}

void readStr(fstream& file, string& str)
{
	uint16_t size = 0;
	file.read((char*)&size, sizeof(uint16_t));
	char* buf = new char[size + 1];
	file.read(buf, size);
	buf[size] = '\0';
	string tmp(buf);
	str = tmp;
}

void readInt(fstream& file, int& num)
{
	file.read((char*)&num, sizeof(int));
}

void readShortInt(fstream& file, uint16_t& num)
{
	file.read((char*)&num, sizeof(num));
}

void readBool(fstream& file, bool& a)
{
	bool b;
	file.read((char*)&b, sizeof(bool));
	a = (bool)b;
}

void readVec(fstream& file, vector<string>& vec)
{
	uint16_t size = 0;
	string temp;
	file.read((char*)&size, sizeof(uint16_t));
	for (uint16_t i = 0; i < size; i++)
	{
		readStr(file, temp);
		vec.push_back(temp);
	}
}

void readVec(fstream& file, vector<int>& vec)
{
	uint16_t size = 0;
	int temp;
	file.read((char*)&size, sizeof(uint16_t));
	for (uint16_t i = 0; i < size; i++)
	{
		readInt(file, temp);
		vec.push_back(temp);
	}
}