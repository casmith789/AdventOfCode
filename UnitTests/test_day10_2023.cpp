#include "pch.h"
#include "Day10_2023.h"
#include "input_day10_2023.h"

TEST(TestDay10_2023, TestExample1) {
	Day10_2023 day10;
	std::vector<std::string> example1 = {
	".......",
	"...S-7.",
	"...|.|.",
	"...L-J.",
	"......." };
	std::vector<std::vector<char>> firstMap;
	std::vector<std::vector<int64_t>> map = day10.createMap(example1, firstMap);

	EXPECT_EQ(map[3][1], 0);
	EXPECT_EQ(map[3][2], 1);
	EXPECT_EQ(map[3][3], 2);
	EXPECT_EQ(map[3][4], -1);
	EXPECT_EQ(map[4][1], 1);
	EXPECT_EQ(map[4][3], 3);
	EXPECT_EQ(map[5][3], 4);
	EXPECT_EQ(day10.findHighest(map), 4);
	EXPECT_EQ(day10.countInside(map, firstMap), 1);
}

TEST(TestDay10_2023, TestExample2) {
	Day10_2023 day10;
	std::vector<std::string> example2 = {
	"............",
	"..S-------7.",
	"..|F-----7|.",
	"..||.....||.",
	"..||.....||.",
	"..|L-7.F-J|.",
	"..|..|.|..|.",
	"..L--J.L--J.",
	"............" };

	std::vector<std::vector<char>> firstMap;
	std::vector<std::vector<int64_t>> map = day10.createMap(example2, firstMap);
	EXPECT_EQ(day10.countInside(map, firstMap), 4);
}

TEST(TestDay10_2023, Test1) {
	Day10_2023 day10;
	std::vector<std::vector<char>> firstMap;
	std::vector<std::vector<int64_t>> map = day10.createMap(Input2023::day10_input, firstMap);
	EXPECT_EQ(day10.findHighest(map), 6690);
}

TEST(TestDay10_2023, Test2) {
	Day10_2023 day10;
	std::vector<std::vector<char>> firstMap;
	std::vector<std::vector<int64_t>> map = day10.createMap(Input2023::day10_input, firstMap);
	EXPECT_EQ(day10.countInside(map, firstMap), 300);
}