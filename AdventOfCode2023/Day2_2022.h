#pragma once
#include <string>
#include <iostream>
#include "input_day2_2022.h"
#include "Util.h"

class Day2_2022
{
public:
    Day2_2022() = default;
    ~Day2_2022() = default;

    int linePoints(std::string line)
    {
        int points = 0;
        std::vector<std::string> rolls = Util::split(line, " ");
        std::string oppRoll = rolls[0];
        std::string yourRoll = rolls[1];

        if (yourRoll == "X")
        {
            points = points + 1;
            if (oppRoll == "C")
            {
                points = points + 6;
            }
            else if (oppRoll == "A")
            {
                points = points + 3;
            }
        }
        else if (yourRoll == "Y")
        {
            points = points + 2;
            if (oppRoll == "A")
            {
                points = points + 6;
            }
            else if (oppRoll == "B")
            {
                points = points + 3;
            }
        } else {
            points = points + 3;
            if (oppRoll == "B")
            {
                points = points + 6;
            }
            else if (oppRoll == "C")
            {
                points = points + 3;
            }
        }
        return points;
    }

    int linePoints2(std::string line)
    {
        int points = 0;
        std::vector<std::string> rolls = Util::split(line, " ");
        std::string oppRoll = rolls[0];
        std::string yourResult = rolls[1];

        if (yourResult == "X")
        {
            points = points + 0;
            if (oppRoll == "A")
            {
                points = points + 3;
            }
            else if (oppRoll == "B")
            {
                points = points + 1;
            }
            else if (oppRoll == "C")
            {
                points = points + 2;
            }
        }
        else if (yourResult == "Y")
        {
            points = points + 3;
            if (oppRoll == "A")
            {
                points = points + 1;
            }
            else if (oppRoll == "B")
            {
                points = points + 2;
            }
            else if (oppRoll == "C")
            {
                points = points + 3;
            }
        }
        else
        {
            points = points + 6;
            if (oppRoll == "A")
            {
                points = points + 2;
            }
            else if (oppRoll == "B")
            {
                points = points + 3;
            }
            else if (oppRoll == "C")
            {
                points = points + 1;
            }
        }


        return points;
    }

    int full(std::vector<std::string> input, bool secondPart)
    {
        int points = 0;
        for (std::string line : input)
        {
            if (!secondPart)
            {
                points = points + linePoints(line);
            }
            else
            {
                points = points + linePoints2(line);
            }
        }
        return points;
    }
};