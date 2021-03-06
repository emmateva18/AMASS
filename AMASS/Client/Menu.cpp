#include "Menu.h";
using namespace std;
void MENU::showMenuItems()
{
	for (size_t i = 0; i < items.size(); i++)
	{
		if (items[i].isSelected)
		{
			cout << "\x1b[36m" <<items[i].number<<"."<<items[i].text<<endl;
		}
		else
		{
			cout << "\x1b[97m" << items[i].number << "." << items[i].text << endl;
		}
	}
}
void showMenuItems(vector<MENU_ITEMS>& items, int selectedIndex)
{
	for (size_t i = 0; i < items.size(); i++)
	{
		if (i == selectedIndex)
		{
			cout << "\x1b[33m";
		}
		else
		{
			cout << "\x1b[97m";
		}
		cout << items[i].number << ". " << items[i].text << endl;
	}
}
void showSecondaryMenu(int& selectedItem, int& ch)
{

	vector<MENU_ITEMS> editInfoMenuItems = {
		{true, '1', "add info"},
		{false,'2',"delete info"},
		{false,'3',"Exit"},
	};
	if (ch == 13)
	{
		while (true)
		{
			system("cls");
			switch (selectedItem)
			{
			case 1:
			{
				showMenuItems(editInfoMenuItems, selectedItem);
				ch = _getch();
				if (ch == 224)
				{
					switch (_getch())
					{
					case 80: selectedItem++; break;
					case 72: selectedItem--; break;
					}
				}
			}
			}

		}
	}
}

int findIndex(MENU menu)
{
	for (size_t i = 0; i < menu.items.size(); i++)
	{
		if (menu.items[i].isSelected)
			return i;
	}
	return string::npos;
}
bool validate(int selection, MENU menu)
{
	if (selection >= 0 and selection < int(menu.items.size()))
		return 1;
	return 0;
}
void getUserInput(vector<MENU> menus)
{
	int currentItem = 0;
	int currentMenu = 0;
	while (1)
	{
		system("cls");
		menus[currentMenu].showMenuItems();
		int ch = _getch();
		if (ch == 224)
		{
			switch (_getch())
			{
			case 80: //down
				if (validate(currentItem+1, menus[currentMenu]))
				{
					menus[currentMenu].items[currentItem].isSelected=false;
					currentItem++;
					menus[currentMenu].items[currentItem].isSelected = true;
				}	
				break;
			case 72: //up
				if (validate(currentItem-1, menus[currentMenu]))
				{
					menus[currentMenu].items[currentItem].isSelected = false;
					currentItem--;
					menus[currentMenu].items[currentItem].isSelected = true;
				}
				break;
			}
		}
		if (ch == 13)
		{
			action ac = menus[currentMenu].items[currentItem].action;
			if (menus[currentMenu].items[currentItem].nextMenuPos == -1)
				ac();
			else
				currentMenu= menus[currentMenu].items[currentItem].nextMenuPos;
		}
	}
}
void showMainMenu(int& selectedItem, int& ch)
{

	vector<MENU_ITEMS> mainMenuItems = {
		{true, '1', "Show info"},
		{false,'2',"Edit info"},
		{false,'3',"Exit"},
	};
	while (true)
	{
		system("cls");
		showMenuItems(mainMenuItems, selectedItem);
		ch = _getch();
		if (ch == 224)
		{
			switch (_getch())
			{
			case 80: selectedItem++; break;
			case 72: selectedItem--; break;
			}
		}
		showSecondaryMenu(selectedItem, ch);
	}
}
vector<MENU> initMenus()
{
	vector<MENU> menus;
	MENU mainMenu =
	{
		{
			{true,'1',"Create School",nullptr,2},
			{false,'2',"Display all schools",nullptr,-1},
			{false,'3',"Edit School",nullptr,1},
			{false,'4',"Exit",}
		}
	};

	MENU editMenu =
	{
		{
			{true,'1',"Create elements"},
			{false,'2',"Update elements"},
			{false,'3',"Delete elements"},
			{false,'4',"Exit"}
		}
	};

	MENU createMenu =
	{
		{
			{true,'1',"Create teacher"},
			{false, '2',"Create team"},
			{false,'3',"Create student"},
			{false, '4', "Create Role"},
			{false, '5',"Input maximum number of members per team"},
			{false,'6',"Exit"}
		}
	};

	MENU updateMenu =
	{
		{
			{true,'1',"Update school name"},
			{false,'2',"Update school address"},
			{false,'3',"Update school city"},
			{false,'4',"Update teachers"},
			{false,'5',"Update students"},
			{false,'6',"Update roles"},
			{false,'7',"Update teams"},
			{false,'8',"Exit"}
		}
	};

	MENU deleteMenu =
	{
		{
			{true,'1',"Delete School"},
			{false,'2',"Delete team"},
			{false,'3',"Delete Role"},
			{false,'4',"Delete student"},
			{false,'5',"Delete teacher"},
			{false,'6',"Exit"}
		}
	};
	menus = { mainMenu,createMenu,editMenu,updateMenu,deleteMenu };
	return menus;
}