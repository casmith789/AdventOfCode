#include "pch.h"
#include "Day14_2023.h"
#include "input_day14_2023.h"

TEST(TestDay14_2023, TestExample) {
    Day14_2023 day14;

    std::vector<std::string> example = {
    "O....#....",
    "O.OO#....#",
    ".....##...",
    "OO.#O....O",
    ".O.....O#.",
    "O.#..O.#.#",
    "..O..#O..O",
    ".......O..",
    "#....###..",
    "#OO..#...."
    };

    std::vector<std::string> input = day14.moveAllIterationsNorth(example);
    int64_t ans = day14.countTotalScore(input);
    EXPECT_EQ(ans, 136);
    
    std::vector<std::string> example2 = {
    "OOOO.#.O..",
    "OO..#....#",
    "OO..O##..O",
    "O..#.OO...",
    "........#.",
    "..#....#.#",
    "..O..#.O.O",
    "..O.......",
    "#....###..",
    "#....#...."
    };
    std::vector<std::string> output;
    for (std::string line : input)
    {
        Util::replaceAll(line, "@", "O");
        output.push_back(line);
    }
    EXPECT_EQ(output, example2);

    std::vector<std::string> example2EastRotated =
    {
    "##....OOOO",
    ".......OOO",
    "..OO#....O",
    "......#..O",
    ".......O#.",
    "##.#..O#.#",
    ".#....O#..",
    ".#.O#....O",
    ".....#....",
    "...O#..O#."
    };

    std::vector<std::string> output2 = day14.rotateWholeInputEast(example2);
    EXPECT_EQ(output2, example2EastRotated);


    std::vector<std::string> example3 = {
".....#....",
"....#...O#",
"...OO##...",
".OO#......",
".....OOO#.",
".O#...O#.#",
"....O#....",
"......OOOO",
"#...O###..",
"#..OO#...."
    };

    std::vector<std::string> spinCycle1 = day14.spinCycle(example);
    EXPECT_EQ(spinCycle1, example3);


}

TEST(TestDay14_2023, Test1) {
    Day14_2023 day14;

    std::vector<std::string> input2 = day14.moveAllIterationsNorth(Input2023::day14_input);
    int64_t ans2 = day14.countTotalScore(input2);
    EXPECT_EQ(ans2, 109939);
}

TEST(TestDay14_2023, Test2) {
    Day14_2023 day14;

    std::map<std::vector<std::string>, int64_t> diffMap;

    std::vector<std::string> input = Input2023::day14_input;
    int64_t iteration = 0;
    while (diffMap.find(input) == diffMap.end())
    {
        diffMap[input] = iteration;
        input = day14.spinCycle(input);
        ++iteration;
    }

    int64_t firstFind = diffMap[input];
    int64_t secondFind = iteration;

    int64_t cycleLength = secondFind - firstFind;

    int64_t equivOneBilCycles = (1000000000ll - firstFind) % cycleLength;
    for (std::pair a : diffMap)
    {
        if (a.second == equivOneBilCycles + firstFind)
        {
            input = a.first;
        }
    }

    int64_t ans2 = day14.countTotalScore(input);
    EXPECT_EQ(ans2, 101010);
}