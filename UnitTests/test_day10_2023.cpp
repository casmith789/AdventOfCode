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
	EXPECT_EQ(day10.countInside(map, firstMap, 'F'), 1);
	EXPECT_EQ(day10.countInside2(map, firstMap, 'F'), 1);
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
	EXPECT_EQ(day10.countInside(map, firstMap, 'F'), 4);
	EXPECT_EQ(day10.countInside2(map, firstMap, 'F'), 4);
}

TEST(TestDay10_2023, TestExample3) {
	Day10_2023 day10;
	std::vector<std::string> example3 = {
	"......................",
	"..F----7F7F7F7F-7.....",
	"..|F--7||||||||FJ.....",
	"..||.FJ||||||||L7.....",
	".FJL7L7LJLJ||LJ.L-7...",
	".L--J.L7...LJS7F-7L7..",
	".....F-J..F7FJ|L7L7L7.",
	".....L7.F7||L7|.L7L7|.",
	"......|FJLJ|FJ|F7|.LJ.",
	".....FJL-7.||.||||....",
	".....L---J.LJ.LJLJ....",
	"......................"};

	std::vector<std::vector<char>> firstMap;
	std::vector<std::vector<int64_t>> map = day10.createMap(example3, firstMap);
	EXPECT_EQ(day10.countInside(map, firstMap, 'F'), 8);
	EXPECT_EQ(day10.countInside2(map, firstMap, 'F'), 8);
}

TEST(TestDay10_2023, TestExample4) {
	Day10_2023 day10;
	std::vector<std::string> example4 = {
"......................",
".FF7FSF7F7F7F7F7F---7.",
".L|LJ||||||||||||F--J.",
".FL-7LJLJ||||||LJL-77.",
".F--JF--7||LJLJ7F7FJ-.",
".L---JF-JLJ.||-FJLJJ7.",
".|F|F-JF---7F7-L7L|7|.",
".|FFJF7L7F-JF7|JL---7.",
".7-L-JL7||F7|L7F-7F7|.",
".L.L7LFJ|||||FJL7||LJ.",
".L7JLJL-JLJLJL--JLJ.L.",
"......................"
	};

	std::vector<std::vector<char>> firstMap;
	std::vector<std::vector<int64_t>> map = day10.createMap(example4, firstMap);
	EXPECT_EQ(day10.countInside(map, firstMap, '7'), 10);
	EXPECT_EQ(day10.countInside2(map, firstMap, '7'), 10);
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
	EXPECT_EQ(day10.countInside(map, firstMap, 'F'), 525);
	EXPECT_EQ(day10.countInside2(map, firstMap, 'F'), 525);
}