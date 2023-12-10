#include "pch.h"
#include "Day9_2023.h"
#include "input_day9_2023.h"


TEST(TestDay9_2023, Test1) {
	Day9_2023 day9;
	EXPECT_EQ(day9.lineValue("0 3 6 9 12 15", false), 18);
	EXPECT_EQ(day9.lineValue("1 3 6 10 15 21", false), 28);
	EXPECT_EQ(day9.lineValue("10 13 16 21 30 45", false), 68);

	int64_t ret = day9.full(false);
	EXPECT_EQ(ret, 1972648895);
}

TEST(TestDay9_2023, Test2) {
	Day9_2023 day9;
	EXPECT_EQ(day9.lineValue("0 3 6 9 12 15", true), -3);
	EXPECT_EQ(day9.lineValue("1 3 6 10 15 21", true), 0);
	EXPECT_EQ(day9.lineValue("10 13 16 21 30 45", true), 5);

	int64_t ret = day9.full(true);
	EXPECT_EQ(ret, 919);
}


