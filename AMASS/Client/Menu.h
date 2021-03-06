#pragma once
#include <iostream>
#include "conio.h"
#include <vector>
#include <string>
#include "ClientConnection.h"
struct MENU_ITEMS
{
	bool isSelected;
	char number;
	std::string text;
	void (*action);
};
struct MENU {
	std::vector<MENU_ITEMS> items;
	int selectedIndex = 0;

	void showMenuItems();
	/*
	void moveUp();
	void moveDown();
	void handleMenu(int selectedIndex);
	*/
};
int findIndex(MENU menu);
bool validate(int selection, MENU menu);
void getUserInput(std::vector<MENU> menus);
void showMenuItems(std::vector<MENU_ITEMS>& items, int selectedIndex);
void showSecondaryMenu(int& selectedItem, int& ch);
void showMainMenu(int& selectedItem, int& ch);
std::vector<MENU> initMenus();
