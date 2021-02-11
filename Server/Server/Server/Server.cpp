#include <iostream>
#include <string>
#include <vector>
#include "Structures.h"
#include "Logic.h"
#include "DataFunctions.h"
using namespace std;

int main()
{
	vector<SCHOOL> schools;
	init(schools);
	displaySchool(schools[0], 0);
	string a = "aaa",b;
	fstream f;
	f.open("data.dat", ios::binary | ios::out | ios::in | ios::trunc);
	vector<SCHOOL> pgkpi;
	init(pgkpi);
	pgkpi[0].save(f);
}