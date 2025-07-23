#include"gmock/gmock.h"
#include"similarityChecker.cpp"

TEST(TS, EXCEPTION01) {
	LenghChecker app;
	try {
		int ret = app.getPoint("", "");
		FAIL();
	}
	catch (exception e){

	}
}

TEST(TS, EXCEPTION02) {
	LenghChecker app;
	try {
		int ret = app.getPoint("123", "123");
		FAIL();
	}
	catch (exception e) {

	}
}

TEST(TS, EXCEPTION03) {
	LenghChecker app;
	try {
		int ret = app.getPoint("abc", "ab");
		FAIL();
	}
	catch (exception e) {

	}
}

TEST(TS, TC01) {
	LenghChecker app;
	int ret = app.getPoint("ABC", "ABC");
	EXPECT_EQ(60, ret);
}

TEST(TS, TC02) {
	LenghChecker app;
	int ret = app.getPoint("CDE", "AB");
	EXPECT_EQ(30, ret);
}
TEST(TS, TC03) {
	LenghChecker app;
	int ret = app.getPoint("AB", "ABC");
	EXPECT_EQ(30, ret);
}
TEST(TS, TC04) {
	LenghChecker app;
	int ret = app.getPoint("AB", "ABCD");
	EXPECT_EQ(0, ret);
}

