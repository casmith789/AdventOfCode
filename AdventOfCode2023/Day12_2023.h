#pragma once
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>
#include "input_day12_2023.h"
#include "Util.h"

class Day12_2023
{
public:
    Day12_2023() = default;
    ~Day12_2023() = default;

    std::vector<std::string> GetGroups(std::string line)
    {
        line = Util::strip(line, '.');
        std::string line2 = "";
        while (line != line2)
        {
            line2 = line;
            Util::replaceAll(line, "..", ".");
        }

        Util::replaceAll(line, ".#", ";#");
        Util::replaceAll(line, "#.", "#;");
        Util::replaceAll(line, ".?", ";?");
        Util::replaceAll(line, "?.", "?;");
        Util::replaceAll(line, ".@", ";@");
        Util::replaceAll(line, "@.", "@;");

        std::vector<std::string> ret = Util::split(line, ";");
        return ret;
    }

    std::string GetSplit(std::string line, std::vector<int>& sizes)
    {
        sizes.clear();
        std::vector<std::string> a = Util::split(line, " ");
        std::vector<std::string> b = Util::split(a[1], ",");

        for (std::string c : b)
        {
            sizes.push_back(std::stoi(c));
        }

        return a[0];
    }

    std::vector<std::string> GetGroups(std::string line, std::vector<int>& sizes)
    {
        sizes.clear();
        std::vector<std::string> a = Util::split(line, " ");
        std::vector<std::string> b = Util::split(a[1], ",");

        for (std::string c : b)
        {
            sizes.push_back(std::stoi(c));
        }

        std::vector<std::string> ret = GetGroups(a[0]);

        return ret;
    }

    bool IsPossible(std::vector<std::string> groups, std::vector<int> sizes)
    {
        int total = 0;
        for (int size : sizes)
        {
            if (total != 0)
            {
                total = total + 1;
            }
            total = total + size;
        }

        int totalGroups = 0;
        for (std::string group : groups)
        {
            if (totalGroups != 0)
            {
                totalGroups = totalGroups + 1;
            }
            totalGroups = totalGroups + group.length();
        }

        if (total > totalGroups)
        {
            return false;
        }

        int numQuestionMarks = 0;
        for (int i = 0; i < groups.size(); ++i)
        {
            for (int j = 0; j < groups[i].size(); ++j)
            {
                if (groups[i][j] == '?')
                {
                    ++numQuestionMarks;
                }
            }
        }

        if (numQuestionMarks == 0)
        {
            if (groups.size() != sizes.size())
            {
                return false;
            }
            for (int i = 0; i < groups.size(); ++i)
            {
                if (groups[i].length() != sizes[i])
                {
                    return false;
                }
            }
        }

        // TODO
        return true;
    }

    int numWaysBruteForce(std::vector<std::string> groups, std::vector<int> sizes)
    {
        std::string line;
        int numQuestionMarks = 0;
        int numHashes = 0;
        for (int i = 0; i < groups.size(); ++i)
        {
            line = line + groups[i] + ".";
            for (int j = 0; j < groups[i].size(); ++j)
            {
                if (groups[i][j] == '?')
                {
                    ++numQuestionMarks;
                }
                if (groups[i][j] == '#')
                {
                    ++numHashes;
                }
            }
        }
        line = Util::strip(line, '.');
        std::vector<int> qMarkLocations;
        for (int i = 0; i < line.length(); ++i)
        {
            if (line[i] == '?')
            {
                qMarkLocations.push_back(i);
            }
        }

        int total = 0;
        for (int size : sizes)
        {
            total = total + size;
        }

        return numWaysBruteForce(line, qMarkLocations, sizes, total - numHashes);
    }

    int64_t numWaysCache(std::string line, const std::vector<int>& sizes, int currentPos, int currentBucket, int currentPosInBucket, std::map<std::pair<int, std::pair<int, int>>, int64_t>& cache)
    {
        int64_t totalWays = 0;
        if (cache.find(std::make_pair(currentPos, std::make_pair(currentBucket, currentPosInBucket))) != cache.end())
        {
            return cache.at(std::make_pair(currentPos, std::make_pair(currentBucket, currentPosInBucket)));
        }

        if (currentPos == line.length())
        {
            if (currentBucket == sizes.size()-1)
            {
                if (currentPosInBucket == sizes[currentBucket])
                {
                    totalWays = 1;
                }
                else
                {
                    totalWays = 0;
                }
            }
            if (currentBucket == sizes.size())
            {
                if (currentPosInBucket == 0)
                {
                    totalWays = 1;
                }
                else
                {
                    totalWays = 0;
                }
            }

            cache[std::make_pair(currentPos, std::make_pair(currentBucket, currentPosInBucket))] = totalWays;
            return totalWays;
        }


        char c = line[currentPos];
        if (c == '?' || c == '.')
        {
            if (currentPosInBucket == 0)
            {
                totalWays = totalWays + numWaysCache(line, sizes, currentPos + 1, currentBucket, 0, cache);
            }
            else if (sizes.size() > currentBucket && sizes[currentBucket] == currentPosInBucket) 
            {
                totalWays = totalWays + numWaysCache(line, sizes, currentPos + 1, currentBucket + 1, 0, cache);
            }
        }
        if (c == '#' || c == '?')
        {
            totalWays = totalWays + numWaysCache(line, sizes, currentPos + 1, currentBucket, currentPosInBucket + 1, cache);
        }

        cache[std::make_pair(currentPos, std::make_pair(currentBucket, currentPosInBucket))] = totalWays;
        return totalWays;
    }

