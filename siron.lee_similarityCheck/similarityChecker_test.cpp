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

TEST_F(LengthFixture, TC01) {
	diagLength(60, "ABC", "ABC");
}

TEST_F(LengthFixture, TC02) {
	diagLength(30, "CDE", "AB");
}
TEST_F(LengthFixture, TC03) {
	diagLength(0, "AB", "ABCD");
}

