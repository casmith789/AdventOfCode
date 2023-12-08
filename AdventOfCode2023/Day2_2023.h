#pragma once
#include <string>
#include <iostream>
#include <regex>
#include "input_day2_2023.h"
#include "Util.h"

class Day2_2023
{
public:
    Day2_2023() = default;
    ~Day2_2023() = default;

    void GetValues(std::string game, int& red, int& blue, int& green)
    {
        {
            std::regex str_expr("(.* )*([0-9]*)( red.*)");
            std::smatch sm;
            if (std::regex_match(game, sm, str_expr))
            {
                red = std::max(red, std::stoi(sm[2]));
            }
        }
        {
            std::regex str_expr("(.* )*([0-9]*)( blue.*)");
            std::smatch sm;
            if (std::regex_match(game, sm, str_expr))
            {
                blue = std::max(blue, std::stoi(sm[2]));
            }
        }
        {
            std::regex str_expr("(.* )*([0-9]*)( green.*)");
            std::smatch sm;
            if (std::regex_match(game, sm, str_expr))
            {
                green = std::max(green, std::stoi(sm[2]));
            }
        }
    }


    bool isPossible(std::string game)
    {
        int redposs = 12;
        int greenposs = 13;
        int blueposs = 14;
        {
            std::regex str_expr("(.* )*([0-9]*)( red.*)");
            std::smatch sm;
            if (std::regex_match(game, sm, str_expr))
            {
                int num = std::stoi(sm[2]);
                //std::cout << num << " red understood." << std::endl;
                if (num > redposs)
                {
                    return false;
                }
            }
        }
        {
            std::regex str_expr("(.* )*([0-9]*)( blue.*)");
            std::smatch sm;
            if (std::regex_match(game, sm, str_expr))
            {
                int num = std::stoi(sm[2]);
                //std::cout << num << " blue understood." << std::endl;
                if (num > blueposs)
                {
                    return false;
                }
            }
        }
        {
            std::regex str_expr("(.* )*([0-9]*)( green.*)");
            std::smatch sm;
            if (std::regex_match(game, sm, str_expr))
            {
                int num = std::stoi(sm[2]);
                //std::cout << num << " green understood." << std::endl;
                if (num > greenposs)
                {
                    return false;
                }
            }
        }
        return true;
    }

    int lineValue(std::string line, bool secondPart)
    {
        std::string originalLine = line;
        int id = 0;
        bool setfirst = false;
        Util::replaceAll(line, "Game", "");
        {
            std::size_t found = line.find(":");
            if (found != std::string::npos)
            {
                id = std::stoi(line.substr(0, found));
                line = line.substr(found+1);
            }
        }
        int red = 0;
        int blue = 0;
        int green = 0;

        bool cont = true;
        while (cont)
        {

            std::size_t found = line.find(";");
            if (found == std::string::npos)
            {
                found = 32767;
                cont = false;
            }
            std::string game = line.substr(0, found);
            if (!secondPart)
            {
                if (!isPossible(game))
                {
                    id = 0;
                    cont = false;
                }
            }
            else
            {
                GetValues(game, red, blue, green);
            }
            if (cont)
            {
                line = line.substr(found + 1);
            }
        }

        if (!secondPart)
        {
            return id;
        }
        else
        {
            return (long)red * (long)blue * (long)green;
        }
    }


    long full(bool secondPart)
    {
        std::vector<std::string> input = Input2023::day2_input;
        long total = 0;
        for (std::string line : input)
        {
            total = total + lineValue(line, secondPart);
        }
        return total;
    }



};

