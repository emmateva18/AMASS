#include <iostream>
#include "ClientConnection.h"
#include "Presentation.h"
#include "Menu.h"
using namespace std;
int main()
{
	/*vector<MENU> menus = initMenus();
	int selectedIndex = 0;
	menus[0].showMenuItems();
	getUserInput(menus);*/

	TEACHER t1 = { 0,"Petur","Ognqnov","Georgiev","POGeorgiev@abv.bg", {1,2,3} };
	TEACHER t2 = { 1,"Gosho","Dizela","Petrov","dizela@gmail.com", {1,2,3} };
	TEACHER t3 = { 2,"Vankata","Dunera","Vulchev","ILYDuner@abv.bg", {1,2,3} };
	TEACHER t4 = { 3,"Eren","Grisha","Jaeger","fighter@titan.bg", {1,2,3} };
	TEACHER t5 = { 4,"Levi","Kenny","Ackermann","scouts@titan.com", {1,2,3} };

	STUDENT s1 = { 0,"Georgi","Georgiev","Georgiev","10A","GG@abv.bg" };
	STUDENT s2 = { 1,"Staiko","Binev","Pogriev","8A","SBP@abv.bg" };
	STUDENT s3 = { 2,"Ivan","Usrefov","Milanov","9G","IUM@abv.bg" };
	STUDENT s4 = { 3,"Stoicho","Breika","Petrov","8G","SBP@abv.bg" };
	STUDENT s5 = { 4,"Ivan","Ivanov","Ivanov","10B","III@abv.bg" };
	STUDENT s6 = { 5,"Mitko","Mitkov","Mitkov","9V","MMM@abv.bg" };

	TEAM te1 = { 0, "Chupacabras","example description lorem eipsum take up space",{0,0,0},STATUS::pendingApproval,{{"GG@abv.bg", 1},{"SBP@abv.bg", 2}} };
	TEAM te2 = { 1, "Anti-Chupacabras","example description lorem eipsum take up space",{0,0,0},STATUS::pendingApproval,{{"IUM@abv.bg", 1},{"SBP@abv.bg", 2}} };
	TEAM te3 = { 2, "We exist too","example description lorem eipsum take up space",{0,0,0},STATUS::pendingApproval,{{"III@abv.bg", 1},{"MMM@abv.bg", 2}} };

	ROLE r1 = { 0, "Scrum Master" };
	ROLE r2 = { 1, "Backend Developer" };
	ROLE r3 = { 2, "Frontend Developer" };
	ROLE r4 = { 3, "QA" };
	ROLE r5 = { 4, "Documentation" };

	vector <TEACHER> teachers{ t1, t2, t3, t4, t5 };
	vector <STUDENT> students{ s1,s2,s3,s4,s5,s6 };
	vector<TEAM> teams{ te1,te2,te3 };
	vector<ROLE> roles = { r1,r2,r3,r4,r5 };

	string name = "PGKPI";
	string city = "Burgas";
	string address = "Meden Rudnik 54";

	SCHOOL school{ 0,5, name, city, address, teachers, teams, students, roles };

	vector<SCHOOL> schools;
	schools.push_back(school);
	schools.push_back(school);

	displaySchools(schools);
}