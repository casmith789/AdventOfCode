#include "pch.h"
#include "Day7_2023.h"
#include "input_day7_2023.h"

TEST(TestDay7_2023, TestHandTypes) {
	Day7_2023 day7;
	EXPECT_EQ(day7.type("AAAAA", false), Day7_2023::FIVE_KIND);
	EXPECT_EQ(day7.type("AA8AA", false), Day7_2023::FOUR_KIND);
	EXPECT_EQ(day7.type("T44T4", false), Day7_2023::FULL_HOUSE);
	EXPECT_EQ(day7.type("98333", false), Day7_2023::THREE_KIND);
	EXPECT_EQ(day7.type("QQKK2", false), Day7_2023::TWO_PAIR);
	EXPECT_EQ(day7.type("43878", false), Day7_2023::ONE_PAIR);
	EXPECT_EQ(day7.type("J43K2", false), Day7_2023::HIGH_CARD);

	EXPECT_EQ(day7.type("AAAAA", true), Day7_2023::FIVE_KIND);
	EXPECT_EQ(day7.type("AAJAA", true), Day7_2023::FIVE_KIND);
	EXPECT_EQ(day7.type("T44TJ", true), Day7_2023::FULL_HOUSE);
	EXPECT_EQ(day7.type("98J33", true), Day7_2023::THREE_KIND);
	EXPECT_EQ(day7.type("QQKJ2", true), Day7_2023::THREE_KIND);
	EXPECT_EQ(day7.type("43J78", true), Day7_2023::ONE_PAIR);
	EXPECT_EQ(day7.type("J43K2", true), Day7_2023::ONE_PAIR);
}

TEST(TestDay7_2023, Example) {
	Day7_2023 day7;
	std::vector<std::string> input = {
	"32T3K 765",
	"T55J5 684",
	"KK677 28",
	"KTJJT 220",
	"QQQJA 483" };

	int res = day7.result(input, false);
	EXPECT_EQ(res, 6440);

	res = day7.result(input, true);
	EXPECT_EQ(res, 5905);
}

TEST(TestDay7_2023, Test1) {
	Day7_2023 day7;

	long res = day7.result(Input2023::day7_input, false);
	EXPECT_EQ(res, 252052080);
}

TEST(TestDay7_2023, Test2) {
	Day7_2023 day7;

	long res = day7.result(Input2023::day7_input, true);
	EXPECT_EQ(res, 252898370);
}