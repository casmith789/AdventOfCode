#include "pch.h"
#include "Day13_2023.h"
#include "input_day13_2023.h"

TEST(TestDay13_2023, TestExample) {
    Day13_2023 day13;
    std::vector<std::string> puzzleInput = {
        "#.##..##.",
        "..#.##.#.",
        "##......#",
        "##......#",
        "..#.##.#.",
        "..##..##.",
        "#.#.##.#.",
        "",
        "#...##..#",
        "#....#..#",
        "..##..###",
        "#####.##.",
        "#####.##.",
        "..##..###",
        "#....#..#",
        ""
    };

    std::vector<std::vector<std::string>> puzzles = day13.parseInputIntoPuzzles(puzzleInput);
    std::vector<std::vector<int>> p1 = day13.parsePuzzle(puzzles[0]);
    std::vector<std::vector<int>> p2 = day13.parsePuzzle(puzzles[1]);
    EXPECT_EQ(day13.isSymmetricalRow(1, p1, 0), false);
    EXPECT_EQ(day13.isSymmetricalRow(1, p2, 0), false);
    EXPECT_EQ(day13.isSymmetricalRow(3, p2, 0), true);
    EXPECT_EQ(day13.isSymmetricalRow(4, p2, 0), false);
    EXPECT_EQ(day13.findSymmetryPoint(p1, false), 5);
    EXPECT_EQ(day13.findSymmetryPoint(p2, false), 400);
    EXPECT_EQ(day13.findTotal(puzzleInput, false), 405);
    EXPECT_EQ(day13.findTotal(puzzleInput, true), 400);
}

TEST(TestDay13_2023, Test1CaseByCase)
{
    Day13_2023 day13;
    std::vector<std::vector<std::string>> puzzles = day13.parseInputIntoPuzzles(Input2023::day13_input);
    std::vector<std::vector<int>> p1 = day13.parsePuzzle(puzzles[0]);
    EXPECT_EQ(day13.findSymmetryPoint(p1, false), 400);
    p1 = day13.parsePuzzle(puzzles[1]);
    EXPECT_EQ(day13.findSymmetryPoint(p1, false), 2);
    p1 = day13.parsePuzzle(puzzles[2]);
    EXPECT_EQ(day13.findSymmetryPoint(p1, false), 4);
    p1 = day13.parsePuzzle(puzzles[3]);
    EXPECT_EQ(day13.findSymmetryPoint(p1, false), 200);
    p1 = day13.parsePuzzle(puzzles[4]);
    EXPECT_EQ(day13.findSymmetryPoint(p1, false), 1);
    p1 = day13.parsePuzzle(puzzles[5]);
    EXPECT_EQ(day13.findSymmetryPoint(p1, false), 800);
    p1 = day13.parsePuzzle(puzzles[6]);
    EXPECT_EQ(day13.findSymmetryPoint(p1, false), 100);
    p1 = day13.parsePuzzle(puzzles[7]);
    EXPECT_EQ(day13.findSymmetryPoint(p1, false), 1);
    p1 = day13.parsePuzzle(puzzles[8]);
    EXPECT_EQ(day13.findSymmetryPoint(p1, false), 9);
    p1 = day13.parsePuzzle(puzzles[9]);
    EXPECT_EQ(day13.findSymmetryPoint(p1, false), 1400);
    p1 = day13.parsePuzzle(puzzles[10]);
    EXPECT_EQ(day13.findSymmetryPoint(p1, false), 12);
    p1 = day13.parsePuzzle(puzzles[11]);
    EXPECT_EQ(day13.findSymmetryPoint(p1, false), 2);
    p1 = day13.parsePuzzle(puzzles[12]);
    EXPECT_EQ(day13.findSymmetryPoint(p1, false), 11);
    p1 = day13.parsePuzzle(puzzles[13]);
    EXPECT_EQ(day13.findSymmetryPoint(p1, false), 3);
    p1 = day13.parsePuzzle(puzzles[14]);
    EXPECT_EQ(day13.findSymmetryPoint(p1, false), 6);
    p1 = day13.parsePuzzle(puzzles[15]);
    EXPECT_EQ(day13.findSymmetryPoint(p1, false), 900);
    p1 = day13.parsePuzzle(puzzles[16]);
    EXPECT_EQ(day13.findSymmetryPoint(p1, false), 13);
    p1 = day13.parsePuzzle(puzzles[17]);
    EXPECT_EQ(day13.findSymmetryPoint(p1, false), 11);
}


TEST(TestDay13_2023, Test1) {
    Day13_2023 day13;
    // 31940 too high
    // 26891 too low
    EXPECT_EQ(day13.findTotal(Input2023::day13_input, false), 30802);
}

TEST(TestDay13_2023, Test2) {
    Day13_2023 day13;
    EXPECT_EQ(day13.findTotal(Input2023::day13_input, true), 37876);
}