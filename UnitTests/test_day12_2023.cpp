#include "pch.h"
#include "Day12_2023.h"
#include "input_day12_2023.h"

TEST(TestDay12_2023, TestExample) {
    Day12_2023 day12;
    EXPECT_EQ(true, true);

    std::vector<std::string> input = {
        "???.### 1,1,3",
        ".??..??...?##. 1,1,3",
        "?#?#?#?#?#?#?#? 1,3,1,6",
        "????.#...#... 4,1,1",
        "????.######..#####. 1,6,5",
        "?###???????? 3,2,1"
    };

    // line 1
    {
        std::string line = input[0];
        std::vector<int> vec;
        std::vector<std::string> grp = day12.GetGroups(line, vec);
        EXPECT_EQ(day12.numWaysBruteForce(grp, vec), 1);
        line = day12.GetSplit(line, vec);
        std::map<std::pair<int, std::pair<int, int>>, int64_t> cache;
        EXPECT_EQ(day12.numWaysCache(line, vec, 0, 0, 0, cache), 1);
    }

    // line 2
    {
        std::string line = input[1];
        std::vector<int> vec;
        std::vector<std::string> grp = day12.GetGroups(line, vec);
        EXPECT_EQ(day12.numWaysBruteForce(grp, vec), 4);
        line = day12.GetSplit(line, vec);
        std::map<std::pair<int, std::pair<int, int>>, int64_t> cache;
        EXPECT_EQ(day12.numWaysCache(line, vec, 0, 0, 0, cache), 4);

    }

    // line 3
    {
        std::string line = input[2];
        std::vector<int> vec;
        std::vector<std::string> grp = day12.GetGroups(line, vec);
        EXPECT_EQ(day12.numWaysBruteForce(grp, vec), 1);
        line = day12.GetSplit(line, vec);
        std::map<std::pair<int, std::pair<int, int>>, int64_t> cache;
        EXPECT_EQ(day12.numWaysCache(line, vec, 0, 0, 0, cache), 1);
    }

    // line 4
    {
        std::string line = input[3];
        std::vector<int> vec;
        std::vector<std::string> grp = day12.GetGroups(line, vec);
        EXPECT_EQ(day12.numWaysBruteForce(grp, vec), 1);
        line = day12.GetSplit(line, vec);
        std::map<std::pair<int, std::pair<int, int>>, int64_t> cache;
        EXPECT_EQ(day12.numWaysCache(line, vec, 0, 0, 0, cache), 1);
    }

    // line 5
    {
        std::string line = input[4];
        std::vector<int> vec;
        std::vector<std::string> grp = day12.GetGroups(line, vec);
        EXPECT_EQ(day12.numWaysBruteForce(grp, vec), 4);
        line = day12.GetSplit(line, vec);
        std::map<std::pair<int, std::pair<int, int>>, int64_t> cache;
        EXPECT_EQ(day12.numWaysCache(line, vec, 0, 0, 0, cache), 4);
    }

    // line 6
    {
        std::string line = input[5];
        std::vector<int> vec;
        std::vector<std::string> grp = day12.GetGroups(line, vec);
        EXPECT_EQ(day12.numWaysBruteForce(grp, vec), 10);
        line = day12.GetSplit(line, vec);
        std::map<std::pair<int, std::pair<int, int>>, int64_t> cache;
        EXPECT_EQ(day12.numWaysCache(line, vec, 0, 0, 0, cache), 10);
    }
}

TEST(TestDay12_2023, Test1BruteForceDISABLED) {
    //Day12_2023 day12;
    //int total = 0;
    //int lines = 0;
    //for (std::string line : Input2023::day12_input)
    //{
    //    std::vector<int> vec;
    //    std::vector<std::string> grp = day12.GetGroups(line, vec);
    //    grp = day12.FullyReduce(grp, vec);
    //    total = total + day12.numWaysBruteForce(grp, vec);
    //    ++lines;
    //}
    //EXPECT_EQ(total, 7379);
}
TEST(TestDay12_2023, Test1Cache) {
    Day12_2023 day12;
    int total = 0;
    int lines = 0;
    for (std::string line : Input2023::day12_input)
    {
        std::vector<int> vec;
        line = day12.GetSplit(line, vec);
        std::map<std::pair<int, std::pair<int, int>>, int64_t> cache;
        total = total + day12.numWaysCache(line, vec, 0, 0, 0, cache);
        ++lines;
    }
    EXPECT_EQ(total, 7379);
}

TEST(TestDay12_2023, Test2Cache) {
    Day12_2023 day12;
    int64_t total = 0;
    int lines = 0;
    for (std::string line : Input2023::day12_input)
    {
        std::vector<int> vec;
        line = day12.GetSplit(line, vec);
        line = line + "?" + line + "?" + line + "?" + line + "?" + line;
        std::vector<int> vec2;
        for (int i = 0; i < 5; ++i)
        {
            for (int j : vec)
            {
                vec2.push_back(j);
            }
        }
        std::map<std::pair<int, std::pair<int, int>>, int64_t> cache;
        total = total + day12.numWaysCache(line, vec2, 0, 0, 0, cache);
        ++lines;
    }
    EXPECT_EQ(total, 7732028747925ll);
}