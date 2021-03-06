#include <iostream>
#include "ClientConnection.h"
#include "Presentation.h"
#include "Menu.h"
using namespace std;
int main()
{
	vector<MENU> menus = initMenus();
	int selectedIndex = 0;
	menus[0].showMenuItems();
	getUserInput(menus);
	//showMainMenu(selectedIndex,)
	//sendRequest(SYSTEM_CODE::sendString, str);
}