    int numWaysBruteForce(std::string line, std::vector<int> qMarkLocations, const std::vector<int>& sizes, int numHashesLeft)
    {
        int numQMarks = qMarkLocations.size();
        if (numQMarks == 0)
        {
            Util::replaceAll(line, "@", ".");
            std::vector<std::string> gS = GetGroups(line);
            if (sizes.size() != gS.size())
            {
                return 0;
            }
            for (int i = 0; i < sizes.size(); ++i)
            {
                if (gS[i].length() != sizes[i])
                {
                    return 0;
                }
            }
            return 1;
        }
        else
        {
            std::string newline = line;
            newline[qMarkLocations[qMarkLocations.size() - 1]] = '@';
            std::string newline2 = line;
            newline2[qMarkLocations[qMarkLocations.size() - 1]] = '#';
            qMarkLocations.erase(qMarkLocations.end() - 1);
            int a = numWaysBruteForce(newline, qMarkLocations, sizes, numHashesLeft);
            int b = 0;
            if (numHashesLeft > 0)
            {
                b = numWaysBruteForce(newline2, qMarkLocations, sizes, numHashesLeft - 1);
            }
            return a + b;
        }
    }




    bool Reduce(std::vector<std::string>& groups, std::vector<int> sizes)
    {
        for (int i = 0; i < groups.size(); ++i)
        {
            for (int j = 0; j < groups[i].size(); ++j)
            {
                if (groups[i][j] != '?')
                {
                    continue;
                }
                // Try '.' and make sure it can work
                {
                    std::string newGroup = groups[i];
                    newGroup[j] = '.';
                    std::vector<std::string> newGrpSplit = Util::split(newGroup, ".");
                    if (newGrpSplit[0] == "")
                    {
                        newGrpSplit = std::vector<std::string>{ newGrpSplit[1] };
                    }
                    else if (newGrpSplit[1] == "")
                    {
                        newGrpSplit = std::vector<std::string>{ newGrpSplit[0] };
                    }
                    if (newGrpSplit.size() == 1)
                    {
                        std::vector<std::string> newGroups = groups;
                        newGroups[i] = newGrpSplit[0];
                        if (!IsPossible(newGroups, sizes))
                        {
                            groups[i][j] = '#';
                            return true;
                        }
                    }
                    else
                    {
                        assert(newGrpSplit.size() == 2);
                        std::vector<std::string> newGroups = groups;
                        newGroups[i] = newGrpSplit[1];
                        newGroups.insert(newGroups.begin() + i, newGrpSplit[0]);
                        if (!IsPossible(newGroups, sizes))
                        {
                            groups[i][j] = '#';
                            return true;
                        }
                    }
                }

                // Try '#' and make sure it can work
                std::vector<std::string> newGroups = groups;
                newGroups[i][j] = '#';
                if (!IsPossible(newGroups, sizes))
                {
                    std::string newGroup = groups[i];
                    newGroup[j] = '.';
                    std::vector<std::string> newGrpSplit = Util::split(newGroup, ".");
                    if (newGrpSplit[0] == "")
                    {
                        newGrpSplit = std::vector<std::string>{ newGrpSplit[1] };
                    }
                    else if (newGrpSplit[1] == "")
                    {
                        newGrpSplit = std::vector<std::string>{ newGrpSplit[0] };
                    }
                    if (newGrpSplit.size() == 1)
                    {
                        groups[i] = newGrpSplit[0];
                    }
                    else
                    {
                        assert(newGrpSplit.size() == 2);
                        groups[i] = newGrpSplit[1];
                        groups.insert(groups.begin() + i, newGrpSplit[0]);
                    }
                }
            }
        }

        return false;
    }

    std::vector<std::string> FullyReduce(std::vector<std::string> groups, std::vector<int> sizes)
    {
        while (Reduce(groups, sizes))
        {
            continue;
        }

        return groups;
    }



};