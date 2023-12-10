#include "pch.h"
#include "Day2_2022.h"

TEST(TestDay02_2022, Test1) {
	Day2_2022 day2;
	std::vector<std::string> example =
	{
		"A Y",
		"B X",
		"C Z"
	};

	EXPECT_EQ(day2.full(example, false), 15);
	EXPECT_EQ(day2.full(Input2022::day2_input, false), 9651);

	EXPECT_EQ(day2.full(example, true), 12);
	EXPECT_EQ(day2.full(Input2022::day2_input, true), 10560);
}

