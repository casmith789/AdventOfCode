#pragma once
#include <vector>
#include <string>
#include <unordered_map>
#include <numeric>
#include "Util.h"

class Day8_2023
{
public:
    Day8_2023() = default;
    ~Day8_2023() = default;

    std::unordered_map<std::string, std::pair<std::string, std::string>> createMapFromInput(std::vector<std::string> input, std::vector<std::string>& startNodes)
    {
        std::unordered_map<std::string, std::pair<std::string, std::string>> ret;
        for (std::string line : input)
        {
            std::vector<std::string> eachNum = Util::split(line, " = ");
            std::string first = eachNum[0];
            Util::replaceAll(eachNum[1], "(", "");
            Util::replaceAll(eachNum[1], ")", "");
            Util::replaceAll(eachNum[1], " ", "");
            std::vector<std::string> eachNum2 = Util::split(eachNum[1], ",");
            ret[first] = std::make_pair(eachNum2[0], eachNum2[1]);
            if (first[2] == 'A')
            {
                startNodes.push_back(first);
            }
        }
        return ret;
    }

    bool endCriteria(const std::vector<std::string>& currentNodes, bool secondPart)
    {
        if (!secondPart)
        {
            return currentNodes[0] == "ZZZ";
        }
        else
        {
            for (std::string all : currentNodes)
            {
                if (all[2] != 'Z')
                {
                    return false;
                }
            }
        }
        return true;
    }

    int64_t numSteps(std::string LRstring, std::vector<std::string> input, bool secondPart)
    {
        std::vector<std::string> currentNodes;
        std::unordered_map<std::string, std::pair<std::string, std::string>> map = createMapFromInput(input, currentNodes);
        if (!secondPart)
        {
            currentNodes.clear();
            std::string node = "AAA";
            currentNodes.push_back(node);
        }
        int LRstringIndex = 0;
        int index = 0;
        std::vector<std::vector<int64_t>> completionNums;
        std::vector<int64_t> empty;
        for (auto irrel : currentNodes)
        {
            completionNums.push_back(empty);
        }
        while (!endCriteria(currentNodes, secondPart))
        {
            
            if (LRstringIndex == LRstring.size())
            {
                LRstringIndex = 0;
            }
            std::vector<std::string> newCurrentNodes;
            int y = 0;
            for (std::string node : currentNodes)
            {
                char c = LRstring[LRstringIndex];
                if (c == 'L')
                {
                    newCurrentNodes.push_back(map[node].first);
                }
                if (c == 'R')
                {
                    newCurrentNodes.push_back(map[node].second);
                }
                if (node[2] == 'Z')
                {
                    completionNums[y].push_back(index);
                    bool foundAll = true;
                    for (int i = 0; i < completionNums.size(); ++i)
                    {
                        if (completionNums[i].size() < 2)
                        {
                            foundAll = false;
                            break;
                        }
                    }
                    if (foundAll)
                    {
                        int64_t ans = completionNums[0][0];
                        for (int i = 1; i < completionNums.size(); ++i)
                        {
                            ans = std::lcm(ans, completionNums[i][0]);
                        }
                        return ans;
                    }
                }
                ++y;
            }
            currentNodes = newCurrentNodes;
            ++index;
            ++LRstringIndex;
        }

        return index;


    }



};
