#include "pch.h"
#include "Day4_2022.h"
#include "input_day4_2022.h"

TEST(TestDay04_2022, Test1) {
	Day4_2022 day4;
	std::vector<std::string> example =
	{
"2-4,6-8",
"2-3,4-5",
"5-7,7-9",
"2-8,3-7",
"6-6,4-6",
"2-6,4-8"
	};

	EXPECT_EQ(day4.findNumEnclosed(example), 2);
	EXPECT_EQ(day4.findNumEnclosed(Input2022::day4_input), 507);

	EXPECT_EQ(day4.findNumOverlapping(example), 4);
	EXPECT_EQ(day4.findNumOverlapping(Input2022::day4_input), 897);
}

