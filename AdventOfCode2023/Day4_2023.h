#pragma once
#include <string>
#include <iostream>
#include <set>
#include <regex>
#include "input_day4_2023.h"
#include "Util.h"

class Day4_2023
{
public:
    Day4_2023() = default;
    ~Day4_2023() = default;

    long lineValue(std::string line, bool secondPart)
    {
        long points = 0;
        std::string originalLine = line;
        int id = 0;
        bool setfirst = false;
        Util::replaceAll(line, "Card", "");
        {
            std::size_t found = line.find(":");
            if (found != std::string::npos)
            {
                id = std::stoi(line.substr(0, found));
                line = line.substr(found + 1);
            }
        }

        std::vector<std::string> s = Util::split(line, " | ");
        if (s.size() == 2)
        {
            std::vector<std::string> s1 = Util::split(s[0], " ");
            std::vector<std::string> s2 = Util::split(s[1], " ");

            std::set<int> i1;
            std::set<int> i2;
            for (std::string t : s1)
            {
                if (t.size())
                {
                    i1.insert(std::stoi(t));
                }
            }
            for (std::string t : s2)
            {
                if (t.size())
                {
                    i2.insert(std::stoi(t));
                }
            }

            for (int i : i1)
            {
                if (i2.find(i) != i2.end())
                {
                    if (points == 0)
                    {
                        points = 1;
                    }
                    else
                    {
                        if (!secondPart)
                        {
                            points = points * 2;
                        }
                        else
                        {
                            points = points + 1;
                        }
                    }
                }
            }
        }

        return points;
    }


    long full(std::vector<std::string> input, bool secondPart)
    {
        if (!secondPart)
        {
            long total = 0;
            for (std::string line : input)
            {
                total = total + lineValue(line, secondPart);
            }
            return total;
        }
        else
        {
            std::vector<int> numberEachIsDone;
            for (auto line : input)
            {
                numberEachIsDone.push_back(1);
            }

            for (int i = 0; i < input.size(); ++i)
            {
                std::string line = input[i];
                int points = lineValue(line, secondPart);
                for (int j = 0; j < points; ++j)
                {
                    int index = i + j + 1;
                    if (index < input.size())
                    {
                        numberEachIsDone[index] = numberEachIsDone[index] + numberEachIsDone[i];
                    }
                }
            }

            int total = 0;
            for (int i : numberEachIsDone)
            {
                total = total + i;
            }
            return total;
        }
    }



};

