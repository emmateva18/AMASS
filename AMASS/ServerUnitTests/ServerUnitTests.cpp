#include "pch.h"
#include "CppUnitTest.h"
#include "../Server/Logic.h"
#include "../Client/Presentation.h"
#include "../CommunicationLibrary/CommunicationLibrary.h"
#include "../asio-1.18.1/include/asio.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ServerUnitTests
{
	TEST_CLASS(ServerUnitTests)
	{
	public:
	
		TEST_METHOD(ShouldSuccessfullyAddStudentIntoSchool)
		{
		SCHOOL testSchool;
		STUDENT testStudent = { 3,"Stoicho","Kirilov","Petrov","8G","SKP@abv.bg" };
		createStudent(testSchool, testStudent);
			Assert::AreEqual(testSchool.students[0].id, testStudent.id);
			Assert::AreEqual(testSchool.students[0].firstName, testStudent.firstName);
			Assert::AreEqual(testSchool.students[0].middleName, testStudent.middleName);
			Assert::AreEqual(testSchool.students[0].surname, testStudent.surname);
			Assert::AreEqual(testSchool.students[0].grade, testStudent.grade);
			Assert::AreEqual(testSchool.students[0].email, testStudent.email);
		}
		TEST_METHOD(ShouldSuccessfullyAddTeachertIntoSchool)
		{
			SCHOOL testSchool;

			TEACHER testTeacher = { 0,"Petur","Ognqnov","Georgiev","POGeorgiev@abv.bg",{1,2,5,4,8,6} };
			createTeacher(testSchool, testTeacher);
			Assert::AreEqual(testSchool.teachers[0].id, testTeacher.id);
			Assert::AreEqual(testSchool.teachers[0].firstName, testTeacher.firstName);
			Assert::AreEqual(testSchool.teachers[0].middleName, testTeacher.middleName);
			Assert::AreEqual(testSchool.teachers[0].surname, testTeacher.surname);
			Assert::AreEqual(testSchool.teachers[0].email, testTeacher.email);
			for (size_t i = 0; i < testTeacher.teamIds.size(); i++)
			{
				Assert::AreEqual(testSchool.teachers[0].teamIds[i], testTeacher.teamIds[i]);
			}
		}
		TEST_METHOD(ShouldSuccessfullyAddTeamIntoSchool)
		{
			SCHOOL testSchool;

			TEAM testTeam = { 1, "Anti-Chupacabras","example description lorem eipsum take up space",{0,0,0},STATUS::pendingApproval,{{"IUM@abv.bg", 1},{"SBP@abv.bg", 2}} };
			createTeam(testSchool, testTeam);
			Assert::AreEqual(testSchool.teams[0].id, testTeam.id);
			Assert::AreEqual(testSchool.teams[0].name, testTeam.name);
			Assert::AreEqual(testSchool.teams[0].desc, testTeam.desc);
			Assert::AreEqual(testSchool.teams[0].dateOfSetUp.day, testTeam.dateOfSetUp.day);
			Assert::AreEqual(testSchool.teams[0].dateOfSetUp.month, testTeam.dateOfSetUp.month);
			Assert::AreEqual(testSchool.teams[0].dateOfSetUp.year, testTeam.dateOfSetUp.year);
			Assert::AreEqual(statusToString(testSchool.teams[0].status), statusToString(testTeam.status));
			for (size_t i = 0; i < testTeam.members.size(); i++)
			{
				Assert::AreEqual(testSchool.teams[0].members[i].roleId, testTeam.members[i].roleId);
				Assert::AreEqual(testSchool.teams[0].members[i].studentEmail, testTeam.members[i].studentEmail);
			}
		}
	};
}

