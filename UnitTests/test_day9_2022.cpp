#include "pch.h"
#include "Day9_2022.h"
#include "input_day9_2022.h"

TEST(TestDay09_2022, Test1) {
    std::vector<std::string> example = {
"R 4",
"U 4",
"L 3",
"D 1",
"R 4",
"D 1",
"L 5",
"R 2"
    };
    Day9_2022 day9;
    EXPECT_EQ(1, 1);
    EXPECT_EQ(day9.numTailPositions(example, 1), 13);
    EXPECT_EQ(day9.numTailPositions(Input2022::day9_input, 1), 6212);
}

TEST(TestDay09_2022, Test2) {
    Day9_2022 day9;
    EXPECT_EQ(day9.numTailPositions(Input2022::day9_input, 9), 2522);
}