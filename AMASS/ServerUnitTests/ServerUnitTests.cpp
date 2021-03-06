#include "pch.h"
#include "CppUnitTest.h"
#include "../Server/Logic.h"
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

	};
}

