#include "pch.h"
#include "Day8_2023.h"
#include "input_day8_2023.h"

TEST(TestDay08_2023, TestExamples) {
	Day8_2023 day8;

	std::string LRString = "RL";
	std::vector<std::string> example = {
		"AAA = (BBB, CCC)",
		"BBB = (DDD, EEE)",
		"CCC = (ZZZ, GGG)",
		"DDD = (DDD, DDD)",
		"EEE = (EEE, EEE)",
		"GGG = (GGG, GGG)",
		"ZZZ = (ZZZ, ZZZ)"
	};
	EXPECT_EQ(day8.numSteps(LRString, example, false), 2);

	LRString = "LLR";
	std::vector<std::string> example2 = {
		"AAA = (BBB, BBB)",
		"BBB = (AAA, ZZZ)",
		"ZZZ = (ZZZ, ZZZ)"
	};
	EXPECT_EQ(day8.numSteps(LRString, example2, false), 6);
}

TEST(TestDay08_2023, Test1) {
	Day8_2023 day8;
	EXPECT_EQ(day8.numSteps(Input2023::day8_LR_string, Input2023::day8_input_map, false), 12169);
}

TEST(TestDay08_2023, Test2) {
	Day8_2023 day8;
	EXPECT_EQ(day8.numSteps(Input2023::day8_LR_string, Input2023::day8_input_map, true), 12030780859469ll);
}