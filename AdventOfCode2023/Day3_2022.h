#pragma once
#include <string>
#include <iostream>
#include <set>
#include "input_day3_2022.h"
#include "Util.h"

class Day3_2022
{
public:
    Day3_2022() = default;
    ~Day3_2022() = default;

    int partOneLine(std::string line)
    {
        std::set<char> firstLine;
        std::set<char> secondLine;


        for (int i = 0; i < line.length(); ++i)
        {
            if (i >= line.length() / 2)
            {
                secondLine.insert(line[i]);
            }
            else
            {
                firstLine.insert(line[i]);
            }
        }

        std::set<char> commonChars;

        for (char c : firstLine)
        {
            if (secondLine.find(c) != secondLine.end())
            {
                commonChars.insert(c);
            }
        }

        int total = 0;
        for (char c : commonChars)
        {
            if (c >= 'a' && c <= 'z')
            {
                total = total + c - 'a' + 1;
            }
            else
            {
                total = total + c - 'A' + 27;
            }
        }

        return total;
    }

    int64_t totalForAllP1(std::vector<std::string> input)
    {
        int64_t total = 0;
        for (std::string line : input)
        {
            total = total + partOneLine(line);
        }

        return total;
    }

    int64_t totalForAllP2(std::vector<std::string> input)
    {
        int64_t total = 0;
        for (int i = 0; i < input.size(); i += 3)
        {
            total = total + partTwoElfThreeLines(input[i], input[i + 1], input[i + 2]);
        }

        return total;
    }

    int partTwoElfThreeLines(std::string line1, std::string line2, std::string line3)
    {
        std::set<char> line1c;
        std::set<char> line2c;
        std::set<char> line3c;

        for (char c : line1)
        {
            line1c.insert(c);
        }
        for (char c : line2)
        {
            line2c.insert(c);
        }
        for (char c : line3)
        {
            line3c.insert(c);
        }


        std::set<char> commonChars;

        for (char c : line1c)
        {
            if (line2c.find(c) != line2c.end())
            {
                if (line3c.find(c) != line3c.end())
                {
                    commonChars.insert(c);
                }
            }
        }

        int total = 0;
        for (char c : commonChars)
        {
            if (c >= 'a' && c <= 'z')
            {
                total = total + c - 'a' + 1;
            }
            else
            {
                total = total + c - 'A' + 27;
            }
        }

        return total;
    }
};