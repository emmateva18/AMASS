#include "Libraries.h"
#include "Logic.h"
#include "BasicFileOperations.h"
#include "AdvancedFileOperations.h"
#include "ServerConnection.h"
#include "../Client/Presentation.h"
using namespace std;

int main()
{
	vector<SCHOOL> schools;
	init(schools);
	startServer(schools);	

}