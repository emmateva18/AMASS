#include "Libraries.h"
#include "ServerStructures.h"
#include "Logic.h"
#include "BasicFileOperations.h"
#include "AdvancedFileOperations.h"
#include <asio.hpp>
using namespace std;

int main()
{
	vector<SCHOOL> schools1,schools2;
	init(schools1);
	fstream f;
	f.open("data.dat", ios::in | ios::out | ios::binary | ios::trunc);
	saveDataBase(f,schools1);
	f.close();
	f.open("data.dat", ios::in | ios::out | ios::binary);
	readDataBase(f, schools2);
	f.close();
	cout << schools2[0].students[2].id;

}