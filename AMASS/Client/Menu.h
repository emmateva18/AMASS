#pragma once
#include <iostream>
#include "conio.h"
#include <vector>
#include <string>
#include "ClientConnection.h"
typedef void(*action)();
typedef void(*idPtr)(int&);

struct MENU_ITEMS
{
	bool isSelected;
	char number;
	std::string text;
	action action = nullptr;
	int nextMenuPos=-1;
	idPtr id = nullptr;
};
struct MENU {
	std::vector<MENU_ITEMS> items;
	void showMenuItems();
};
void resetPositions(std::vector<MENU>& menus);
bool validate(int selection, MENU menu);
void getUserInput(std::vector<MENU> menus);
std::vector<MENU> initMenus();
