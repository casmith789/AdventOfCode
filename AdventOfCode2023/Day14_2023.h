#pragma once
#include <string>
#include <iostream>
#include "input_day14_2023.h"
#include "Util.h"
#include <cassert>

class Day14_2023
{
public:
    Day14_2023() = default;
    ~Day14_2023() = default;

    std::vector<std::string> moveOneIterationNorth(std::vector<std::string> input)
    {
        for (int i = 1; i < input.size(); ++i)
        {
            for (int j = 0; j < input[0].length(); ++j)
            {
                if (input[i][j] == 'O')
                {
                    if (input[i - 1][j] == '.')
                    {
                        input[i - 1][j] = 'O';
                        input[i][j] = '.';
                    }
                    else
                    {
                        input[i][j] = '@';
                    }
                }
            }
        }

        return input;
    }

    std::vector<std::string> moveAllIterationsNorth(std::vector<std::string> input)
    {
        std::vector<std::string> inputBefore;
        while (input != inputBefore)
        {
            inputBefore = input;
            input = moveOneIterationNorth(input);
        }

        return input;
    }

    std::vector<std::string> rotateWholeInputEast(std::vector<std::string> input)
    {
        assert(input.size() == input[0].size());
        std::vector<std::string> newInput;
        for (int i = 0; i < input.size(); ++i)
        {
            newInput.push_back("");
            for (int j = input.size() - 1; j >= 0; --j)
            {
                char c = input[j][i];
                std::string st = newInput[newInput.size() - 1];
                st = st + (c == '@' ? 'O' : c);
                newInput[newInput.size() - 1] = st;
            }
        }

        return newInput;
    }

    std::vector<std::string> spinCycle(std::vector<std::string> input)
    {
        input = moveAllIterationsNorth(input);
        input = rotateWholeInputEast(input);
        input = moveAllIterationsNorth(input);
        input = rotateWholeInputEast(input);
        input = moveAllIterationsNorth(input);
        input = rotateWholeInputEast(input);
        input = moveAllIterationsNorth(input);
        input = rotateWholeInputEast(input);
        return input;
    }

    int64_t countTotalScore(std::vector<std::string> input)
    {
        int64_t total = 0;
        for (int i = 0; i < input.size(); ++i)
        {
            int points = input.size() - i;
            for (int j = 0; j < input[0].length(); ++j)
            {
                if (input[i][j] == 'O' || input[i][j] == '@')
                {
                    total = total + points;
                }
            }
        }
        return total;
    }

};