#pragma once
#include <string>
#include <iostream>
#include "input_day1_2022.h"
#include "Util.h"

class Day1_2022
{
public:
    Day1_2022() = default;
    ~Day1_2022() = default;

    std::vector<std::vector<int>> formInput(std::vector<std::string> input)
    {
        std::vector<std::vector<int>> elfInfo;
        elfInfo.push_back(std::vector<int>());
        for (std::string line : input)
        {
            if (line == "")
            {
                elfInfo.push_back(std::vector<int>());
            }
            else
            {
                elfInfo[elfInfo.size() - 1].push_back(std::stoi(line));
            }
        }

        return elfInfo;
    }

    int findMostCalories(std::vector<std::string> input, bool secondPart)
    {
        std::vector<std::vector<int>> elfInfo = formInput(input);
        int max = 0;
        int max2 = 0;
        int max3 = 0;
        for (std::vector<int> a : elfInfo)
        {
            int total = 0;
            for (int b : a)
            {
                total = total + b;
            }
            if (total > max)
            {
                max3 = max2;
                max2 = max;
                max = total;
            }
            else if (total > max2)
            {
                max3 = max2;
                max2 = total;
            }
            else if (total > max3)
            {
                max3 = total;
            }
        }
        if (!secondPart)
        {
            return max;
        }
        else return (max + max2 + max3);
    }

};