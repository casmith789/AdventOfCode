#pragma once
#include <string>
#include <iostream>
#include "Util.h"

class Day15_2023
{
public:
    Day15_2023() = default;
    ~Day15_2023() = default;

    int hashFn(std::string entry, int total)
    {
        for (char c : entry)
        {
            total = total + (int)c;
            total = total * 17;
            total = total % 256;
        }
        return total;
    }

    int hashAll(std::string all)
    {
        int total = 0;
        std::vector<std::string> entries = Util::split(all, ",");
        for (std::string entry : entries)
        {
            total = hashFn(entry, total);
        }
        return total;
    }

    std::vector<std::vector<std::pair<std::string, int>>> createHashMap()
    {
        std::vector<std::vector<std::pair<std::string, int>>> hm;
        for (int i = 0; i < 256; ++i)
        {
            hm.push_back(std::vector<std::pair<std::string, int>>());
        }

        return hm;
    }

    void applyStep(std::string step, std::vector<std::vector<std::pair<std::string,int>>>& hashMap)
    {
        if (Util::stringContains(step, "="))
        {
            std::vector<std::string> s = Util::split(step, "=");
            int hashNum = hashAll(s[0]);
            bool found = false;
            for (int i = 0; i < hashMap[hashNum].size(); ++i)
            {
                std::pair<std::string, int>& entry = hashMap[hashNum][i];
                if (s[0] == entry.first)
                {
                    entry.second = std::stoi(s[1]);
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                hashMap[hashNum].push_back(std::make_pair(s[0], std::stoi(s[1])));
            }
        }
        else if (Util::stringContains(step, "-"))
        {
            std::vector<std::string> s = Util::split(step, "-");
            int hashNum = hashAll(s[0]);
            bool found = false;
            int i = 0;
            for (; i < hashMap[hashNum].size(); ++i)
            {
                std::pair<std::string, int> entry = hashMap[hashNum][i];
                if (s[0] == entry.first)
                {
                    found = true;
                    break;
                }
            }
            if (found)
            {
                hashMap[hashNum].erase(hashMap[hashNum].begin() + i);
            }
        }
        else
        {
            assert(false);
        }
    }

    int64_t getValue(std::vector<std::vector<std::pair<std::string, int>>>& hashMap)
    {
        int64_t total = 0;
        for (int i = 0; i < hashMap.size(); ++i)
        {
            for (int j = 0; j < hashMap[i].size(); ++j)
            {
                std::pair<std::string, int> e = hashMap[i][j];
                total = total + ((i + 1) * (j + 1) * e.second);
            }
        }
        return total;
    }

};