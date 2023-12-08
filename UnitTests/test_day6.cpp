#include "pch.h"
#include "Day6_2023.h"

TEST(TestDay6_2023, Test1) {
	Day6_2023 day6;
	EXPECT_EQ(day6.calc(7, 9), 4);
	EXPECT_EQ(day6.calc(15, 40), 8);
	EXPECT_EQ(day6.calc(30, 200), 9);
	EXPECT_EQ(day6.example(), 288);
	EXPECT_EQ(day6.full(), 608902);
}

TEST(TestDay6_2023, Test2)
{
	Day6_2023 day6;
	EXPECT_EQ(day6.calc(55826490, 246144110121111ll), 46173809);
}