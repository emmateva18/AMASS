#include "pch.h"
#include "CppUnitTest.h"
#include "../Server/Logic.h"
#include "../Client/Presentation.h"
#include "../CommunicationLibrary/CommunicationLibrary.h"
#include "../asio-1.18.1/include/asio.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace ServerUnitTests
{
	TEST_CLASS(ServerUnitTests)
	{
	public:

		TEST_METHOD(ShouldSuccessfullyUpdateStudentFirstName)
		{
			STUDENT testStudent = { 0,"Georgi","Georgiev","Georgiev","10A","GG@abv.bg" };
			string testFirstName = "Teodor";
			updateStudentFirstName(testStudent, testFirstName);
			Assert::AreEqual(testStudent.firstName, testFirstName);
		}
		TEST_METHOD(ShouldSuccessfullyUpdateStudentMiddleName)
		{
			STUDENT testStudent = { 0,"Georgi","Georgiev","Georgiev","10A","GG@abv.bg" };
			string testMiddleName = "Petrov";
			updateStudentMiddleName(testStudent, testMiddleName);
			Assert::AreEqual(testStudent.middleName, testMiddleName);
		}
		TEST_METHOD(ShouldSuccessfullyUpdateStudentSurname)
		{
			STUDENT testStudent = { 0,"Georgi","Georgiev","Georgiev","10A","GG@abv.bg" };
			string testSurname = "Ivanov";
			updateStudentSurname(testStudent, testSurname);
			Assert::AreEqual(testStudent.surname, testSurname);
		}
		TEST_METHOD(ShouldSuccessfullyUpdateStudentGrade)
		{
			STUDENT testStudent = { 0,"Georgi","Georgiev","Georgiev","10A","GG@abv.bg" };
			string testGrade = "10G";
			updateStudentGrade(testStudent, testGrade);
			Assert::AreEqual(testStudent.grade, testGrade);
		}
		TEST_METHOD(ShouldSuccessfullyUpdateStudentEmail)
		{
			STUDENT testStudent = { 0,"Georgi","Georgiev","Georgiev","10A","GG@abv.bg" };
			string testEmail = "gggeorgiev@abv.bg";
			updateStudentEmail(testStudent, testEmail);
			Assert::AreEqual(testStudent.email, testEmail);
		}
		TEST_METHOD(ShouldSuccessfullyUpdateTeacherFirstName)
		{
			TEACHER testTeacher = { 0,"Petur","Ognqnov","Georgiev","POGeorgiev@abv.bg" };
			string testFirstName = "Teodor";
			updateTeacherFirstName(testTeacher, testFirstName);
			Assert::AreEqual(testTeacher.firstName, testFirstName);
		}
		TEST_METHOD(ShouldSuccessfullyUpdateTeacherMiddleName)
		{
			TEACHER testTeacher = { 0,"Petur","Ognqnov","Georgiev","POGeorgiev@abv.bg" };
			string testMiddleName = "Ivanov";
			updateTeacherMiddleName(testTeacher, testMiddleName);
			Assert::AreEqual(testTeacher.middleName, testMiddleName);
		}
		TEST_METHOD(ShouldSuccessfullyUpdateTeacherSurname)
		{
			TEACHER testTeacher = { 0,"Petur","Ognqnov","Georgiev","POGeorgiev@abv.bg" };
			string testSurname = "Petrov";
			updateTeacherSurname(testTeacher, testSurname);
			Assert::AreEqual(testTeacher.surname, testSurname);
		}
		TEST_METHOD(ShouldSuccessfullyUpdateTeacherEmail)
		{
			TEACHER testTeacher = { 0,"Petur","Ognqnov","Georgiev","POGeorgiev@abv.bg" };
			string testEmail = "peturog@abv.bg";
			updateTeacherEmail(testTeacher, testEmail);
			Assert::AreEqual(testTeacher.email, testEmail);
		}
		TEST_METHOD(ShouldSuccessfullyUpdateTeacherTeamId)
		{
			TEACHER testTeacher = { 0,"Petur","Ognqnov","Georgiev","POGeorgiev@abv.bg",{0,1,2,3,4,5} };
			int testTeamIdIndex = 3;
			int testNewId = 6;
			updateTeamIdInTeacher(testTeacher, testTeamIdIndex, testNewId);
			Assert::AreEqual(testTeacher.teamIds[testTeamIdIndex], testNewId);
		}

		TEST_METHOD(ShouldSuccessfullyUpdateTeamName)
		{
			TEAM testTeam = { 0, "Chupacabras","example description lorem eipsum take up space",{0,0,0},STATUS::pendingApproval,{{"GG@abv.bg", 1},{"SBP@abv.bg", 2}} };
			string testTeamName = "AMASS";
			updateTeamName(testTeam, testTeamName);
			Assert::AreEqual(testTeam.name, testTeamName);
		}
		TEST_METHOD(ShouldSuccessfullyUpdateTeamDesc)
		{
			TEAM testTeam = { 0, "Chupacabras","example description lorem eipsum take up space",{0,0,0},STATUS::pendingApproval,{{"GG@abv.bg", 1},{"SBP@abv.bg", 2}} };
			string testTeamDesc = "Vivamus blandit tortor aliquam magna posuere auctor. ";
			updateTeamDesc(testTeam, testTeamDesc);
			Assert::AreEqual(testTeam.desc, testTeamDesc);
		}
		TEST_METHOD(ShouldSuccessfullyUpdateTeamStatus)
		{
			TEAM testTeam = { 0, "Chupacabras","example description lorem eipsum take up space",{0,0,0},STATUS::pendingApproval,{{"GG@abv.bg", 1},{"SBP@abv.bg", 2}} };
			STATUS testTeamStatus = pendingApproval;
			updateTeamStatus(testTeam, testTeamStatus);
			Assert::AreEqual(statusToString(testTeam.status), statusToString(testTeamStatus));
		}
		TEST_METHOD(ShouldSuccessfullyUpdateSchoolName)
		{
			SCHOOL testSchool = { 0,4,"PGKPI","Burgas","Meden Rudnik", {{ 0,"Petur","Ognqnov","Georgiev","POGeorgiev@abv.bg" }}, {{ 2, "We exist too","example description lorem eipsum take up space",{0,0,0},STATUS::pendingApproval,{{"III@abv.bg", 1},{"MMM@abv.bg", 2}}} },{{ 0,"Georgi","Georgiev","Georgiev","10A","GG@abv.bg" }},{{ 0, "Scrum Master" }} };
			string testSchoolName = "VCSPI";
			updateSchoolName(testSchool, testSchoolName);
			Assert::AreEqual(testSchool.name, testSchoolName);
		}
		TEST_METHOD(ShouldSuccessfullyUpdateSchoolCity)
		{
			SCHOOL testSchool = { 0,4,"PGKPI","Burgas","Meden Rudnik", {{ 0,"Petur","Ognqnov","Georgiev","POGeorgiev@abv.bg" }}, {{ 2, "We exist too","example description lorem eipsum take up space",{0,0,0},STATUS::pendingApproval,{{"III@abv.bg", 1},{"MMM@abv.bg", 2}}} },{{ 0,"Georgi","Georgiev","Georgiev","10A","GG@abv.bg" }},{{ 0, "Scrum Master" }} };
			string testSchoolCity = "Bourgas";
			updateSchoolCity(testSchool, testSchoolCity);
			Assert::AreEqual(testSchool.city, testSchoolCity);
		}
		TEST_METHOD(ShouldSuccessfullyUpdateSchoolAdress)
		{
			SCHOOL testSchool = { 0,4,"PGKPI","Burgas","Meden Rudnik", {{ 0,"Petur","Ognqnov","Georgiev","POGeorgiev@abv.bg" }}, {{ 2, "We exist too","example description lorem eipsum take up space",{0,0,0},STATUS::pendingApproval,{{"III@abv.bg", 1},{"MMM@abv.bg", 2}}} },{{ 0,"Georgi","Georgiev","Georgiev","10A","GG@abv.bg" }},{{ 0, "Scrum Master" }} };
			string testSchoolAdress = "Burgas Meden Rudnik";
			updateSchoolAdress(testSchool, testSchoolAdress);
			Assert::AreEqual(testSchool.address, testSchoolAdress);
		}
	};
}
