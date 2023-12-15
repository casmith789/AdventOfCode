#pragma once
#include <string>
#include <iostream>
#include <set>
#include "input_day9_2022.h"
#include "Util.h"
#include <cassert>

class Day9_2022
{
public:
    Day9_2022() = default;
    ~Day9_2022() = default;

    int numTailPositions(std::vector<std::string> input)
    {
        std::set<std::pair<int, int>> tailPositions;
        std::pair<int, int> headPosition = std::make_pair(0, 0);
        std::pair<int, int> tailPosition = std::make_pair(0, 0);
        tailPositions.insert(tailPosition);

        for (std::string line : input)
        {
            std::vector<std::string> dir = Util::split(line, " ");
            int num = std::stoi(dir[1]);
            for (int i = 0; i < num; ++i)
            {
                if (dir[0] == "U")
                {
                    headPosition.second = headPosition.second - 1;
                }
                else if (dir[0] == "D")
                {
                    headPosition.second = headPosition.second + 1;
                }
                else if (dir[0] == "L")
                {
                    headPosition.first = headPosition.first - 1;
                }
                else if (dir[0] == "R")
                {
                    headPosition.first = headPosition.first + 1;
                }
                else
                {
                    assert(false);
                }

                int difX = headPosition.first - tailPosition.first;
                int difY = headPosition.second - tailPosition.second;
                if (std::abs(difX) > 1 || std::abs(difY) > 1)
                {
                    if (!difY)
                    {
                        if (headPosition.first > tailPosition.first)
                        {
                            tailPosition.first = tailPosition.first + 1;
                            tailPositions.insert(std::make_pair(tailPosition.first, tailPosition.second));
                        }
                        else if (tailPosition.first > headPosition.first)
                        {
                            tailPosition.first = tailPosition.first - 1;
                            tailPositions.insert(std::make_pair(tailPosition.first, tailPosition.second));
                        }
                    }
                    if (!difX)
                    {
                        if (headPosition.second > tailPosition.second)
                        {
                            tailPosition.second = tailPosition.second + 1;
                            tailPositions.insert(std::make_pair(tailPosition.first, tailPosition.second));
                        }
                        else if (tailPosition.second > headPosition.second)
                        {
                            tailPosition.second = tailPosition.second - 1;
                            tailPositions.insert(std::make_pair(tailPosition.first, tailPosition.second));
                        }
                    }
                    if (difX > 0 && difY > 0)
                    {
                        tailPosition.first = tailPosition.first + 1;
                        tailPosition.second = tailPosition.second + 1;
                        tailPositions.insert(std::make_pair(tailPosition.first, tailPosition.second));
                    }
                    else if (difX < 0 && difY > 0)
                    {
                        tailPosition.first = tailPosition.first - 1;
                        tailPosition.second = tailPosition.second + 1;
                        tailPositions.insert(std::make_pair(tailPosition.first, tailPosition.second));
                    }
                    else if (difX > 0 && difY < 0)
                    {
                        tailPosition.first = tailPosition.first + 1;
                        tailPosition.second = tailPosition.second - 1;
                        tailPositions.insert(std::make_pair(tailPosition.first, tailPosition.second));
                    }
                    else if (difX < 0 && difY < 0)
                    {
                        tailPosition.first = tailPosition.first - 1;
                        tailPosition.second = tailPosition.second - 1;
                        tailPositions.insert(std::make_pair(tailPosition.first, tailPosition.second));
                    }
                }


            }

        }
        return tailPositions.size();
    }

};