#include "pch.h"
#include "Day16_2023.h"
#include "input_day16_2023.h"

TEST(TestDay16_2023, TestExample) {
	Day16_2023 day16;

	std::vector<std::string> example = {
".|...@....",
"|.-.@.....",
".....|-...",
"........|.",
"..........",
".........@",
"..../.@@..",
".-.-/..|..",
".|....-|.@",
"..//.|...."
	};

	Day16_2023_LightBeam initial(0, 0, RIGHT);
	std::vector<Day16_2023_LightBeam> ans = day16.result(example, initial);
	std::set<std::pair<int, int>> energised = day16.energisedSquares(ans);
	day16.printEnergised(energised);
	EXPECT_EQ(energised.size(), 46);
}

TEST(TestDay16_2023, Test1) {
	Day16_2023 day16;
	Day16_2023_LightBeam initial(0, 0, RIGHT);
	std::vector<Day16_2023_LightBeam> ans = day16.result(Input2023::day16_input, initial);
	std::set<std::pair<int, int>> energised = day16.energisedSquares(ans);
	EXPECT_EQ(energised.size(), 7236);
}

TEST(TestDay16_2023, Test2) {
	Day16_2023 day16;

	std::vector<std::string> input = Input2023::day16_input;
	int xSize = input[0].size();
	int ySize = input.size();

	int maxEnergised = 0;
	for (int i = 0; i < xSize; ++i)
	{
		Day16_2023_LightBeam initial(i, 0, RIGHT);
		std::vector<Day16_2023_LightBeam> ans = day16.result(Input2023::day16_input, initial);
		std::set<std::pair<int, int>> energised = day16.energisedSquares(ans);
		if (energised.size() > maxEnergised)
		{
			maxEnergised = energised.size();
		}
	}

	for (int i = 0; i < xSize; ++i)
	{
		Day16_2023_LightBeam initial(i, xSize-1, LEFT);
		std::vector<Day16_2023_LightBeam> ans = day16.result(Input2023::day16_input, initial);
		std::set<std::pair<int, int>> energised = day16.energisedSquares(ans);
		if (energised.size() > maxEnergised)
		{
			maxEnergised = energised.size();
		}
	}

	for (int i = 0; i < ySize; ++i)
	{
		Day16_2023_LightBeam initial(0, i, DOWN);
		std::vector<Day16_2023_LightBeam> ans = day16.result(Input2023::day16_input, initial);
		std::set<std::pair<int, int>> energised = day16.energisedSquares(ans);
		if (energised.size() > maxEnergised)
		{
			maxEnergised = energised.size();
		}
	}

	for (int i = 0; i < ySize; ++i)
	{
		Day16_2023_LightBeam initial(0, ySize-1, UP);
		std::vector<Day16_2023_LightBeam> ans = day16.result(Input2023::day16_input, initial);
		std::set<std::pair<int, int>> energised = day16.energisedSquares(ans);
		if (energised.size() > maxEnergised)
		{
			maxEnergised = energised.size();
		}
	}
	EXPECT_EQ(maxEnergised, 7521);
}
