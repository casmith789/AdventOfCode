#pragma once
#include <string>
#include <iostream>
#include <set>
#include "input_day16_2023.h"
#include "Util.h"
#include <cassert>

enum Day16_2023_DIRECTION
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Day16_2023_LightBeam
{
public:
    Day16_2023_LightBeam(int x1, int y1, Day16_2023_DIRECTION d1)
    {
        x = x1;
        y = y1;
        dir = d1;
    }
    ~Day16_2023_LightBeam() = default;

    int x;
    int y;
    Day16_2023_DIRECTION dir;

    bool operator==(const Day16_2023_LightBeam& oth) const = default;
    bool operator<(const Day16_2023_LightBeam& oth) const
    {
        if (x < oth.x)
        {
            return true;
        }
        else if (x > oth.x)
        {
            return false;
        }
        else
        {
            if (y < oth.y)
            {
                return true;
            }
            else if (y > oth.y)
            {
                return false;
            }
            else
            {
                if (dir < oth.dir)
                {
                    return true;
                }
                else if (dir > oth.dir)
                {
                    return false;
                }
            }
        }
        return false;
    }
};

class Day16_2023
{
public:
    Day16_2023() = default;
    ~Day16_2023() = default;

    std::vector<Day16_2023_LightBeam> result(std::vector<std::string> input, Day16_2023_LightBeam initial)
    {
        std::vector<Day16_2023_LightBeam> s;
        
        std::vector<Day16_2023_LightBeam> unchecked;
        unchecked.push_back(initial);

        while (!unchecked.empty())
        {
            Day16_2023_LightBeam toCheck = unchecked[unchecked.size() - 1];
            unchecked.erase(unchecked.begin() + unchecked.size() - 1);
            if (std::find(s.begin(), s.end(), toCheck) != s.end())
            {
                continue; // already checked
            }

            if (toCheck.x >= input.size() || toCheck.x < 0 || toCheck.y >= input[0].size() || toCheck.y < 0)
            {
                continue; // out of bounds
            }
            s.push_back(toCheck); // energise

            char c = input[toCheck.x][toCheck.y];
            if (c == '.')
            {
                if (toCheck.dir == DOWN)
                {
                    unchecked.push_back(Day16_2023_LightBeam(toCheck.x + 1, toCheck.y, DOWN));
                }
                else if (toCheck.dir == UP)
                {
                    unchecked.push_back(Day16_2023_LightBeam(toCheck.x - 1, toCheck.y, UP));
                }
                else if (toCheck.dir == LEFT)
                {
                    unchecked.push_back(Day16_2023_LightBeam(toCheck.x, toCheck.y - 1, LEFT));
                }
                else if (toCheck.dir == RIGHT)
                {
                    unchecked.push_back(Day16_2023_LightBeam(toCheck.x, toCheck.y + 1, RIGHT));
                }
                else
                {
                    assert(false);
                }
            }
            else if (c == '/')
            {
                if (toCheck.dir == DOWN)
                {
                    unchecked.push_back(Day16_2023_LightBeam(toCheck.x, toCheck.y - 1, LEFT));
                }
                else if (toCheck.dir == UP)
                {
                    unchecked.push_back(Day16_2023_LightBeam(toCheck.x, toCheck.y + 1, RIGHT));
                }
                else if (toCheck.dir == LEFT)
                {
                    unchecked.push_back(Day16_2023_LightBeam(toCheck.x + 1, toCheck.y, DOWN));
                }
                else if (toCheck.dir == RIGHT)
                {
                    unchecked.push_back(Day16_2023_LightBeam(toCheck.x - 1, toCheck.y, UP));
                }
                else
                {
                    assert(false);
                }
            }
            else if (c == '@')
            {
                if (toCheck.dir == UP)
                {
                    unchecked.push_back(Day16_2023_LightBeam(toCheck.x, toCheck.y - 1, LEFT));
                }
                else if (toCheck.dir == DOWN)
                {
                    unchecked.push_back(Day16_2023_LightBeam(toCheck.x, toCheck.y + 1, RIGHT));
                }
                else if (toCheck.dir == RIGHT)
                {
                    unchecked.push_back(Day16_2023_LightBeam(toCheck.x + 1, toCheck.y, DOWN));
                }
                else if (toCheck.dir == LEFT)
                {
                    unchecked.push_back(Day16_2023_LightBeam(toCheck.x - 1, toCheck.y, UP));
                }
                else
                {
                    assert(false);
                }
            }
            else if (c == '|')
            {
                if (toCheck.dir == DOWN)
                {
                    unchecked.push_back(Day16_2023_LightBeam(toCheck.x + 1, toCheck.y, DOWN));
                }
                else if (toCheck.dir == UP)
                {
                    unchecked.push_back(Day16_2023_LightBeam(toCheck.x - 1, toCheck.y, UP));
                }
                else if (toCheck.dir == LEFT)
                {
                    unchecked.push_back(Day16_2023_LightBeam(toCheck.x + 1, toCheck.y, DOWN));
                    unchecked.push_back(Day16_2023_LightBeam(toCheck.x - 1, toCheck.y, UP));
                }
                else if (toCheck.dir == RIGHT)
                {
                    unchecked.push_back(Day16_2023_LightBeam(toCheck.x + 1, toCheck.y, DOWN));
                    unchecked.push_back(Day16_2023_LightBeam(toCheck.x - 1, toCheck.y, UP));
                }
                else
                {
                    assert(false);
                }
            }
            else if (c == '-')
            {
                if (toCheck.dir == DOWN)
                {
                    unchecked.push_back(Day16_2023_LightBeam(toCheck.x, toCheck.y - 1, LEFT));
                    unchecked.push_back(Day16_2023_LightBeam(toCheck.x, toCheck.y + 1, RIGHT));
                }
                else if (toCheck.dir == UP)
                {
                    unchecked.push_back(Day16_2023_LightBeam(toCheck.x, toCheck.y - 1, LEFT));
                    unchecked.push_back(Day16_2023_LightBeam(toCheck.x, toCheck.y + 1, RIGHT));
                }
                else if (toCheck.dir == LEFT)
                {
                    unchecked.push_back(Day16_2023_LightBeam(toCheck.x, toCheck.y - 1, LEFT));
                }
                else if (toCheck.dir == RIGHT)
                {
                    unchecked.push_back(Day16_2023_LightBeam(toCheck.x, toCheck.y + 1, RIGHT));
                }
                else
                {
                    assert(false);
                }
            }

        }

        return s;
    }

    std::set<std::pair<int, int>> energisedSquares(std::vector<Day16_2023_LightBeam> travelMap)
    {
        std::set<std::pair<int, int>> s;

        for (Day16_2023_LightBeam a : travelMap)
        {
            s.insert(std::make_pair(a.x, a.y));
        }

        return s;
    }

    void printEnergised(std::set<std::pair<int, int>> energised)
    {
        for (int i = 0; i < 10; ++i)
        {
            for (int j = 0; j < 10; ++j)
            {
                if (energised.find(std::make_pair(i, j)) != energised.end())
                {
                    std::cout << "#";
                }
                else
                {
                    std::cout << ".";
                }
            }
            std::cout << "\n";
        }
    }

};