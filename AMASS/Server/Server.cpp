#include "Libraries.h"
#include "Structures.h"
#include "Logic.h"
#include "BasicFileOperations.h"
using namespace std;

bool isInputNumeric(int a)
{
	try
	{
		std::cin >> a;
	}
	catch (const std::exception& ex)
	{
		cout << ex.what();
		return false;
	}
	return true;
}

int main()
{
	/*vector<SCHOOL> schools;
	init(schools);
	string a = "aaa", b;
	fstream f;
	f.open("data.dat", ios::binary | ios::out | ios::in | ios::trunc);
	schools[0].save(f);
	f.close();*/
	int a;
	isInputNumeric(a);
}