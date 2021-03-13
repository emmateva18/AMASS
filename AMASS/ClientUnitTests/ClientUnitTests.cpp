#include "pch.h"
#include "CppUnitTest.h"
#include "../Client/Presentation.h"
#include "../asio-1.18.1/include/asio.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
namespace ClientUnitTests
{
	TEST_CLASS(ClientUnitTests)
	{
	public:
		
		TEST_METHOD(ShouldReturnFalseIfStringConsisctsOfSomethingOtherThanLetter)
		{
			string testString = "test4$%45$%#45^&String";
			bool result;
			result = isStringInputValid(testString);
			Assert::AreEqual(false, result);
		}
		TEST_METHOD(ShouldReturnTrueIfStringDoesNotConsisctsOfSomethingOtherThanLetter)
		{
			string testString = "testString";
			bool result;
			result = isStringInputValid(testString);
			Assert::AreEqual(true, result);
		}
		TEST_METHOD(ShouldReturnTheCorrectCorrespondingStatusAsAString)
		{
			STATUS testStatus = inUse;
			string expectedResult = "In Use";
			string result = statusToString(testStatus);
			Assert::AreEqual(expectedResult, result);
		}
		TEST_METHOD(ShoulSuccessfullyReturnFullNameAsAString)
		{
			string expectedResult = "Ivan Ivanov Teodorov";
			string testFirstName = "Ivan";
			string testMiddleName = "Ivanov";
			string testLastName = "Teodorov";
			string result = nameToString(testFirstName, testMiddleName, testLastName);
			Assert::AreEqual(expectedResult, result);
		}
		TEST_METHOD(ShoulSuccessfullyReturnVectorOfIntsAsAString)
		{
			vector<int> testVector = { 1,2,3,4,5,6,7,8,9,10 };
			string result = vectorIntToString(testVector);
			string expectedResult = "1 2 3 4 5 6 7 8 9 10 ";
			Assert::AreEqual(expectedResult, result);
		}
		TEST_METHOD(ShoulSuccessfullyReturnDateAsAString)
		{
			DATE testDate;
			testDate.day = 1;
			testDate.month = 3;
			testDate.year = 1980;
			string result = dateOfSetupToString(testDate);
			string expectedResult = "1/3/1980";
			Assert::AreEqual(expectedResult, result);
		}
		TEST_METHOD(ShouldSuccedssfullyReturnStudentEmailsAsAString)
		{
			TEAM testTeam = { 0, "Chupacabras","example description lorem eipsum take up space",{0,0,0},STATUS::pendingApproval,{{"GG@abv.bg", 1},{"SBP@abv.bg", 2}} };
			string result = studentEmailsToString(testTeam);
			string expectedResult = "GG@abv.bg SBP@abv.bg ";
			Assert::AreEqual(expectedResult, result);
		}
		TEST_METHOD(ShouldSuccessfullyReturnTrueIfInTeamAsAString)
		{
			bool ifInTeam = true;
			string result = isInTeamToString(ifInTeam);
			string expectedResult = "true";
			Assert::AreEqual(expectedResult, result);
		}
		TEST_METHOD(ShouldSuccessfullyReturnFalseIfNotInTeamAsAString)
		{
			bool ifInTeam = false;
			string result = isInTeamToString(ifInTeam);
			string expectedResult = "false";
			Assert::AreEqual(expectedResult, result);
		}
	};
}
