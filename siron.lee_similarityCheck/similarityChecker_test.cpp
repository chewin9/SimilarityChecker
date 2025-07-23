#include "gmock/gmock.h"
#include "similarityChecker.cpp"
using namespace testing;
<<<<<<< Updated upstream

class LengthFixture : public Test {
public :
	LengthChecker app;

	void diagLength(int extpectedScore, string str1, string str2) {
		int actual = app.getLengthScore(str1, str2);
		EXPECT_EQ(extpectedScore, actual);
	}
};

TEST(TS, EXCEPTION01) {
	LengthChecker app;
	try {
		int ret = app.getLengthScore("", "");
		FAIL();
=======

class LengthFixture : public Test {
public :
	LengthChecker app;

	void diagLength(int extpectedScore, string str1, string str2) {
		int actual = app.getLengthScore(str1, str2);
		EXPECT_EQ(extpectedScore, actual);
>>>>>>> Stashed changes
	}
};

class ExceptionFixture : public Test {
public:
	LengthChecker app;
	void assertIllegalArguemnt(string str1, string str2) {
		try {
			app.getLengthScore(str1, str2);
			FAIL();
		}
		catch(exception e){

		}
	}
};

TEST_F(ExceptionFixture, EXCEPTIONNULL) {
	assertIllegalArguemnt("", "");
}
TEST_F(ExceptionFixture, EXCEPTIONPARAMETER) {
	assertIllegalArguemnt("123", "123");
	assertIllegalArguemnt("abc", "ab");
}

<<<<<<< Updated upstream
TEST(TS, EXCEPTION02) {
	LengthChecker app;
	try {
		int ret = app.getLengthScore("123", "123");
		FAIL();
	}
	catch (exception e) {
=======
>>>>>>> Stashed changes

TEST_F(LengthFixture, TC01) {
	diagLength(60, "ABC", "ABC");
}

<<<<<<< Updated upstream
TEST(TS, EXCEPTION03) {
	LengthChecker app;
	try {
		int ret = app.getLengthScore("abc", "ab");
		FAIL();
	}
	catch (exception e) {

	}
}

TEST_F(LengthFixture, TC01) {
	diagLength(60, "ABC", "ABC");
}

=======
>>>>>>> Stashed changes
TEST_F(LengthFixture, TC02) {
	diagLength(30, "CDE", "AB");
}
TEST_F(LengthFixture, TC03) {
	diagLength(0, "AB", "ABCD");
}

