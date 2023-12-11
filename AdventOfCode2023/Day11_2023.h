#pragma once
#include <string>
#include <iostream>
#include <set>
#include "input_day11_2023.h"
#include "Util.h"
#include "day9_2023.h"

class Day11_2023
{
public:
    Day11_2023() = default;
    ~Day11_2023() = default;

    std::vector<std::string> expandedInput(std::vector<std::string> input, int expansionFactor)
    {
        std::vector<std::string> input2;
        std::vector<std::string> input3;

        for (std::string line : input)
        {
            bool allDots = true;
            for (char c : line)
            {
                if (c != '.')
                {
                    allDots = false;
                }
            }
            if (allDots)
            {
                for (int i = 0; i < expansionFactor-1; ++i)
                {
                    input2.push_back(line);
                    input3.push_back("");
                }
                
            }
            input2.push_back(line);
            input3.push_back("");
        }

        std::set<int> expands;
		for (int i = 0; i < input2[0].length(); ++i)
		{
            bool allDots = true;
			for (int j = 0; j < input2.size(); ++j)
			{
				char c = input2[j][i];
				if (c != '.')
				{
					allDots = false;
                    break;
				}
			}
            if (allDots)
            {
                expands.insert(i);
            }
		}
        int j = 0;
        for (std::string line : input2)
        {
            int i = 0;
            for (char c : line)
            {
                if (expands.find(i) != expands.end())
                {
                    for (int i = 0; i < expansionFactor-1; ++i)
                    {
                        input3[j] = input3[j] + c;
                    }              
                }
                input3[j] = input3[j] + c;
                ++i;
            }
            ++j;
        }

        return input3;
    }

    std::vector<std::pair<int, int>> findAllCoords(std::vector<std::string> map)
    {
        std::vector<std::pair<int, int>> ret;
        int i = 0;
        for (std::string line : map)
        {
            int j = 0;
            for (char c : line)
            {
                if (c == '#')
                {
                    ret.push_back(std::make_pair(i, j));
                }
                ++j;
            }
            ++i;
        }
        return ret;
    }

    int64_t findDistance(std::pair<int, int> a, std::pair<int, int> b)
    {
        return std::abs(b.first - a.first) + std::abs(b.second - a.second);
    }

    int64_t findTotalDistance(std::vector<std::string> map)
    {
        int64_t total = 0;
        std::vector<std::pair<int, int>> coords = findAllCoords(map);
        for (int i = 0; i < coords.size(); ++i)
        {
            for (int j = i + 1; j < coords.size(); ++j)
            {
                total = total + findDistance(coords[i], coords[j]);
            }
        }
        return total;
    }

    int64_t findTotalDistance(std::vector<std::string> map, int expansionFactor)
    {
        if (expansionFactor < 10)
        {
            std::vector<std::string> exp = expandedInput(map, expansionFactor);
            return findTotalDistance(exp);

        }

        else
        {
            std::vector<int64_t> gaps;
            for (int i = 1; i < 10; ++i)
            {
                std::vector<std::string> exp = expandedInput(map, i);
                gaps.push_back(findTotalDistance(exp));
            }

            return findTotalDistance(gaps, 9, expansionFactor);
        }
    }

    int64_t findTotalDistance(std::vector<int64_t> sequence, int max_term, int term)
    {
        Day9_2023 day9;
        std::vector<std::vector<int64_t>> gapList;

        while (!day9.is_same_val(sequence))
        {
            gapList.push_back(sequence);
            sequence = day9.getGaps(sequence);
        }
        int64_t num_extra_terms = term - max_term;
        return gapList[0][gapList[0].size() - 1] + num_extra_terms * sequence[0];
    }

};