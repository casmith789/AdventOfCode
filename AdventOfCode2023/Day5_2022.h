#pragma once
#include <string>
#include <iostream>
#include <stack>
#include "input_day5_2022.h"
#include "Util.h"
#include <map>

class Day5_2022
{
public:
    Day5_2022() = default;
    ~Day5_2022() = default;

    std::vector<std::stack<char>> getStacks(std::vector<std::string> input)
    {
        std::vector<std::stack<char>> stacks;
        // get stack ids from last row
        std::string stackIDs = input.back();
        std::map<int, int> charMap;
        stacks.push_back(std::stack<char>());
        for (int i = 0; i < stackIDs.length(); ++i)
        {
            if (stackIDs[i] != ' ')
            {
                charMap[i] = stackIDs[i] - '0';
                stacks.push_back(std::stack<char>());
            }
        }
        for (int i = input.size() - 2; i >= 0; --i)
        {
            std::string line = input[i];
            for (auto it = charMap.begin(); it != charMap.end(); ++it)
            {
                int key = it->first;
                int val = it->second;
                for (int j = 0; j < line.length(); ++j)
                {
                    if (j == key)
                    {
                        if (line[key] != ' ')
                        {
                            stacks[val].push(line[key]);
                        }
                    }
                }
            }            
        }

        return stacks;
    }

    std::vector<std::pair<int, std::pair<int, int>>> getMoveMap(std::vector<std::string> input, bool secondPart)
    {
        std::vector<std::pair<int, std::pair<int, int>>> map;
        for (std::string line : input)
        {
            Util::replaceAll(line, "move ", "");
            std::vector<std::string> a = Util::split(line, " from ");
            int number = std::stoi(a[0]);
            std::vector<std::string> b = Util::split(a[1], " to ");
            int from = std::stoi(b[0]);
            int to = std::stoi(b[1]);

            if (!secondPart)
            {
                for (int i = 0; i < number; ++i)
                {
                    map.push_back(std::make_pair(1, std::make_pair(from, to)));
                }
            }
            else
            {
                map.push_back(std::make_pair(number, std::make_pair(from, to)));
            }
        }
        return map;
    }

    std::vector<std::stack<char>> applyInstructions(std::vector<std::stack<char>> current, std::vector<std::pair<int, std::pair<int, int>>> instructions)
    {
        for (std::pair<int, std::pair<int, int>> instruction : instructions)
        {
            int number = instruction.first;
            int from = instruction.second.first;
            int to = instruction.second.second;

            std::stack<char> temp;
            for (int i = 0; i < number; ++i)
            {
                char c = current[from].top();
                temp.push(c);
                current[from].pop();
            }
            for (int i = 0; i < number; ++i)
            {
                char c = temp.top();
                current[to].push(c);
                temp.pop();
            }
        }
        return current;
    }

    std::string getAnswer(std::vector<std::stack<char>> current)
    {
        std::string ans;
        for (int i = 1; i < current.size(); ++i)
        {
            ans = ans + current[i].top();
        }

        return ans;
    }

};