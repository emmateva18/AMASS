#include "DataFunctions.h"

using namespace std;

typedef unsigned char byte;

void saveStr(fstream& file, string str)
{
	uint16_t size = (uint16_t)str.size();
	byte* buffer = (byte*)str.c_str();
	file.write((const char *)&size, sizeof(size));
	file.write((const char *)buffer, (uint16_t)size);
}

void saveInt(fstream& file, int a)
{
	file.write((const char*)&a, sizeof(int));
}

void saveBool(fstream& file, bool a)
{
	file.write((const char*)&a, sizeof(bool));
}

void readStr(fstream& file, string& str)
{
	uint16_t size=0;
	file.read((char*)&size,sizeof(uint16_t));
	char* buf = new char[size + 1];
	file.read(buf, size);
	buf[size] = '\0';
	string tmp(buf);
	str = tmp;
}

void saveVec(fstream& file, vector<int> vec)
{
	/*uint16_t size = (uint16_t)vec.size();
	int* data = new int[size];
	data = vec.data();
	file.write((const char*)&size, sizeof(size));
	file.write((const char*)data, (uint16_t)size*sizeof(int));*/
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