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
		TEST_METHOD(ShouldSuccessfullyAddSchool)
		{
			std::vector<SCHOOL> schools;
			SCHOOL testSchool = { 0,4,"PGKPI","Burgas","Meden Rudnik", {{ 0,"Petur","Ognqnov","Georgiev","POGeorgiev@abv.bg" }}, {{ 2, "We exist too","example description lorem eipsum take up space",{0,0,0},STATUS::pendingApproval,{{"III@abv.bg", 1},{"MMM@abv.bg", 2}}} },{{ 0,"Georgi","Georgiev","Georgiev","10A","GG@abv.bg" }},{{ 0, "Scrum Master" }} };
			createSchool(schools, testSchool);
			for (size_t i = 0; i < schools.size(); i++)
			{
				Assert::AreEqual(schools[0].id, testSchool.id);
				Assert::AreEqual(schools[0].maxMemberCountPerTeam, testSchool.maxMemberCountPerTeam);
				Assert::AreEqual(schools[0].name, testSchool.name);
				Assert::AreEqual(schools[0].city, testSchool.city);
				Assert::AreEqual(schools[0].address, testSchool.address);

				// Test teachers
				for (size_t i = 0; i < testSchool.teachers.size(); i++)
				{
					Assert::AreEqual(schools[0].teachers[i].id, testSchool.teachers[i].id);
					Assert::AreEqual(schools[0].teachers[i].firstName, testSchool.teachers[i].firstName);
					Assert::AreEqual(schools[0].teachers[i].middleName, testSchool.teachers[i].middleName);
					Assert::AreEqual(schools[0].teachers[i].surname, testSchool.teachers[i].surname);
					Assert::AreEqual(schools[0].teachers[i].email, testSchool.teachers[i].email);

					// Test teams for teachers
					for (size_t j = 0; j < testSchool.teachers[i].teamIds.size(); j++)
					{
						Assert::AreEqual(schools[0].teachers[i].teamIds[j], testSchool.teachers[i].teamIds[j]);
					}
				}

				// Test teams
				for (size_t i = 0; i < testSchool.teams.size(); i++)
				{
					Assert::AreEqual(schools[0].teams[i].id, testSchool.teams[i].id);
					Assert::AreEqual(schools[0].teams[i].name, testSchool.teams[i].name);
					Assert::AreEqual(schools[0].teams[i].dateOfSetUp.day, testSchool.teams[i].dateOfSetUp.day);
					Assert::AreEqual(schools[0].teams[i].dateOfSetUp.month, testSchool.teams[i].dateOfSetUp.month);
					Assert::AreEqual(schools[0].teams[i].dateOfSetUp.year, testSchool.teams[i].dateOfSetUp.year);
					Assert::AreEqual(statusToString(schools[0].teams[0].status), statusToString(testSchool.teams[i].status));

					//Test members in team
					for (size_t j = 0; j < testSchool.teams[i].members.size(); j++)
					{
						Assert::AreEqual(schools[0].teams[i].members[j].studentEmail, testSchool.teams[i].members[j].studentEmail);
						Assert::AreEqual(schools[0].teams[i].members[j].roleId, testSchool.teams[i].members[j].roleId);
					}
				}

				// Test students
				for (size_t i = 0; i < testSchool.students.size(); i++)
				{
					Assert::AreEqual(schools[0].students[i].id, testSchool.students[i].id);
					Assert::AreEqual(schools[0].students[i].firstName, testSchool.students[i].firstName);
					Assert::AreEqual(schools[0].students[i].middleName, testSchool.students[i].middleName);
					Assert::AreEqual(schools[0].students[i].surname, testSchool.students[i].surname);
					Assert::AreEqual(schools[0].students[i].grade, testSchool.students[i].grade);
					Assert::AreEqual(schools[0].students[i].email, testSchool.students[i].email);
					Assert::AreEqual(schools[0].students[i].isInTeam, testSchool.students[i].isInTeam);
				}

				//Test roles
				for (size_t i = 0; i < testSchool.roles.size(); i++)
				{
					Assert::AreEqual(schools[0].roles[i].id, testSchool.roles[i].id);
					Assert::AreEqual(schools[0].roles[i].name, testSchool.roles[i].name);
				}
			}
		}
		TEST_METHOD(ShouldSuccessfullyDeleteStudentFromSchool)
		{
			SCHOOL testSchool;
			STUDENT testStudent1 = { 3,"Stoicho","Kirilov","Petrov","8G","SKP@abv.bg" };
			STUDENT testStudent2 = { 0,"Georgi","Georgiev","Georgiev","10A","GG@abv.bg" };
			createStudent(testSchool, testStudent2);
			createStudent(testSchool, testStudent1);
			deleteStudent(testSchool, testStudent1.id);

			for (size_t i = 0; i < testSchool.students.size(); i++)
			{
				Assert::AreNotEqual(testSchool.students[i].id, testStudent1.id);
				Assert::AreNotEqual(testSchool.students[i].firstName, testStudent1.firstName);
				Assert::AreNotEqual(testSchool.students[i].middleName, testStudent1.middleName);
				Assert::AreNotEqual(testSchool.students[i].surname, testStudent1.surname);
				Assert::AreNotEqual(testSchool.students[i].grade, testStudent1.grade);
				Assert::AreNotEqual(testSchool.students[i].email, testStudent1.email);
			}

		}
		TEST_METHOD(ShouldSuccessfullyDeleteTeacherFromSchool)
		{
			SCHOOL testSchool;
			TEACHER testTeacher1 = { 0,"Petur","Ognqnov","Georgiev","POGeorgiev@abv.bg" };
			TEACHER testTeacher2 = { 1,"Gosho","Dimitrov","Petrov","dimitrov@gmail.com" };
			createTeacher(testSchool, testTeacher2);
			createTeacher(testSchool, testTeacher1);
			deleteTeacher(testSchool, testTeacher1.id);

			for (size_t i = 0; i < testSchool.teachers.size(); i++)
			{
				Assert::AreNotEqual(testSchool.teachers[i].id, testTeacher1.id);
				Assert::AreNotEqual(testSchool.teachers[i].email, testTeacher1.email);
			}

		}
		TEST_METHOD(ShouldSuccessfullyDeleteTeamFromSchool)
		{
			SCHOOL testSchool;
			TEAM testTeam1 = { 0, "Chupacabras","example 1 description lorem eipsum take up space",{1,2,2020},STATUS::pendingApproval,{{"GG@abv.bg", 1},{"SBP@abv.bg", 2}} };
			TEAM testTeam2 = { 1, "Anti-Chupacabras","example 2 description lorem eipsum take up space",{2,3,2019},STATUS::inUse,{{"IUM@abv.bg", 1},{"SBP@abv.bg", 2}} };
			createTeam(testSchool, testTeam2);
			createTeam(testSchool, testTeam1);
			deleteTeam(testSchool, testTeam1.id);

			for (size_t i = 0; i < testSchool.teams.size(); i++)
			{
				Assert::AreNotEqual(testSchool.teams[i].id, testTeam1.id);
				Assert::AreNotEqual(testSchool.teams[i].name, testTeam1.name);

			}
		}
		TEST_METHOD(ShouldSuccessfullyDeleteRolesFromSchool)
		{
			SCHOOL testSchool;
			ROLE testRole1 = { 0, "Scrum Master" };
			ROLE testRole2 = { 1, "Backend Developer" };
			createRole(testSchool, testRole2);
			createRole(testSchool, testRole1);
			deleteRoles(testSchool, testRole1.id);

			for (size_t i = 0; i < testSchool.roles.size(); i++)
			{
				Assert::AreNotEqual(testSchool.roles[i].id, testRole1.id);
				Assert::AreNotEqual(testSchool.roles[i].name, testRole1.name);

			}
		}
		TEST_METHOD(ShouldSuccessfullyDeleteSchool)
		{
			std::vector<SCHOOL> schools;
			SCHOOL testSchool1 = { 0,4,"PGKPI","Burgas","Meden Rudnik", {{ 0,"Petur","Ognqnov","Georgiev","POGeorgiev@abv.bg" }}, {{ 2, "We exist too","example description lorem eipsum take up space",{0,0,0},STATUS::pendingApproval,{{"III@abv.bg", 1},{"MMM@abv.bg", 2}}} },{{ 0,"Georgi","Georgiev","Georgiev","10A","GG@abv.bg" }},{{ 0, "Scrum Master" }} };
			SCHOOL testSchool2 = { 1,4,"PMG","Burgas","Centur", {{ 0,"Petur","Stoynov","Ivanov","PSIvanov@abv.bg" }}, { { 1, "Anti-Chupacabras","example description lorem eipsum take up space",{0,0,0},STATUS::pendingApproval,{{"IUM@abv.bg", 1},{"SBP@abv.bg", 2}} } },{{ 4,"Ivan","Ivanov","Ivanov","10B","III@abv.bg" }},{{ 1, "Backend Developer" }} };
			createSchool(schools, testSchool2);
			createSchool(schools, testSchool1);
			deleteSchool(schools, testSchool1.id);
			for (size_t i = 0; i < schools.size(); i++)
			{
				Assert::AreNotEqual(schools[i].id, testSchool1.id);
				Assert::AreNotEqual(schools[i].name, testSchool1.name);
			}
		}
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

	};
}
