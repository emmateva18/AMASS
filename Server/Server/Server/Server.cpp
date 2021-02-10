#include <iostream>
#include <string>
#include <vector>
#include "Structures.h"
#include "Logic.h"
using namespace std;

int main()
{
	vector<SCHOOL> schools;
	init(schools);
	displaySchool(schools[0], 0);
}