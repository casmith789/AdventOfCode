#include "pch.h"
#include "Day2_2023.h"

TEST(TestDay02_2023, Test1)
{
	Day2_2023 day2;
	EXPECT_EQ(day2.lineValue("Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green", false), 1);
	EXPECT_EQ(day2.lineValue("Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue", false), 2);
	EXPECT_EQ(day2.lineValue("Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red", false), 0);
	EXPECT_EQ(day2.lineValue("Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red", false), 0);
	EXPECT_EQ(day2.lineValue("Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green", false), 5);
	EXPECT_EQ(day2.lineValue("Game 100: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green", false), 100);

	EXPECT_EQ(day2.full(false), 2162);
}

TEST(TestDay02_2023, Test2)
{
	Day2_2023 day2;
	EXPECT_EQ(day2.lineValue("Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green", true), 48);
	EXPECT_EQ(day2.lineValue("Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue", true), 12);
	EXPECT_EQ(day2.lineValue("Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red", true), 1560);
	EXPECT_EQ(day2.lineValue("Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red", true), 630);
	EXPECT_EQ(day2.lineValue("Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green", true), 36);
	EXPECT_EQ(day2.lineValue("Game 100: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green", true), 36);

	EXPECT_EQ(day2.full(true), 72513);
}