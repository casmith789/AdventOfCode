#include "pch.h"
#include "Day5_2022.h"
#include "input_day5_2022.h"

TEST(TestDay05_2022, TestExample) {
    Day5_2022 day5;
    std::vector<std::string> stacksExample =
    {
"    [D]",
"[N] [C]",
"[Z] [M] [P]",
" 1   2   3"
    };

    std::vector<std::stack<char>> stacks = day5.getStacks(stacksExample);
    EXPECT_EQ(stacks[1].size(), 2);
    EXPECT_EQ(stacks[2].size(), 3);
    EXPECT_EQ(stacks[3].size(), 1);
    EXPECT_EQ(stacks[1].top(), 'N');
    EXPECT_EQ(stacks[2].top(), 'D');
    EXPECT_EQ(stacks[3].top(), 'P');

    std::vector<std::string> instructionsExample =
    {
        "move 1 from 2 to 1",
        "move 3 from 1 to 3",
        "move 2 from 2 to 1",
        "move 1 from 1 to 2"
    };
    std::vector<std::pair<int, std::pair<int, int>>> instructionsP1 = day5.getMoveMap(instructionsExample, false);
    std::vector<std::stack<char>> stacksP1 = day5.applyInstructions(stacks, instructionsP1);
    std::string ans = day5.getAnswer(stacksP1);
    EXPECT_EQ(ans, "CMZ");
    std::vector<std::pair<int, std::pair<int, int>>> instructionsP2 = day5.getMoveMap(instructionsExample, true);
    std::vector<std::stack<char>> stacksP2 = day5.applyInstructions(stacks, instructionsP2);
    ans = day5.getAnswer(stacksP2);
    EXPECT_EQ(ans, "MCD");
}

TEST(TestDay05_2022, Test1) {
    Day5_2022 day5;
    std::vector<std::stack<char>> stacks = day5.getStacks(Input2022::day5_stacks_input);
    EXPECT_EQ(stacks.size(), 10);
    std::vector<std::pair<int, std::pair<int, int>>> instructions = day5.getMoveMap(Input2022::day5_instructions_input, false);
    stacks = day5.applyInstructions(stacks, instructions);
    std::string ans = day5.getAnswer(stacks);
    EXPECT_EQ(ans, "FCVRLMVQP");
}

TEST(TestDay05_2022, Test2) {
    Day5_2022 day5;
    std::vector<std::stack<char>> stacks = day5.getStacks(Input2022::day5_stacks_input);
    EXPECT_EQ(stacks.size(), 10);
    std::vector<std::pair<int, std::pair<int, int>>> instructions = day5.getMoveMap(Input2022::day5_instructions_input, true);
    stacks = day5.applyInstructions(stacks, instructions);
    std::string ans = day5.getAnswer(stacks);
    EXPECT_EQ(ans, "RWLWGJGFD");
}

