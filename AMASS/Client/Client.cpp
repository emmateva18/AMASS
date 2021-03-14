#include <iostream>
#include "ClientConnection.h"
#include "Presentation.h"
#include "Menu.h"
using namespace std;
int main()
{
	pingServer();
	vector<MENU> menus = initMenus();
	int selectedIndex = 0;
	
	menus[0].showMenuItems();
	try
	{
		getUserInput(menus);
	}
	catch (exception& e)
	{
		cout << "There was an error: " << e.what()<<endl;
		cout << "Exiting program...";
		_getch();
		exit(0);
	}

}