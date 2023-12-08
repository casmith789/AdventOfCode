#include "pch.h"
#include "Day4_2023.h"

TEST(TestDay4_2023, Test1) {
	Day4_2023 day4;
	EXPECT_EQ(day4.lineValue("Card 1: 41 48 83 86 17 | 83 86  6 31 17  9 48 53", false), 8);
	EXPECT_EQ(day4.lineValue("Card 2: 13 32 20 16 61 | 61 30 68 82 17 32 24 19", false), 2);
	EXPECT_EQ(day4.lineValue("Card 3:  1 21 53 59 44 | 69 82 63 72 16 21 14  1", false), 2);
	EXPECT_EQ(day4.lineValue("Card 4: 41 92 73 84 69 | 59 84 76 51 58  5 54 83", false), 1);
	EXPECT_EQ(day4.lineValue("Card 5: 87 83 26 28 32 | 88 30 70 12 93 22 82 36", false), 0);
	EXPECT_EQ(day4.lineValue("Card 6: 31 18 13 56 72 | 74 77 10 23 35 67 36 11", false), 0);

	EXPECT_EQ(day4.full(Input2023::day4_input, false), 21919);

}

TEST(TestDay4_2023, Test2) {
	Day4_2023 day4;
	EXPECT_EQ(day4.lineValue("Card 1: 41 48 83 86 17 | 83 86  6 31 17  9 48 53", true), 4);
	EXPECT_EQ(day4.lineValue("Card 2: 13 32 20 16 61 | 61 30 68 82 17 32 24 19", true), 2);
	EXPECT_EQ(day4.lineValue("Card 3:  1 21 53 59 44 | 69 82 63 72 16 21 14  1", true), 2);
	EXPECT_EQ(day4.lineValue("Card 4: 41 92 73 84 69 | 59 84 76 51 58  5 54 83", true), 1);
	EXPECT_EQ(day4.lineValue("Card 5: 87 83 26 28 32 | 88 30 70 12 93 22 82 36", true), 0);
	EXPECT_EQ(day4.lineValue("Card 6: 31 18 13 56 72 | 74 77 10 23 35 67 36 11", true), 0);

	const std::vector<std::string> test_input =
	{
		"Card 1: 41 48 83 86 17 | 83 86  6 31 17  9 48 53",
		"Card 2: 13 32 20 16 61 | 61 30 68 82 17 32 24 19",
		"Card 3:  1 21 53 59 44 | 69 82 63 72 16 21 14  1",
		"Card 4: 41 92 73 84 69 | 59 84 76 51 58  5 54 83",
		"Card 5: 87 83 26 28 32 | 88 30 70 12 93 22 82 36",
		"Card 6: 31 18 13 56 72 | 74 77 10 23 35 67 36 11"
	};

	EXPECT_EQ(day4.full(test_input, true), 30);

	EXPECT_EQ(day4.full(Input2023::day4_input, true), 9881048);
}
