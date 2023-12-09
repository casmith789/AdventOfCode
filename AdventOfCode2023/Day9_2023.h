#pragma once
#include <string>
#include <iostream>
#include <set>
#include "input_day9_2023.h"
#include "Util.h"

class Day9_2023
{
public:
    Day9_2023() = default;
    ~Day9_2023() = default;

    bool is_same_val(std::vector<int64_t> sequence)
    {
        if (sequence.size() <= 1)
        {
            return true;
        }
        int64_t val = sequence[0];
        for (int i = 1; i < sequence.size(); ++i)
        {
            if (sequence[i] != val)
            {
                return false;
            }
        }
        return true;
    }

    std::vector<int64_t> getGaps(std::vector<int64_t> sequence)
    {
        std::vector<int64_t> gaps;
        int64_t prev;
        int first = true;
        for (int64_t a : sequence)
        {
            if (first)
            {
                prev = a;
                first = false;
            }
            else
            {
                gaps.push_back(a - prev);
                prev = a;
            }
        }
        return gaps;
    }


    int lineValue(std::string line, bool secondPart)
    {
        std::vector<std::string> other = Util::split(line, " ");
        std::vector<int64_t> sequence;
        for (std::string oth : other)
        {
            sequence.push_back(std::stoll(oth));
        }

        std::vector<std::vector<int64_t>> gapList;

        while (!is_same_val(sequence))
        {
            gapList.push_back(sequence);
            sequence = getGaps(sequence);
        }

        int64_t addedNum = sequence[0];

        if (!secondPart)
        {
            for (int i = gapList.size() - 1; i >= 0; --i)
            {
                addedNum = gapList[i][gapList[i].size() - 1] + addedNum;
            }
        }
        else
        {
            for (int i = gapList.size() - 1; i >= 0; --i)
            {
                addedNum = gapList[i][0] - addedNum;
            }
        }

        return addedNum;
    }


    int64_t full(bool secondPart)
    {
        std::vector<std::string> input = Input2023::day9_input;
        int64_t total = 0;
        for (std::string line : input)
        {
            total = total + lineValue(line, secondPart);
        }
        return total;
    }



};
