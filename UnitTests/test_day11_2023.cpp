#include "pch.h"
#include "Day11_2023.h"
#include "input_day11_2023.h"

TEST(TestDay11_2023, TestExample) {
	Day11_2023 day11;
	std::vector<std::string> example = {
		"...#......",
		".......#..",
		"#.........",
		"..........",
		"......#...",
		".#........",
		".........#",
		"..........",
		".......#..",
		"#...#....."
	};

	EXPECT_EQ(example.size(), 10);
	EXPECT_EQ(example[0].length(), 10);

	std::vector<std::string> expanded = day11.expandedInput(example, 2);
	EXPECT_EQ(expanded.size(), 12);
	EXPECT_EQ(expanded[0].length(), 13);

	EXPECT_EQ(day11.findTotalDistance(expanded), 374);

	EXPECT_EQ(day11.findTotalDistance(example, 2), 374);
	EXPECT_EQ(day11.findTotalDistance(example, 10), 1030);
	EXPECT_EQ(day11.findTotalDistance(example, 100), 8410);
}

TEST(TestDay11_2023, Test1) {
	Day11_2023 day11;
	std::vector<std::string> expanded = day11.expandedInput(Input2023::day11_input, 2);
	EXPECT_EQ(day11.findTotalDistance(expanded), 10231178);
}

TEST(TestDay11_2023, Test2) {
	Day11_2023 day11;
	EXPECT_EQ(day11.findTotalDistance(Input2023::day11_input, 1000000), 622120986954ll);
	
}