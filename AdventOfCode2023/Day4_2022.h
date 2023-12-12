#pragma once
#include <string>
#include <iostream>
#include "input_day4_2022.h"
#include "Util.h"

class Day4_2022
{
public:
    Day4_2022() = default;
    ~Day4_2022() = default;


    bool isCompletelyEnclosed(std::string line)
    {
        std::vector<std::string> sp = Util::split(line, ",");
        std::vector<std::string> s1 = Util::split(sp[0], "-");
        std::vector<std::string> s2 = Util::split(sp[1], "-");

        int a1 = std::stoi(s1[0]);
        int a2 = std::stoi(s1[1]);
        int b1 = std::stoi(s2[0]);
        int b2 = std::stoi(s2[1]);

        if (a1 <= b1)
        {
            if (a2 >= b2)
            {
                return true;
            }
        }
        if (b1 <= a1)
        {
            if (b2 >= a2)
            {
                return true;
            }
        }
        return false;
    }

    bool isOverlapping(std::string line)
    {
        std::vector<std::string> sp = Util::split(line, ",");
        std::vector<std::string> s1 = Util::split(sp[0], "-");
        std::vector<std::string> s2 = Util::split(sp[1], "-");

        int a1 = std::stoi(s1[0]);
        int a2 = std::stoi(s1[1]);
        int b1 = std::stoi(s2[0]);
        int b2 = std::stoi(s2[1]);

        if (a1 <= b1 && a2 >= b1)
        {
            return true;
        }
        else if (a1 <= b2 && a2 >= b2)
        {
            return true;
        }
        else if (b1 <= a1 && b2 >= a1)
        {
            return true;
        }
        else if (b1 <= a2 && b2 >= a2)
        {
            return true;
        }
        return false;
    }

    int findNumEnclosed(std::vector<std::string> input)
    {
        int enclosed = 0;
        for (std::string line : input)
        {
            if (isCompletelyEnclosed(line))
            {
                ++enclosed;
            }
        }
        return enclosed;
    }

    int findNumOverlapping(std::vector<std::string> input)
    {
        int enclosed = 0;
        for (std::string line : input)
        {
            if (isOverlapping(line))
            {
                ++enclosed;
            }
        }
        return enclosed;
    }

};