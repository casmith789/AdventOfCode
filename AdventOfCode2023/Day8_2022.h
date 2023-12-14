#pragma once
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>
#include "input_day8_2022.h"
#include "Util.h"

class Day8_2022
{
public:
    Day8_2022() = default;
    ~Day8_2022() = default;

    std::vector<std::vector<int>> maxHeightLeftIncludingThis(std::vector<std::string> input)
    {
        std::vector<std::vector<int>> ret;
        for (int i = 0; i < input.size(); ++i)
        {
            ret.push_back(std::vector<int>());
            for (int j = 0; j < input[i].length(); ++j)
            {
                int heightLeft = -1;
                if (j - 1 >= 0)
                {
                    heightLeft = ret[i][j-1];
                }
                int height = std::max(heightLeft, input[i][j] - '0');
                ret[i].push_back(height);
            }
        }

        return ret;
    }

    std::vector<std::vector<int>> maxHeightRightIncludingThis(std::vector<std::string> input)
    {
        std::vector<std::vector<int>> ret;
        for (int i = 0; i < input.size(); ++i)
        {
            ret.push_back(std::vector<int>());
            for (int j = 0; j < input[i].length(); ++j)
            {
                ret[i].push_back(-1);
            }

            for (int j = input[i].length() - 1; j >= 0; --j)
            {
                int heightRight = -1;
                if (j + 1 <= input[i].length()-1)
                {
                    heightRight = ret[i][j + 1];
                }
                int height = std::max(heightRight, input[i][j] - '0');
                ret[i][j] = height;
            }
        }

        return ret;
    }

    std::vector<std::vector<int>> maxHeightUpIncludingThis(std::vector<std::string> input)
    {
        std::vector<std::vector<int>> ret;
        for (int i = 0; i < input.size(); ++i)
        {
            ret.push_back(std::vector<int>());
            for (int j = 0; j < input[i].length(); ++j)
            {
                int heightUp = -1;
                if (i - 1 >= 0)
                {
                    heightUp = ret[i-1][j];
                }
                int height = std::max(heightUp, input[i][j] - '0');
                ret[i].push_back(height);
            }
        }

        return ret;
    }

    std::vector<std::vector<int>> maxHeightDownIncludingThis(std::vector<std::string> input)
    {
        std::vector<std::vector<int>> ret;
        for (int i = 0; i < input.size(); ++i)
        {
            ret.push_back(std::vector<int>());
            for (int j = 0; j < input[i].length(); ++j)
            {
                ret[i].push_back(-1);
            }
        }

        for (int i = input.size() - 1; i >= 0; --i)
        {
            for (int j = 0; j < input[i].length() - 1; ++j)
            {
                int heightDown = -1;
                if (i + 1 <= input.size() - 1)
                {
                    heightDown = ret[i+1][j];
                }
                int height = std::max(heightDown, input[i][j] - '0');
                ret[i][j] = height;
            }
        }

        return ret;
    }

    int numTreesUncovered(std::vector<std::string> input)
    {
        std::vector<std::vector<int>> rMap = maxHeightRightIncludingThis(input);
        std::vector<std::vector<int>> uMap = maxHeightUpIncludingThis(input);
        std::vector<std::vector<int>> dMap = maxHeightDownIncludingThis(input);
        std::vector<std::vector<int>> lMap = maxHeightLeftIncludingThis(input);

        int total = 0;
        for (size_t i = 0; i < input.size(); ++i)
        {
            for (size_t j = 0; j < input.size(); ++j)
            {
                if (j == 0 || j == input.size() - 1 ||
                    i == 0 || i == input.size() - 1)
                {
                    total = total + 1;
                }
                else
                {
                    int thisVal = input[i][j] - '0';
                    if (thisVal > rMap[i][j+1] ||
                        thisVal > lMap[i][j-1] ||
                        thisVal > uMap[i-1][j] ||
                        thisVal > dMap[i+1][j])
                    {
                        total = total + 1;
                        //std::cout << "Inside tree: " << i << " " << j << std::endl;
                    }
                }
            }
        }

        return total;
    }

    int64_t scenicScore(int row, int col, std::vector<std::string> input)
    {
        int height = input[row][col] - '0';
        int score1 = 0;
        int score2 = 0;
        int score3 = 0;
        int score4 = 0;
        for (int x = row-1; x >= 0; --x)
        {
            ++score1;
            if (input[x][col] - '0' >= height)
            {
                break;
            }
            
        }
        for (int x = row + 1; x < input.size(); ++x)
        {
            ++score2;
            if (input[x][col] - '0' >= height)
            {
                break;
            }
            
        }
        for (int x = col - 1; x >= 0; --x)
        {
            ++score3;
            if (input[row][x] - '0' >= height)
            {
                break;
            }
            
        }
        for (int x = col + 1; x < input[0].size(); ++x)
        {
            ++score4;
            if (input[row][x] - '0' >= height)
            {
                break;
            }
            
        }
        return score1 * score2 * score3 * score4;
    }

    int maxScenicScore(std::vector<std::string> input)
    {
        int maxScenicScore = 0;
        for (int i = 0; i < input.size(); ++i)
        {
            for (int j = 0; j < input[i].length(); ++j)
            {
                int s = scenicScore(i, j, input);
                if (s > maxScenicScore)
                {
                    maxScenicScore = s;
                }
            }
        }
        return maxScenicScore;
    }



};