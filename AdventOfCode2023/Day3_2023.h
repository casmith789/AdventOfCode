#pragma once
#include <string>
#include <iostream>
#include <regex>
#include <set>
#include "input_day3_2023.h"
#include "Util.h"

class Day3_2023
{
public:
    Day3_2023() = default;
    ~Day3_2023() = default;

    void getNumValues(std::string line, bool secondPart, std::set<int>& numValues, std::set<int>& symbolIndexes)
    {
        int index = 0;
        for (auto c : line)
        {
            if (c == '.')
            {
                ++index;
                continue;
            }
            if (c >= '0' && c <= '9')
            {
                numValues.insert(index);
            }
            else
            {
                symbolIndexes.insert(index);
            }
            ++index;
        }
    }

    long full_firstPart(std::vector<std::string> input)
    {
        std::vector<int> parts;
        std::vector<std::set<int>> numValuesVec;
        std::vector<std::set<int>> symbolsVec;
        input.push_back(".............................................................................................................................................................");

        for (std::string line : input)
        {
            line = line + "....................0"; // don't deal with the issue of last char number - hack
            std::set<int> indexes;
            std::set<int> numValues;
            getNumValues(line, false, numValues, indexes);
            numValuesVec.push_back(numValues);
            symbolsVec.push_back(indexes);
        }

        int row = 0;

        for (std::set<int> valuesSet : numValuesVec)
        {
            std::string thisNum;
            int lastIndexOfNum = -2;
            int i = 0;
            for (int index : valuesSet)
            {
                if ((lastIndexOfNum < 0 || index - lastIndexOfNum == 1) && index <= input[row].size())
                {
                    lastIndexOfNum = index;
                    thisNum.push_back(input[row][index]);
                }
                else if (lastIndexOfNum >= 0)
                {
                    bool found = false;
                    for (int j = row - 1; j <= row + 1; ++j)
                    {
                        for (int k = lastIndexOfNum - thisNum.size(); k <= lastIndexOfNum + 1; ++k)
                        {
                            if (j < 0 || k < 0 || j > input.size() - 1 || k > input[j].size() - 1)
                            {
                                continue;
                            }
                            if (symbolsVec[j].find(k) != symbolsVec[j].end())
                            {
                                // adjacent symbol (diagonally or orthogonally)
                                // add number
                                parts.push_back(std::stoi(thisNum));
                                found = true;
                                break;
                            }
                        }
                        if (found)
                        {
                            break;
                        }
                    }
                    if (index > input[row].size())
                    {
                        break; // because of hack
                    }
                    lastIndexOfNum = index;
                    thisNum = input[row][index];
                }
            }
            ++row;
        }
        std::sort(parts.begin(), parts.end());
        long total = 0;
        for (int a : parts)
        {
            total = total + a;
        }
        return total;
    }

    int findNumberOfAdjacent(const std::vector<std::set<int>>& numValuesVec, int row, int col)
    {
        int a1 = 0;
        int a2 = 0;
        int a3 = 0;
        int b1 = 0;
        int b2 = 0;
        int b3 = 0;
        int c1 = 0;
        int c2 = 0;
        int c3 = 0;

        if (row - 1 >= 0)
        {
            if (numValuesVec[row - 1].find(col-1) != numValuesVec[row - 1].end())
            {
                a1 = 1;
            }
            if (numValuesVec[row - 1].find(col) != numValuesVec[row - 1].end())
            {
                a2 = 1;
            }
            if (numValuesVec[row - 1].find(col+1) != numValuesVec[row - 1].end())
            {
                a3 = 1;
            }
        }
        if (row < numValuesVec.size())
        {
            if (numValuesVec[row].find(col - 1) != numValuesVec[row].end())
            {
                b1 = 1;
            }
            if (numValuesVec[row].find(col + 1) != numValuesVec[row].end())
            {
                b3 = 1;
            }
        }
        if (row + 1 < numValuesVec.size())
        {
            if (numValuesVec[row + 1].find(col - 1) != numValuesVec[row + 1].end())
            {
                c1 = 1;
            }
            if (numValuesVec[row + 1].find(col) != numValuesVec[row + 1].end())
            {
                c2 = 1;
            }
            if (numValuesVec[row + 1].find(col + 1) != numValuesVec[row + 1].end())
            {
                c3 = 1;
            }
        }

        int num_a_numbers = a1 && a2 ? 1 : a1 && a3 && !a2 ? 2 : a2 && a3 ? 1 : a1 ? 1 : a2 ? 1 : a3 ? 1 : 0;
        int num_b_numbers = b1 && b2 ? 1 : b1 && b3 && !b2 ? 2 : b2 && b3 ? 1 : b1 ? 1 : b2 ? 1 : b3 ? 1 : 0;
        int num_c_numbers = c1 && c2 ? 1 : c1 && c3 && !c2 ? 2 : c2 && c3 ? 1 : c1 ? 1 : c2 ? 1 : c3 ? 1 : 0;
        return num_a_numbers + num_b_numbers + num_c_numbers;
    }

