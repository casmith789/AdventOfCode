#pragma once
#include <string>
#include <iostream>
#include <set>
#include "input_day10_2023.h"
#include "Util.h"

class Day10_2023
{
public:
    Day10_2023() = default;
    ~Day10_2023() = default;

    static const int SQUARE_SIZE = 145;

    bool canLink(int x1, int y1, int x2, int y2, std::vector<std::vector<char>> firstMap)
    {
        char one = firstMap[y1][x1];
        char two = firstMap[y2][x2];
        if (one == '.' || two == '.')
        {
            return false;
        }

        bool one_connects_to_two = false;
        bool two_connects_to_one = false;
        if (one == 'S')
        {
            one_connects_to_two = true;
        }
        if (two == 'S')
        {
            two_connects_to_one = true;
        }
        if (y1 == y2)
        {
            if (one == '-')
            {
                one_connects_to_two = true;
            }
            if (two == '-')
            {
                two_connects_to_one = true;
            }
            if (x1 == x2 + 1)
            {
                // x1 is right of x2
                if (one == 'J' || one == '7')
                {
                    one_connects_to_two = true;
                }

                if (two == 'F' || two == 'L')
                {
                    two_connects_to_one = true;
                }
            }
            else if (x1 + 1 == x2)
            {
                // x1 is left of x2
                if (two == 'J' || two == '7')
                {
                   two_connects_to_one = true;
                }

                if (one == 'F' || one == 'L')
                {
                    one_connects_to_two = true;
                    
                }
            }
        }
        else if (x1 == x2)
        {
            if (one == '|')
            {
                one_connects_to_two = true;
            }
            if (two == '|')
            {
                two_connects_to_one = true;
            }
            if (y1 == y2 + 1)
            {
                // y1 is below y2
                if (one == 'J' || one == 'L')
                {
                    one_connects_to_two = true;
                }

                if (two == 'F' || two == '7')
                {
                    two_connects_to_one = true;
                }
            }
            else if (y1 + 1 == y2)
            {
                // x1 is above x2
                if (two == 'J' || two == 'L')
                {
                    two_connects_to_one = true;
                }

                if (one == 'F' || one == '7')
                {
                    one_connects_to_two = true;

                }
            }
        }
        if (one_connects_to_two && two_connects_to_one)
        {
            return true;
        }

        return false;
    }


    std::vector<std::vector<int64_t>> createMap(std::vector<std::string> input, std::vector<std::vector<char>>& firstMap)
    {
        int Sx = 0;
        int Sy = 0;
        std::vector<int64_t> empty{};
        for (std::string line : input)
        {
            firstMap.push_back(std::vector<char>());
            int idx = firstMap.size() - 1;
            for (char c : line)
            {
                if (c == 'S')
                {
                    Sy = idx;
                    Sx = firstMap[idx].size();
                }
                firstMap[idx].push_back(c);
            }
        }
        // WTF DEBUGGING JUST IGNORES THIS
        //std::vector<std::vector<int64_t>> numMap;
        //for (int i = 0; i < input.size(); ++i)
        //{
        //    numMap.push_back(std::vector<int64_t>());
        //    for (int j = 0; j < input[0].size(); ++j)
        //    {
        //        numMap[i].push_back(-1);
        //    }
        //}


        int numMap[SQUARE_SIZE][SQUARE_SIZE];
        for (int i = 0; i < SQUARE_SIZE; ++i)
        {
            for (int j = 0; j < SQUARE_SIZE; ++j)
            {
                numMap[i][j] = -1;
            }
        }

        numMap[Sx][Sy] = 0;

        std::set<std::pair<int, int>> usedNodes;

        std::vector<std::pair<int, int>> openEdges;
        openEdges.push_back(std::make_pair(Sx, Sy));

        while (!openEdges.empty())
        {
            std::pair<int, int> openEdge = openEdges.front();
            if (usedNodes.find(openEdge) != usedNodes.end())
            {
                openEdges.erase(openEdges.begin());
                continue;
            }
            int x = openEdge.first;
            int y = openEdge.second;
            //std::cout << "Testing edge (" << x << ", " << y << ")" << std::endl;

            if (x-1 >= 0 && numMap[x - 1][y] < 0 && canLink(x, y, x - 1, y, firstMap))
            {
                numMap[x - 1][y] = numMap[x][y] + 1;
                openEdges.push_back(std::make_pair(x - 1, y));
                //std::cout << "Linked left" << std::endl;
            }
            if (x+1 < firstMap[y].size() && numMap[x + 1][y] < 0 && canLink(x, y, x + 1, y, firstMap))
            {
                numMap[x + 1][y] = numMap[x][y] + 1;
                openEdges.push_back(std::make_pair(x + 1, y));
                //std::cout << "Linked right" << std::endl;
            }
            if (y-1 >= 0 && numMap[x][y-1] < 0 && canLink(x, y, x, y - 1, firstMap))
            {
                numMap[x][y-1] = numMap[x][y] + 1;
                openEdges.push_back(std::make_pair(x, y - 1));
                //std::cout << "Linked up" << std::endl;
            }
            if (y+1 < firstMap.size() && numMap[x][y + 1] < 0 && canLink(x, y, x, y + 1, firstMap))
            {
                numMap[x][y + 1] = numMap[x][y] + 1;
                openEdges.push_back(std::make_pair(x, y + 1));
               // std::cout << "Linked down" << std::endl;
            }
            usedNodes.insert(openEdge);
            openEdges.erase(openEdges.begin());
        }

        std::vector<std::vector<int64_t>> numericalMap;
        for (int i = 0; i < SQUARE_SIZE; ++i)
        {
            numericalMap.push_back(std::vector<int64_t>());
            for (int j = 0; j < SQUARE_SIZE; ++j)
            {
                numericalMap[i].push_back(numMap[i][j]);
            }
        }


        return numericalMap;
    }

