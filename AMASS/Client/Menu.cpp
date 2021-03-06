#include "Menu.h";
using namespace std;
void MENU::showMenuItems()
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