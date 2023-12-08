#pragma once
#include <string>
#include <iostream>
#include "input_day1_2023.h"
#include "Util.h"

class Day1_2023
{
public:
	Day1_2023() = default;
	~Day1_2023() = default;


    int lineValue(std::string line, bool secondPart)
    {
        std::string originalLine = line;
        int first_num = 0;
        int last_num = 0;
        bool setfirst = false;
        if (secondPart)
        {
            Util::replaceAll(line, "one", "o1e");
            Util::replaceAll(line, "two", "t2o");
            Util::replaceAll(line, "three", "t3e");
            Util::replaceAll(line, "four", "f4r");
            Util::replaceAll(line, "five", "f5e");
            Util::replaceAll(line, "six", "s6x");
            Util::replaceAll(line, "seven", "s7n");
            Util::replaceAll(line, "eight", "e8t");
            Util::replaceAll(line, "nine", "n9e");
        }
        for (char c : line)
        {
            if (c >= '0' && c <= '9')
            {
                if (!setfirst)
                {
                    setfirst = true;
                    first_num = c - '0';
                }
                last_num = c - '0';
            }
        }

        long lineNum = first_num * 10 + last_num;
        //std::cout << originalLine << std::endl;
        //std::cout << line << std::endl;
        //std::cout << lineNum << std::endl;
        return lineNum;
    }


    long full(bool secondPart)
    {
        std::vector<std::string> input = Input2023::day1_input;
        long total = 0;
        for (std::string line : input)
        {
            total = total + lineValue(line, secondPart);
        }
        return total;
    }



};

