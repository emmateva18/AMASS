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