#pragma once
#include <iostream>
#include "conio.h"
#include <vector>
#include <string>
struct MENU_ITEMS
{
	bool isSelected;
	char number;
	std::string text;
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
void showMenuItems(std::vector<MENU_ITEMS>& items, int selectedIndex);
void showSecondaryMenu(int& selectedItem, int& ch);
void showMainMenu(int& selectedItem, int& ch);

