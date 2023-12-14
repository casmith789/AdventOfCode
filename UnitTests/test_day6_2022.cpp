#include "pch.h"
#include "Day6_2022.h"
#include "input_day6_2022.h"

TEST(TestDay06_2022, Test1) {
    Day6_2022 day6;
    std::string ex("mjqjpqmgbljsphdztnvjfqwrcgsmlb");
    EXPECT_EQ(day6.ans(ex, 4), 7);

    EXPECT_EQ(day6.ans(Input2022::day6_input, 4), 1343);

    EXPECT_EQ(day6.ans(Input2022::day6_input, 14), 2193);
}

