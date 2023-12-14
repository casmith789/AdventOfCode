#include "pch.h"
#include "Day7_2022.h"
#include "input_day7_2022.h"

TEST(TestDay07_2022, TestExample) {
    Day7_2022 day7;

    std::vector<std::string> example = {
"$ cd /",
"$ ls",
"dir a",
"14848514 b.txt",
"8504156 c.dat",
"dir d",
"$ cd a",
"$ ls",
"dir e",
"29116 f",
"2557 g",
"62596 h.lst",
"$ cd e",
"$ ls",
"584 i",
"$ cd ..",
"$ cd ..",
"$ cd d",
"$ ls",
"4060174 j",
"8033020 d.log",
"5626152 d.ext",
"7214296 k"
    };

    int64_t ans = day7.total(example, false);
    EXPECT_EQ(ans, 95437);
    ans = day7.total(example, true);
    EXPECT_EQ(ans, 24933642);
}

TEST(TestDay07_2022, Test1) {
    Day7_2022 day7;
    int64_t ans = day7.total(Input2022::day7_input, false);
    EXPECT_EQ(ans, 1297159);
}

TEST(TestDay07_2022, Test2) {
    Day7_2022 day7;
    int64_t ans = day7.total(Input2022::day7_input, true);
    EXPECT_EQ(ans, 3866390);
}