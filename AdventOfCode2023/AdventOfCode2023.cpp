// AdventOfCode2023.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma warning( disable : 6262 )
#include <iostream>
#include "Day10_2023.h"
#include "input_day10_2023.h"


int main()
{
	//Day10_2023 day10;
	//std::vector<std::string> example1 = {
	//".......",
	//"...S-7.",
	//"...|.|.",
	//"...L-J.",
	//"......." };

	//std::vector<std::vector<char>> firstMap;
	//std::vector<std::vector<int64_t>> map = day10.createMap(Input2023::day10_input, firstMap);
	//Day10_2023 day10;
	//std::vector<std::string> example2 = {
	//"...........",
	//".S-------7.",
	//".|F-----7|.",
	//".||.....||.",
	//".||.....||.",
	//".|L-7.F-J|.",
	//".|..|.|..|.",
	//".L--J.L--J.",
	//"..........." };

	//std::vector<std::vector<char>> firstMap;
	//std::vector<std::vector<int64_t>> map = day10.createMap(example2, firstMap);
	//day10.printMap(map);


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
	day10.printMap(map);
	int b = 3;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
