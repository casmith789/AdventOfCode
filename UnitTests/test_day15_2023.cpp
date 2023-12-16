#include "pch.h"
#include "Day15_2023.h"

TEST(TestDay15_2023, Test1) {
	Day15_2023 day15;
	std::string example = "HASH";
	EXPECT_EQ(day15.hashAll(example), 52);
	std::vector<std::string> lines = Util::readFile("../../AdventOfCode2023/input_day15_2023.txt");
	EXPECT_EQ(lines.size(), 1);
	std::vector<std::string> entries = Util::split(lines[0], ",");
	int64_t total = 0;
	for (std::string entry : entries)
	{		
		total = total + day15.hashAll(entry);
	}

	EXPECT_EQ(total, 503487);
}

TEST(TestDay15_2023, Test2)
{
    Day15_2023 day15;
    {
        std::vector<std::vector<std::pair<std::string, int>>> hm = day15.createHashMap();
        std::string example = "rn=1,cm-,qp=3,cm=2,qp-,pc=4,ot=9,ab=5,pc-,pc=6,ot=7";
        std::vector<std::string> entries = Util::split(example, ",");
        for (std::string entry : entries)
        {
            day15.applyStep(entry, hm);
        }

        EXPECT_EQ(day15.getValue(hm), 145);
    }
    {
        std::vector<std::vector<std::pair<std::string, int>>> hm = day15.createHashMap();
        std::vector<std::string> t2 = Util::readFile("../../AdventOfCode2023/input_day15_2023.txt");
        std::vector<std::string> entries = Util::split(t2[0], ",");
        for (std::string entry : entries)
        {
            day15.applyStep(entry, hm);
        }

        EXPECT_EQ(day15.getValue(hm), 261505);
    }
}