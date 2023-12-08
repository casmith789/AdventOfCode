#pragma once
#include "Util.h"

class Day7_2023
{
public:
    Day7_2023() = default;
    ~Day7_2023() = default;

    enum Type
    {
        HIGH_CARD,
        ONE_PAIR,
        TWO_PAIR,
        THREE_KIND,
        FULL_HOUSE,
        FOUR_KIND,
        FIVE_KIND
    };

    int cardIndex(char letter, bool secondPart)
    {
        if (letter == 'A')
        {
            return 14;
        }
        else if (letter == 'T')
        {
            return 10;
        }
        else if (letter == 'J')
        {
            if (!secondPart)
            {
                return 11;
            }
            else
            {
                return 1;
            }
        }
        else if (letter == 'Q')
        {
            return 12;
        }
        else if (letter == 'K')
        {
            return 13;
        }
        else
        {
            return letter - '0';
        }
    }

    bool betterHand(std::string hand1, std::string hand2, bool secondPart)
    {
        if (type(hand1, secondPart) > type(hand2, secondPart))
        {
            return true;
        }
        else if (type(hand2, secondPart) > type(hand1, secondPart))
        {
            return false;
        }
        else
        {
            for (int i = 0; i < 5; ++i)
            {
                if (cardIndex(hand1[i], secondPart) > cardIndex(hand2[i], secondPart))
                {
                    return true;
                }
                else if (cardIndex(hand2[i], secondPart) > cardIndex(hand1[i], secondPart))
                {
                    return false;
                }
            }
        }

        return false;
    }

    Type type(std::string hand, bool secondPart)
    {
        int cards[15];
        for (int i = 0; i < 15; ++i)
        {
            cards[i] = 0;
        }

        for (char c : hand)
        {
            cards[cardIndex(c, secondPart)] += 1;
        }

        int highestStack = 0;
        int secondHighestStack = 0;
        int thirdHighestStack = 0;
        int fourthHighestStack = 0;

        for (int i = 0; i < 15; ++i)
        {
            if (cards[i] > 0)
            {
                if (cards[i] > highestStack)
                {
                    fourthHighestStack = thirdHighestStack;
                    thirdHighestStack = secondHighestStack;
                    secondHighestStack = highestStack;
                    highestStack = cards[i];
                }
                else if (cards[i] > secondHighestStack)
                {
                    fourthHighestStack = thirdHighestStack;
                    thirdHighestStack = secondHighestStack;
                    secondHighestStack = cards[i];
                }
                else if (cards[i] > thirdHighestStack)
                {
                    fourthHighestStack = thirdHighestStack;
                    thirdHighestStack = cards[i];
                }
                else
                {
                    fourthHighestStack = cards[i];
                }
            }
        }

        if (secondPart)
        {
            if (cards[1] > 0)
            {
                if (cards[1] == 5)
                {
                    return FIVE_KIND;
                }
                if (cards[1] == 4)
                {
                    return FIVE_KIND;
                }
                if (cards[1] == 3)
                {
                    if (secondHighestStack == 2)
                    {
                        return FIVE_KIND;
                    }
                    else
                    {
                        return FOUR_KIND;
                    }
                }
                if (cards[1] == 2)
                {
                    if (highestStack == 3)
                    {
                        return FIVE_KIND;
                    }
                    else if (highestStack == 2 && secondHighestStack == 2)
                    {
                        return FOUR_KIND;
                    }
                    else if (secondHighestStack == 1)
                    {
                        return THREE_KIND;
                    }
                }
                if (cards[1] == 1)
                {
                    if (highestStack == 4)
                    {
                        return FIVE_KIND;
                    }
                    if (highestStack == 3)
                    {
                        return FOUR_KIND;
                    }
                    if (highestStack == 2)
                    {
                        if (secondHighestStack == 2)
                        {
                            return FULL_HOUSE;
                        }

                        return THREE_KIND;
                    }
                    if (highestStack == 1)
                    {
                        return ONE_PAIR;
                    }
                }
            }
        }


        if (highestStack == 5)
        {
            return FIVE_KIND;
        }
        else if (highestStack == 4)
        {
            return FOUR_KIND;
        }
        else if (highestStack == 3)
        {
            if (secondHighestStack == 2)
            {
                return FULL_HOUSE;
            }
            else
            {
                return THREE_KIND;
            }
        }
        else if (highestStack == 2)
        {
            if (secondHighestStack == 2)
            {
                return TWO_PAIR;
            }
            else
            {
                return ONE_PAIR;
            }
        }
        else
        {
            return HIGH_CARD;
        }
    }

    std::vector<std::pair<std::string, int>> formUnsortedList(std::vector<std::string> input)
    {
        std::vector<std::pair<std::string, int>> ret;
        for (std::string line : input)
        {
            std::vector<std::string> eachNum = Util::split(line, " ");
            ret.push_back(std::make_pair(eachNum[0], std::stoi(eachNum[1])));
        }
        return ret;
    }

    std::vector<std::pair<std::string, int>> sortList(std::vector<std::pair<std::string, int>> input, bool secondPart)
    {
        std::sort(input.begin(), input.end(), [&](const std::pair<std::string, int>& mapLine1, const std::pair<std::string, int>& mapLine2)
            {
                return !betterHand(mapLine1.first, mapLine2.first, secondPart);
            });
        return input;
    }

    long result(std::vector<std::string> input, bool secondPart)
    {
        long total = 0;
        std::vector<std::pair<std::string, int>> list = formUnsortedList(input);
        list = sortList(list, secondPart);
        for (int i = 0; i < list.size(); ++i)
        {
            total = total + (i + 1) * list[i].second;
        }

        return total;
    }
};
