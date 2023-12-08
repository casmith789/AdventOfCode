#pragma once
#include <string>
#include <iostream>
#include "Util.h"

class Day6_2023
{
public:
    Day6_2023() = default;
    ~Day6_2023() = default;

    int64_t calc(int64_t time, int64_t dist)
    {
        int64_t total = 0;
        for (int64_t i = 0; i < time; ++i)
        {
            if (i * (time - i) > dist)
            {
                ++total;
            }
        }
        return total;
    }


    int64_t example()
    {
        int64_t w1 = calc(7, 9);
        int64_t w2 = calc(15, 40);
        int64_t w3 = calc(30, 200);
        return w1 * w2 * w3;
    }

    int64_t full()
    {
        int64_t w1 = calc(55, 246);
        int64_t w2 = calc(82, 1441);
        int64_t w3 = calc(64, 1012);
        int64_t w4 = calc(90, 1111);

        return w1 * w2 * w3 * w4;
    }



};
