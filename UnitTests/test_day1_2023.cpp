#include "pch.h"
#include "Day1_2023.h"

TEST(TestDay01_2023, Test1) {
	Day1_2023 day1;
	EXPECT_EQ(day1.full(false), 55386);

	EXPECT_EQ(day1.lineValue("two1nine", true), 29);
	EXPECT_EQ(day1.lineValue("eightwothree", true), 83);
	EXPECT_EQ(day1.lineValue("abcone2threexyz", true), 13);
	EXPECT_EQ(day1.lineValue("xtwone3four", true), 24);
	EXPECT_EQ(day1.lineValue("4nineeightseven2", true), 42);
	EXPECT_EQ(day1.lineValue("zoneight234", true), 14);
	EXPECT_EQ(day1.lineValue("7pqrstsixteen", true), 76);
}

TEST(TestDay01_2023, Test2) {
	Day1_2023 day1;
	EXPECT_EQ(day1.full(true), 54824);
}
