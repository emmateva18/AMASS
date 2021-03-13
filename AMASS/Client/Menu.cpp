#include "Menu.h";
using namespace std;
void MENU::showMenuItems()
{
	for (size_t i = 0; i < items.size(); i++)
	{
		if (items[i].isSelected)
		{
			cout << "\x1b[36m" << items[i].number << "." << items[i].text << endl;
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

void resetPositions(vector<MENU>& menus)
{
	for (size_t i = 0; i < menus.size(); i++)
	{
		for (size_t j = 0; j < menus[i].items.size(); j++)
		{
			menus[i].items[j].isSelected = false;
		}
	}
	for (size_t i = 0; i < menus.size(); i++)
	{
		menus[i].items[0].isSelected = true;
	}
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
				if (validate(currentItem + 1, menus[currentMenu]))
				{
					menus[currentMenu].items[currentItem].isSelected = false;
					currentItem++;
					menus[currentMenu].items[currentItem].isSelected = true;
				}
				break;
			case 72: //up
				if (validate(currentItem - 1, menus[currentMenu]))
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
			if (menus[currentMenu].items[currentItem].nextMenuPos != -1)
			{
				currentMenu = menus[currentMenu].items[currentItem].nextMenuPos;
				currentItem = 0;
				resetPositions(menus);
			}
			if (ac != nullptr)
			{
				ac();
			}
		}
		if (ch == 27)
		{
			// Escape ch to be written
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
			{true,'1',"Create School",requestCrtSch,-1},
			{false,'2',"Display information",nullptr,5},
			{false,'3',"Edit School",nullptr,11},
			{false,'4',"Exit",exitProgram,-1}
		}
	};

	MENU editMenu =
	{
		{
			{true,'1',"Create elements",nullptr,2},
			{false,'2',"Update elements",nullptr,3},
			{false,'3',"Delete elements",nullptr,4},
			{false,'4',"Back",nullptr,0}
		}
	};

	MENU createMenu =
	{
		{
			{true,'1',"Create teacher",requestCrtTeacher,-1},
			{false, '2',"Create team",requestCrtTeam,-1},
			{false,'3',"Create student",requestCrtStudent,-1},
			{false, '4', "Create Role",requestCrtRole,-1},
			{false, '5',"Input maximum number of members per team",requestInputMaxNumOfMem,-1},
			{false,'6',"Back",nullptr,1}
		}
	};

	MENU updateMenu =
	{
		{
			{true,'1',"Update school name",requestUpdateSchoolName,-1},
			{false,'2',"Update school address",requestUpdateSchoolAddress,-1},
			{false,'3',"Update school city",requestUpdateSchoolCity,-1},
			{false,'4',"Update teachers",nullptr,7},
			{false,'5',"Update students",nullptr,10},
			{false,'6',"Update roles",nullptr,9},
			{false,'7',"Update teams",nullptr,8},
			{false,'8',"Back",nullptr,1}
		}
	};

	MENU deleteMenu =
	{
		{
			{true,'1',"Delete School",requestDeleteSchool,-1},
			{false,'2',"Delete team",requestDeleteTeam,-1},
			{false,'3',"Delete Role",requestDeleteRole,-1},
			{false,'4',"Delete student",requestDeleteStudent,-1},
			{false,'5',"Delete teacher",requestDeleteTeacher,-1},
			{false,'6',"Back",nullptr,1}
		}
	};

	MENU displayMenu =
	{
		{
			{true,'1',"Display all records",requestReadDB,-1},
			{false,'2',"Display record by criteria",nullptr,7},
			{false,'3',"Back",nullptr,0}
		}
	};

	MENU displayRecordsMenu =
	{
		{
			{true,'1',"Show students in team",nullptr,-1},
			{false,'2',"Show teachers without teams",nullptr,-1},
			{false,'3',"Show archived teams",nullptr,-1},
			{false,'4',"Back",nullptr,6}
		}
	};

	MENU updateTeacherMenu =
	{
		{
			{true,'1',"Update first name",requestUpdateTeacherFirstName,-1},
			{false,'2',"Update middle name",requestUpdateTeacherMiddleName,-1},
			{false,'3',"Update surname",requestUpdateTeacherSurname,-1},
			{false,'4',"Update email",requestUpdateTeacherEmail,-1},
			{false,'5',"Update the teacher's teams",requestUpdateTeacherTeams,-1},
			{false,'6',"Back",nullptr,3}
		}
	};

	MENU updateTeamMenu =
	{
		{
			{true,'1',"Update team name",requestUpdateTeamName,-1},
			{false,'2',"Update team description",requestUpdateTeamDescription,-1},
			{false,'3',"Update team status",requestUpdateTeamStatus,-1},
			{false,'4',"Update team members",nullptr,9},
			{false,'5',"Back",nullptr,3},
		}
	};

	MENU updateTeamMemberMenu =
	{
		{
			{true,'1',"Update student role",nullptr,-1},
			{false,'2',"Back",nullptr,8},
		}
	};

	MENU updateStudentMenu =
	{
		{
			{true,'1',"Update student's first name",requestUpdateStudentFirstName,-1},
			{false,'2',"Update student's middle name",requestUpdateStudentMiddleName,-1},
			{false,'3',"Update student's surname",requestUpdateStudentSurname,-1},
			{false,'4',"Update student's class",requestUpdateStudentClass,-1},
			{false,'5',"Update student's email",requestUpdateStudentEmail,-1},
			{false,'6',"Update wether a student is in a team",requestUpdateStudentIsInTeam,-1},
			{false,'7',"Back",nullptr,3},
		}
	};

	MENU idMenu =
	{
		{
			{true,'1',"Press to enter the ID of the school",getSchoolId,1},
			{false,'2',"Back",nullptr,0}
		}
	};

	menus =
	{
		mainMenu,editMenu,createMenu,updateMenu,
		deleteMenu,displayMenu,displayRecordsMenu,updateTeacherMenu,
		updateTeamMenu,updateTeamMemberMenu,updateStudentMenu, idMenu
	};

	return menus;
}