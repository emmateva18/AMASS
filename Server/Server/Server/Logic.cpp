#include "Logic.h"
#include "Structures.h"
using namespace std;

//CRUD

void init(vector<SCHOOL>& schools)
{
	TEACHER t1 = { "Petur","Ognqnov","Georgiev","POGeorgiev@abv.bg",{} };
	TEACHER t2 = { "Gosho","Dizela","Petrov","dizela@gmail.com",{} };
	TEACHER t3 = { "Vankata","Dunera","Vulchev","ILYDuner@abv.bg",{} };
	TEACHER t4 = { "Eren","Grisha","Jaeger","fighter@titan.bg",{} };
	TEACHER t5 = { "Levi","Kenny","Ackermann","scouts@titan.com",{} };

	STUDENT s1 = { "Georgi","Georgiev","Georgiev","10A","GG@abv.bg" };
	STUDENT s2 = { "Staiko","Binev","Pogriev","8A","SBP@abv.bg" };
	STUDENT s3 = { "Ivan","Usrefov","Milanov","9G","IUM@abv.bg" };
	STUDENT s4 = { "Stoicho","Breika","Petrov","8G","SBP@abv.bg" };
	STUDENT s5 = { "Ivan","Ivanov","Ivanov","10B","III@abv.bg" };
	STUDENT s6 = { "Mitko","Mitkov","Mitkov","9V","MMM@abv.bg" };

	TEAM te1 = { "Chupacabras","example description lorem eipsum take up space",{0,0,0},Status::pendingApproval,{s1,s2} };
	TEAM te2 = { "Anti-Chupacabras","example description lorem eipsum take up space",{0,0,0},Status::pendingApproval,{s3,s4} };
	TEAM te3 = { "We exist too","example description lorem eipsum take up space",{0,0,0},Status::pendingApproval,{s5,s6} };

	vector <TEACHER> teachers {t1, t2, t3, t4, t5};
	vector <STUDENT> students{ s1,s2,s3,s4,s5,s6 };
	vector<TEAM> teams { te1,te2,te3 };

	string name = "PGKPI";
	string city = "Burgas";
	string address = "Meden Rudnik 54";

	SCHOOL school{ name,city,address,teachers,teams,students };

	schools.push_back(school);
}

void createSchool(vector<SCHOOL>& schools,SCHOOL school)
{
	schools.push_back(school);
	//saveData(schools);
}