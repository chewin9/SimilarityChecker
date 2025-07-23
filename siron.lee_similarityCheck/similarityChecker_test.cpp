#include "gmock/gmock.h"
#include "similarityChecker.cpp"
using namespace testing;

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
	}
	catch (exception e){

	}
}

TEST(TS, EXCEPTION02) {
	LengthChecker app;
	try {
		int ret = app.getLengthScore("123", "123");
		FAIL();
	}
	catch (exception e) {

	}
}

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

TEST_F(LengthFixture, TC02) {
	diagLength(30, "CDE", "AB");
}
TEST_F(LengthFixture, TC03) {
	diagLength(0, "AB", "ABCD");
}

