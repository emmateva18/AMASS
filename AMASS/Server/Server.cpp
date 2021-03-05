#include "Libraries.h"
#include "Logic.h"
#include "BasicFileOperations.h"
#include "AdvancedFileOperations.h"
#include "ServerConnection.h"
using namespace std;

int main()
{
	//vector<SCHOOL> schools1,schools2;
	//init(schools1);
	//fstream f;
	//f.open("data.dat", ios::in | ios::out | ios::binary | ios::trunc);
	//saveDataBase(f,schools1);
	//f.close();
	//f.open("data.dat", ios::in | ios::out | ios::binary);
	//readDataBase(f, schools2);
	//f.close();
	//cout << schools2[0].students[2].id;

	//vector<SCHOOL> s;
	//init(s);
	//deleteStudent(s, 0, 0);

	serverStart();
}