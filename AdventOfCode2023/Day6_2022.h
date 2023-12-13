#pragma once
#include <string>
#include <iostream>
#include "input_day6_2022.h"
#include "Util.h"

class Day6_2022
{
public:
    Day6_2022() = default;
    ~Day6_2022() = default;

    int ans(std::string input, int numDistinct)
    {
        std::vector<char> chars;
        for (int j = 0; j < numDistinct; ++j)
        {
            chars.push_back('@');
        }
        int i = 0;
        for (char c : input)
        {
            ++i;

            for (int j = 1; j < numDistinct; ++j)
            {
                chars[j - 1] = chars[j];
            }
            chars[numDistinct - 1] = c;

            bool cont = false;
            for (int j = 0; j < numDistinct; ++j)
            {
                if (chars[j] == '@')
                {
                    cont = true;
                    break;
                }
            }
            if (cont)
            {
                continue;
            }

            std::set<char> s;
            for (int j = 0; j < numDistinct; ++j)
            {
                s.insert(chars[j]);
            }

            if (s.size() == numDistinct)
            {
                return i;
            }
        }
        return i;
    }
};