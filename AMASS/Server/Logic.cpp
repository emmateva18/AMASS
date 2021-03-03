#include "Logic.h"

using namespace std;

//CRUD

void init(vector<SCHOOL>& schools)
{
	TEACHER t1 = { 1,"Petur","Ognqnov","Georgiev","POGeorgiev@abv.bg" };
	TEACHER t2 = { 2,"Gosho","Dizela","Petrov","dizela@gmail.com" };
	TEACHER t3 = { 3,"Vankata","Dunera","Vulchev","ILYDuner@abv.bg" };
	TEACHER t4 = { 4,"Eren","Grisha","Jaeger","fighter@titan.bg" };
	TEACHER t5 = { 5,"Levi","Kenny","Ackermann","scouts@titan.com" };

	STUDENT s1 = { 1,"Georgi","Georgiev","Georgiev","10A","GG@abv.bg" };
	STUDENT s2 = { 2,"Staiko","Binev","Pogriev","8A","SBP@abv.bg" };
	STUDENT s3 = { 3,"Ivan","Usrefov","Milanov","9G","IUM@abv.bg" };
	STUDENT s4 = { 4,"Stoicho","Breika","Petrov","8G","SBP@abv.bg" };
	STUDENT s5 = { 5,"Ivan","Ivanov","Ivanov","10B","III@abv.bg" };
	STUDENT s6 = { 6,"Mitko","Mitkov","Mitkov","9V","MMM@abv.bg" };

	TEAM te1 = { 0, "Chupacabras","example description lorem eipsum take up space",{0,0,0},STATUS::pendingApproval,{{"GG@abv.bg", 1},{"SBP@abv.bg", 2}} };
	TEAM te2 = { 1, "Anti-Chupacabras","example description lorem eipsum take up space",{0,0,0},STATUS::pendingApproval,{{"IUM@abv.bg", 1},{"SBP@abv.bg", 2}} };
	TEAM te3 = { 2, "We exist too","example description lorem eipsum take up space",{0,0,0},STATUS::pendingApproval,{{"III@abv.bg", 1},{"MMM@abv.bg", 2}} };

	vector <TEACHER> teachers{ t1, t2, t3, t4, t5 };
	vector <STUDENT> students{ s1,s2,s3,s4,s5,s6 };
	vector<TEAM> teams{ te1,te2,te3 };

	string name = "PGKPI";
	string city = "Burgas";
	string address = "Meden Rudnik 54";

	SCHOOL school{ 1,name,city,address,teachers,teams,students };

	schools.push_back(school);
}

void createSchool(vector<SCHOOL>& schools, SCHOOL school)
{
	schools.push_back(school);
	//saveData(schools);
}