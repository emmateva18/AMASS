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


	/*TEACHER t1 = { 0,"Petur","Ognqnov","Georgiev","POGeorgiev@abv.bg", {1,2,3} };
	TEACHER t3 = { 2,"Vankata","Dunera","Vulchev","ILYDuner@abv.bg",{4,1,6} };
	STUDENT s1 = { 0,"Georgi","Georgiev","Georgiev","10A","GG@abv.bg" };
	TEAM te1 = { 0, "Chupacabras","example description lorem eipsum take up space",{0,0,0},STATUS::pendingApproval,{{"GG@abv.bg", 1},{"SBP@abv.bg", 2}} };
	ROLE r1 = { 0, "Scrum Master" };
	string name = "PGKPI";
	string city = "Burgas";
	string address = "Meden Rudnik 54";

	vector <TEACHER> teachers{ t1, t3 };
	vector <STUDENT> students{ s1 };
	vector<TEAM> teams{ te1 };
	vector<ROLE> roles = { r1 };

	SCHOOL school{ 0,5, name, city, address, teachers, teams, students };

	displaySchoolWithTable(school);*/
}