    int countInside(std::vector<std::vector<int64_t>> numericalMap, const std::vector<std::vector<char>>& firstMap, char S)
    {
        int numInside = 0;
        for (int x = 0; x < numericalMap.size(); ++x)
        {
            int numInsideStore = 0;
            bool count = false;
            int pipesInARow = 0;
            char pipeStartChar = '@';
            char pipeEndChar = '@';
            for (int y = 0; y < numericalMap[x].size(); ++y)
            {
                bool thisPipe = numericalMap[x][y] > -1;

                if (y - 1 < 0)
                {
                    count = false;
                }
                else if (pipesInARow > 0 && thisPipe == false)
                {
                    if (pipesInARow == 1)
                    {
                        count = !count;
                    }
                    else if (pipeStartChar == 'F' && pipeEndChar == 'J')
                    {
                        count = !count;
                    }
                    else if (pipeStartChar == '7' && pipeEndChar == 'L')
                    {
                        count = !count;
                    }
                    numInside += numInsideStore;
                    if (count)
                    {
                        numInsideStore = 1;
                    }
                    else
                    {
                        numInsideStore = 0;
                    }
                }
                else if (pipesInARow > 0 && thisPipe == true)
                {
                    if (!canLink(x, y-1, x, y, firstMap))
                    {
                        if (pipesInARow == 1)
                        {
                            count = !count;
                        }
                        else if (pipeStartChar == 'F' && pipeEndChar == 'J')
                        {
                            count = !count;
                        }
                        else if (pipeStartChar == '7' && pipeEndChar == 'L')
                        {
                            count = !count;
                        }

                        pipesInARow = 0;
                    }
                }
                else if (pipesInARow == 0 && thisPipe == false)
                {
                    if (count)
                    {
                        ++numInsideStore;
                    }
                }
                else if (pipesInARow == 0 && thisPipe == true)
                {
                    if (count)
                    {
                        numInside += numInsideStore;
                        numInsideStore = 0;
                    }
                }
                if (thisPipe)
                {
                    ++pipesInARow;
                    if (pipesInARow == 1)
                    {
                        pipeStartChar = firstMap[y][x];
                        if (pipeStartChar == 'S')
                        {
                            pipeStartChar = S;
                        }
                    }
                    pipeEndChar = firstMap[y][x];
                    if (pipeEndChar == 'S')
                    {
                        pipeEndChar = S;
                    }
                }
                else
                {
                    pipesInARow = 0;
                }
            }
        }

        return numInside;
    }

    int countInside2(std::vector<std::vector<int64_t>> numericalMap, const std::vector<std::vector<char>>& firstMap, char S)
    {
        int numInside = 0;
        for (int y = 0; y < numericalMap.size(); ++y)
        {
            int numInsideStore = 0;
            bool count = false;
            int pipesInARow = 0;
            char pipeStartChar = '@';
            char pipeEndChar = '@';
            for (int x = 0; x < numericalMap[y].size(); ++x)
            {
                bool thisPipe = numericalMap[x][y] > -1;

                if (x - 1 < 0)
                {
                    count = false;
                }
                else if (pipesInARow > 0 && thisPipe == false)
                {
                    if (pipesInARow == 1)
                    {
                        count = !count;
                    }
                    else if (pipeStartChar == 'F' && pipeEndChar == 'J')
                    {
                        count = !count;
                    }
                    else if (pipeStartChar == 'L' && pipeEndChar == '7')
                    {
                        count = !count;
                    }
                    numInside += numInsideStore;
                    if (count)
                    {
                        numInsideStore = 1;
                    }
                    else
                    {
                        numInsideStore = 0;
                    }
                }
                else if (pipesInARow > 0 && thisPipe == true)
                {
                    if (!canLink(x - 1, y, x, y, firstMap))
                    {
                        if (pipesInARow == 1)
                        {
                            count = !count;
                        }
                        else if (pipeStartChar == 'F' && pipeEndChar == 'J')
                        {
                            count = !count;
                        }
                        else if (pipeStartChar == 'L' && pipeEndChar == '7')
                        {
                            count = !count;
                        }

                        pipesInARow = 0;
                    }
                }
                else if (pipesInARow == 0 && thisPipe == false)
                {
                    if (count)
                    {
                        ++numInsideStore;
                    }
                }
                else if (pipesInARow == 0 && thisPipe == true)
                {
                    if (count)
                    {
                        numInside += numInsideStore;
                        numInsideStore = 0;
                    }
                }
                if (thisPipe)
                {
                    ++pipesInARow;
                    if (pipesInARow == 1)
                    {
                        pipeStartChar = firstMap[y][x];
                        if (pipeStartChar == 'S')
                        {
                            pipeStartChar = S;
                        }
                    }
                    pipeEndChar = firstMap[y][x];
                    if (pipeEndChar == 'S')
                    {
                        pipeEndChar = S;
                    }
                }
                else
                {
                    pipesInARow = 0;
                }
            }
        }

        return numInside;
    }



    int findHighest(std::vector<std::vector<int64_t>> numericalMap)
    {
        int highest = 0;
        for (auto a : numericalMap)
        {
            for (int64_t b : a)
            {
                if (b > highest)
                {
                    highest = b;
                }
            }
        }
        return highest;
    }

    void printMap(std::vector<std::vector<int64_t>> numericalMap)
    {
        for (auto list : numericalMap)
        {
            for (int64_t val : list)
            {
                if (val == -1)
                {
                    std::cout << ". ";
                }
                else
                {
                    std::cout << val << " ";
                }
            }
            std::cout << std::endl;
        }
    }

};