    std::vector<std::set<int>> findGears(const std::vector<std::set<int>>& numValuesVec, const std::vector<std::set<int>>& symbolsVec)
    {
        std::vector<std::set<int>> gears;

        int row = 0;
        for (std::set<int> testGears : symbolsVec)
        {
            std::set<int> finishGears;
            for (int gearCol : testGears)
            {
                if (findNumberOfAdjacent(numValuesVec, row, gearCol) == 2)
                {
                    finishGears.insert(gearCol);
                }
            }
            gears.push_back(finishGears);
            ++row;
        }

        return gears;
    }

    std::vector<std::set<int>> GetGears(std::vector<std::string>& input, std::vector<std::set<int>>& numValuesVec, std::vector<std::set<int>>& symbolsVec)
    {
        input.push_back(".............................................................................................................................................................");

        for (std::string line : input)
        {
            line = line + "....................0"; // don't deal with the issue of last char number - hack
            std::set<int> indexes;
            std::set<int> numValues;
            getNumValues(line, false, numValues, indexes);
            numValuesVec.push_back(numValues);
            symbolsVec.push_back(indexes);
        }

        // Get the symbolsVec, and work out which gears exist
        std::vector<std::set<int>> allGears = findGears(numValuesVec, symbolsVec);
        return allGears;
    }


    long full(std::vector<std::string> input, bool secondPart)
    {
        if (!secondPart)
        {
            return full_firstPart(input);
        }

        std::vector<std::vector<int>> parts;
        std::vector<std::set<int>> numValuesVec;
        std::vector<std::set<int>> symbolsVec;
        std::vector<std::set<int>> allGears = GetGears(input, numValuesVec, symbolsVec);

        int x = 0;
        // reuse value vector but only allow it to match the specific gear we are using
        for (int x = 0; x < allGears.size(); ++x)
        {
            for (int y : allGears[x])
            {
                std::vector<int> p1;
                for (int row = x-1; row <= x+1; ++row)
                {
                    if (!(row >= 0 && row < numValuesVec.size()))
                    {
                        continue;
                    }
                    std::set<int> valuesSet = numValuesVec[row];
                    std::string thisNum;
                    int lastIndexOfNum = -2;
                    int i = 0;
                    for (int index : numValuesVec[row])
                    {
                        if ((lastIndexOfNum < 0 || index - lastIndexOfNum == 1) && index <= input[row].size())
                        {
                            lastIndexOfNum = index;
                            thisNum.push_back(input[row][index]);
                        }
                        else if (lastIndexOfNum >= 0)
                        {
                            bool found = false;
                            for (int j = row - 1; j <= row + 1; ++j)
                            {
                                for (int k = lastIndexOfNum - thisNum.size(); k <= lastIndexOfNum + 1; ++k)
                                {
                                    if (j < 0 || k < 0 || j > input.size() - 1 || k > input[j].size() - 1)
                                    {
                                        continue;
                                    }
                                    if (j == x && k == y) // only this gear
                                    {
                                        // adjacent symbol (diagonally or orthogonally)
                                        // add number
                                        p1.push_back(std::stoi(thisNum));
                                        found = true;
                                        break;
                                    }
                                }
                                if (found)
                                {
                                    break;
                                }
                            }
                            if (index > input[row].size())
                            {
                                break; // because of hack
                            }
                            lastIndexOfNum = index;
                            thisNum = input[row][index];
                        }
                    }
                }
                parts.push_back(p1);
            }
        }
 
        std::sort(parts.begin(), parts.end());
        long total = 0;
        for (std::vector<int> a : parts)
        {
            long totalsq = 0;
            for (int b : a)
            {
                if (totalsq == 0)
                {
                    totalsq = b;
                }
                else
                {
                    totalsq = totalsq * b;
                }
            }
            total = total + totalsq;
        }
        return total;
    }



};