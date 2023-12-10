#include "pch.h"
#include "Day1_2022.h"
#include "input_day1_2022.h"

TEST(TestDay01_2022, TestExample) {
	std::vector<std::string> input = {
	"1000",
	"2000",
	"3000",
	"",
	"4000",
	"",
	"5000",
	"6000",
	"",
	"7000",
	"8000",
	"9000",
	"",
	"10000" };
	Day1_2022 day1;
	EXPECT_EQ(day1.findMostCalories(input, false), 24000);
	EXPECT_EQ(day1.findMostCalories(input, true), 45000);
}

TEST(TestDay01_2022, Test1) {
	Day1_2022 day1;
	EXPECT_EQ(day1.findMostCalories(Input2022::day1_input, false), 70296);
}

TEST(TestDay01_2022, Test2) {
	Day1_2022 day1;
	EXPECT_EQ(day1.findMostCalories(Input2022::day1_input, true), 205381);
}