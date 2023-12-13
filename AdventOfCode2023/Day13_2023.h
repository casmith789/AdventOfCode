#pragma once
#include <string>
#include <iostream>
#include "input_day13_2023.h"
#include "Util.h"
#include <cassert>

class Day13_2023
{
public:
    Day13_2023() = default;
    ~Day13_2023() = default;

    std::vector<std::vector<std::string>> parseInputIntoPuzzles(std::vector<std::string> puzzleInput)
    {
        std::vector<std::vector<std::string>> puzzles;
        std::vector<std::string> puzzle;
        for (std::string line : puzzleInput)
        {
            if (line.empty())
            {
                puzzles.push_back(puzzle);
                puzzle.clear();
            }
            else
            {
                puzzle.push_back(line);
            }
        }

        return puzzles;
    }

    std::vector<std::vector<int>> parsePuzzle(std::vector<std::string> puzzleInput)
    {
        std::vector<std::vector<int>> matrix;
        for (std::string s : puzzleInput)
        {
            matrix.push_back(std::vector<int>());
            for (char c : s)
            {
                if (c == '#')
                {
                    matrix[matrix.size() - 1].push_back(1);
                }
                else
                {
                    matrix[matrix.size() - 1].push_back(0);
                }
            }
        }

        return matrix;
    }

    bool isSymmetricalRow(int row, std::vector<std::vector<int>> matrix, int numMistakes)
    {
        int min = 0;
        int max = matrix.size();
        getMinMax(row, min, max);
        if (max <= min)
        {
            return false;
        }
        for (int i = row; i >= min; --i)
        {
            int row1 = i;
            int row2 = row + (row - i) + 1;
            
            for (int j = 0; j < matrix[row1].size(); ++j)
            {
                if (matrix[row1][j] != matrix[row2][j])
                {
                    if (numMistakes > 0)
                    {
                        --numMistakes;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }

        return numMistakes == 0;
    }

    void getMinMax(int col, int& min, int& max)
    {
        int stepsDown = col - min + 1;
        int stepsUp = max - (col + 1);
        int steps = std::min(stepsUp, stepsDown);
        min = col - steps + 1;
        max = col + steps + 1;
    }

    bool isSymmetricalCol(int col, std::vector<std::vector<int>> matrix, int numMistakes)
    {
        int min = 0;
        int max = matrix[0].size();
        getMinMax(col, min, max);
        if (max <= min)
        {
            return false;
        }
        for (int i = col; i >= min; --i)
        {
            int col1 = i;
            int col2 = col + (col - i) + 1;

            for (int j = 0; j < matrix.size(); ++j)
            {
                if (matrix[j][col1] != matrix[j][col2])
                {
                    if (numMistakes > 0)
                    {
                        --numMistakes;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }

        return numMistakes == 0;
    }


    int findSymmetryPoint(std::vector<std::vector<int>> matrix, bool secondPart)
    {
        int numMistakes = 0;
        if (secondPart)
        {
            numMistakes = 1;
        }

        bool found = false;
        int retVal = 0;
        for (int i = 0; i < matrix[0].size(); ++i)
        {
            if (isSymmetricalCol(i, matrix, numMistakes))
            {
                if (!found)
                {
                    retVal = (i + 1);
                    found = true;
                }
                else
                {
                    assert(false);
                }
            }
        }
        for (int i = 0; i < matrix.size(); ++i)
        {
            if (isSymmetricalRow(i, matrix, numMistakes))
            {
                if (!found)
                {
                    retVal = 100 * (i + 1);
                    found = true;
                }
                else
                {
                    assert(false);
                }
            }
        }
        assert(found);
        return retVal;
    }

    int findTotal(std::vector<std::string> input, bool secondPart)
    {
        int total = 0;
        std::vector<std::vector<std::string>> puzzleInputs = parseInputIntoPuzzles(input);
        for (std::vector<std::string> puzzle : puzzleInputs)
        {
            std::vector<std::vector<int>> pz = parsePuzzle(puzzle);
            total = total + findSymmetryPoint(pz, secondPart);
        }

        return total;
    }
};