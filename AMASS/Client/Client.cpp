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

	/*TEACHER t1 = { 0,"petur","ognqnov","georgiev","pogeorgiev@abv.bg", {1,2,3} };
	TEACHER t2 = { 1,"gosho","dizela","petrov","dizela@gmail.com", {1,2,3} };
	TEACHER t3 = { 2,"vankata","dunera","vulchev","ilyduner@abv.bg", {1,2,3} };
	TEACHER t4 = { 3,"eren","grisha","jaeger","fighter@titan.bg", {1,2,3} };
	TEACHER t5 = { 4,"levi","kenny","ackermann","scouts@titan.com", {1,2,3} };

	STUDENT s1 = { 0,"georgi","georgiev","georgiev","10a","gg@abv.bg" };
	STUDENT s2 = { 1,"staiko","binev","pogriev","8a","sbp@abv.bg" };
	STUDENT s3 = { 2,"ivan","usrefov","milanov","9g","ium@abv.bg" };
	STUDENT s4 = { 3,"stoicho","breika","petrov","8g","sbp@abv.bg" };
	STUDENT s5 = { 4,"ivan","ivanov","ivanov","10b","iii@abv.bg" };
	STUDENT s6 = { 5,"mitko","mitkov","mitkov","9v","mmm@abv.bg" };

	TEAM te1 = { 0, "chupacabras","example description lorem eipsum take up space",{0,0,0},STATUS::pendingapproval,{{"gg@abv.bg", 1},{"sbp@abv.bg", 2}} };
	TEAM te2 = { 1, "anti-chupacabras","example description lorem eipsum take up space",{0,0,0},STATUS::pendingapproval,{{"ium@abv.bg", 1},{"sbp@abv.bg", 2}} };
	TEAM te3 = { 2, "we exist too","example description lorem eipsum take up space",{0,0,0},STATUS::pendingapproval,{{"iii@abv.bg", 1},{"mmm@abv.bg", 2}} };

	ROLE r1 = { 0, "scrum master" };
	ROLE r2 = { 1, "backend developer" };
	ROLE r3 = { 2, "frontend developer" };
	ROLE r4 = { 3, "qa" };
	ROLE r5 = { 4, "documentation" };

	vector <TEACHER> teachers{ t1, t2, t3, t4, t5 };
	vector <STUDENT> students{ s1,s2,s3,s4,s5,s6 };
	vector<TEAM> teams{ te1,te2,te3 };
	vector<ROLE> roles = { r1,r2,r3,r4,r5 };

	string name = "pgkpi";
	string city = "burgas";
	string address = "meden rudnik 54";

	school school{ 0,5, name, city, address, teachers, teams, students, roles };

	vector<school> schools;
	schools.push_back(school);
	schools.push_back(school);

	displayschools(schools);*/
}