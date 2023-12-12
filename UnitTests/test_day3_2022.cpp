#include "pch.h"
#include "Day3_2022.h"
#include "input_day3_2022.h"

TEST(TestDay03_2022, Test1) {
	Day3_2022 day3;
	std::vector<std::string> example =
	{
"vJrwpWtwJgWrhcsFMMfFFhFp",
"jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL",
"PmmdzqPrVvPwwTWBwg",
"wMqvLMZHhHMvwLHjbvcjnnSBnvTQFn",
"ttgJtRGJQctTZtZT",
"CrZsJsPPZsGzwwsLwLmpwMDw"
	};

	EXPECT_EQ(day3.totalForAllP1(example), 157);
	EXPECT_EQ(day3.totalForAllP1(Input2022::day3_input), 7826);

	EXPECT_EQ(day3.totalForAllP2(example), 70);
	EXPECT_EQ(day3.totalForAllP2(Input2022::day3_input), 2577);
}

