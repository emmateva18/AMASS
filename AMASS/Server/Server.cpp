#include "Libraries.h"
#include "Structures.h"
#include "Logic.h"
#include "DataFunctions.h"
using namespace std;

int main()
{
	vector<SCHOOL> schools;
	init(schools);
	displaySchool(schools[0], 0);
	string a = "aaa", b;
	fstream f;
	f.open("data.dat", ios::binary | ios::out | ios::in | ios::trunc);
	vector<string> vec1{ "test1","test2","test3" };
	vector<string> vec2;
	saveVec(f, vec1);
	f.close();
	f.open("data.dat", ios::binary | ios::out | ios::in);
	readVec(f, vec2);
	for (size_t i = 0; i < vec2.size(); i++)
	{
		cout << vec2[i];
	}
	f.close();
}