#include "pch.h"
#include "Day8_2022.h"
#include "input_day8_2022.h"

TEST(TestDay08_2022, TestExample) {
	Day8_2022 day8;

	std::vector<std::string> example = {
		"30373",
		"25512",
		"65332",
		"33549",
		"35390"
	};

	EXPECT_EQ(day8.numTreesUncovered(example), 21);
    EXPECT_EQ(day8.maxScenicScore(example), 8);
}

TEST(TestDay08_2022, Test1) {
	Day8_2022 day8;

    std::vector<std::vector<int>> uMap = day8.maxHeightUpIncludingThis(Input2022::day8_input);
    for (int j = 0; j < uMap[0].size(); ++j)
    {
        int lastVal = 0;
        for (int i = 0; i < uMap.size(); ++i)
        {
            EXPECT_GE(uMap[i][j], lastVal);
            lastVal = uMap[i][j];
        }
    }

    std::vector<std::vector<int>> dMap = day8.maxHeightDownIncludingThis(Input2022::day8_input);
    for (int j = 0; j < dMap[0].size(); ++j)
    {
        int lastVal = 9;
        for (int i = 0; i < dMap.size(); ++i)
        {
            EXPECT_LE(dMap[i][j], lastVal);
            lastVal = dMap[i][j];
        }
    }

    std::vector<std::vector<int>> lMap = day8.maxHeightLeftIncludingThis(Input2022::day8_input);
    for (int i = 0; i < lMap.size(); ++i)
    {
        int lastVal = 0;
        for (int j = 0; j < lMap[0].size(); ++j)
        {
            EXPECT_GE(lMap[i][j], lastVal);
            lastVal = lMap[i][j];
        }
    }

    std::vector<std::vector<int>> rMap = day8.maxHeightRightIncludingThis(Input2022::day8_input);
    for (int i = 0; i < rMap.size(); ++i)
    {
        int lastVal = 9;
        for (int j = 0; j < rMap[0].size(); ++j)
        {
            EXPECT_LE(rMap[i][j], lastVal);
            lastVal = rMap[i][j];
        }
    }


	// 4550 - too high
	// 1533 - too low (right for someone else)
	EXPECT_EQ(day8.numTreesUncovered(Input2022::day8_input), 1705);

}

TEST(TestDay08_2022, Test2) {
    Day8_2022 day8;
    EXPECT_EQ(day8.maxScenicScore(Input2022::day8_input), 371200);
}