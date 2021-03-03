#include "Libraries.h"
#include "Structures.h"
#include "Logic.h"
#include "BasicFileOperations.h"
#include"AdvancedFileOperations.h"
using namespace std;

int main()
{
	vector<SCHOOL> schools1,schools2;
	init(schools1);
	fstream f;
	f.open("data.dat", ios::binary | ios::out | ios::in | ios::trunc);
	saveDataBase(f, schools1);
	f.close();
	f.open("data.dat", ios::binary | ios::out | ios::in);
	readDataBase(f, schools2);
	f.close();
	cout << schools2[0].city;
}