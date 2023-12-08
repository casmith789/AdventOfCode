#include "pch.h"
#include "Day3_2023.h"
#include "input_day3_2023.h"

TEST(TestDay3_2023, Test1)
{
	std::vector<std::string> test_data = {
		"467..114..",
		"...*......",
		"..35..633.",
		"......#...",
		"617*......",
		".....+.58.",
		"..592.....",
		"......755.",
		"...$.*....",
		".664.598..",
	};

	Day3_2023 day3;
	long ans = day3.full(test_data, false);
	EXPECT_EQ(ans, 4361);
}


TEST(TestDay3_2023, TestNoSymbols)
{
	std::vector<std::string> test_data = {
		".....",
		".467.",
		"....."
	};

	Day3_2023 day3;
	long ans = day3.full(test_data, false);
	EXPECT_EQ(ans, 0);
}

TEST(TestDay3_2023, TestTopLeft)
{
	std::vector<std::string> test_data = {
		"&....",
		".467.",
		"....."
	};

	Day3_2023 day3;
	long ans = day3.full(test_data, false);
	EXPECT_EQ(ans, 467);
}

TEST(TestDay3_2023, TestTopRight)
{
	std::vector<std::string> test_data = {
		"....*",
		".467.",
		"....."
	};

	Day3_2023 day3;
	long ans = day3.full(test_data, false);
	EXPECT_EQ(ans, 467);
}

TEST(TestDay3_2023, TestBottomRight)
{
	std::vector<std::string> test_data = {
		".....",
		".467.",
		"....)"
	};

	Day3_2023 day3;
	long ans = day3.full(test_data, false);
	EXPECT_EQ(ans, 467);
}

TEST(TestDay3_2023, TestBottomLeft)
{
	std::vector<std::string> test_data = {
		".....",
		".467.",
		"^...."
	};

	Day3_2023 day3;
	long ans = day3.full(test_data, false);
	EXPECT_EQ(ans, 467);
}

TEST(TestDay3_2023, TestLeft)
{
	std::vector<std::string> test_data = {
		".....",
		"#467.",
		"....."
	};

	Day3_2023 day3;
	long ans = day3.full(test_data, false);
	EXPECT_EQ(ans, 467);
}

TEST(TestDay3_2023, TestRight)
{
	std::vector<std::string> test_data = {
		".....",
		".467%",
		"....."
	};

	Day3_2023 day3;
	long ans = day3.full(test_data, false);
	EXPECT_EQ(ans, 467);
}

TEST(TestDay3_2023, TestFull1)
{
	std::vector<std::string> test_data = Input2023::day3_input;
	Day3_2023 day3;
	long ans = day3.full(test_data, false);
	EXPECT_EQ(ans, 520019);
}

TEST(TestDay3_2023, TestFourOneSymbol)
{
	std::vector<std::string> test_data = {
		"....9",
		".467%73",
		"...8."
	};

	Day3_2023 day3;
	long ans = day3.full(test_data, false);
	EXPECT_EQ(ans, 557);
}

TEST(TestDay3_2023, TestEndOfLine)
{
	std::vector<std::string> test_data = {
		"...@9",
		"....."
	};

	Day3_2023 day3;
	long ans = day3.full(test_data, false);
	EXPECT_EQ(ans, 9);
}

TEST(TestDay3_2023, TestStartOfLine)
{
	std::vector<std::string> test_data = {
		"12*...",
		"....."
	};

	Day3_2023 day3;
	long ans = day3.full(test_data, false);
	EXPECT_EQ(ans, 12);
}

TEST(TestDay3_2023, TestLastRow)
{
	std::vector<std::string> test_data = {
		"//..~",
		"...3."
	};

	Day3_2023 day3;
	long ans = day3.full(test_data, false);
	EXPECT_EQ(ans, 3);
}

TEST(TestDay3_2023, TestFirstThree)
{
	std::vector<std::string> test_data = {
"..975..95..................717..........................................747................................................622..............",
"................/47...........@....701...610.........252.660*.............*..236.....323..........108........653............................",
".......69............313..............$...$...*....@.........640........81.....*................................*332..92...................."
	};

	Day3_2023 day3;
	long ans = day3.full(test_data, false);
	EXPECT_EQ(ans, 5424);
}

TEST(TestDay3_2023, TestFindNumberOfAdjacent)
{
	std::vector<std::set<int>> test;
	std::set<int> zero;
	test.push_back(zero);
	std::set<int> one;
	one.insert(1);
	one.insert(2);
	one.insert(3);
	test.push_back(one);
	std::set<int> two;
	two.insert(1);
	two.insert(3);
	test.push_back(two);
	std::set<int> three;
	three.insert(1);
	three.insert(2);
	three.insert(3);
	test.push_back(three);

	Day3_2023 day3;
	int numAdjacent = day3.findNumberOfAdjacent(test, 2, 2);
	EXPECT_EQ(numAdjacent, 4);
	numAdjacent = day3.findNumberOfAdjacent(test, 0, 2);
	EXPECT_EQ(numAdjacent, 1);
	numAdjacent = day3.findNumberOfAdjacent(test, 1, 2);
	EXPECT_EQ(numAdjacent, 4);
}

TEST(TestDay3_2023, Test2)
{
	std::vector<std::string> test_data = {
		"467..114..",
		"...*......",
		"..35..633.",
		"......#...",
		"617*......",
		".....+.58.",
		"..592.....",
		"......755.",
		"...$.*....",
		".664.598..",
	};

	Day3_2023 day3;
	long ans = day3.full(test_data, true);
	EXPECT_EQ(ans, 467835);
}

TEST(TestDay3_2023, TestGears2)
{
	std::vector<std::string> test_data = {
		"467..114..",
		"...*......",
		"..35..633.",
		"......#...",
		"617*......",
		".....+.58.",
		"..592.....",
		"......755.",
		"...$.*....",
		".664.598..",
	};

	Day3_2023 day3;
	std::vector<std::set<int>> numValuesVec;
	std::vector<std::set<int>> symbolsVec;
	std::vector<std::set<int>> allGears = day3.GetGears(test_data, numValuesVec, symbolsVec);
	EXPECT_EQ(allGears[1].find(3) != allGears[1].end(), true);
	EXPECT_EQ(allGears[8].find(5) != allGears[8].end(), true);
}



TEST(TestDay3_2023, TestFull2)
{
	std::vector<std::string> test_data = Input2023::day3_input;
	Day3_2023 day3;
	long ans = day3.full(test_data, true);
	EXPECT_EQ(ans, 75519888);
}