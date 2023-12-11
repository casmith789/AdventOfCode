#include "pch.h"
#include "Day5_2023.h"

TEST(TestDay05_2023, TestMapLine) {
	std::vector<std::string> testMapLines = {
	"50 98 2",
	"52 50 48"
	};
	Day5_2023 day5;
	EXPECT_EQ(day5.GetDestinationVal(98, testMapLines[0]), 50);
	EXPECT_EQ(day5.GetDestinationVal(99, testMapLines[0]), 51);
	EXPECT_EQ(day5.GetDestinationVal(100, testMapLines[0]), -1);

	EXPECT_EQ(day5.GetDestinationVal(50, testMapLines[1]), 52);
	EXPECT_EQ(day5.GetDestinationVal(97, testMapLines[1]), 99);
	EXPECT_EQ(day5.GetDestinationVal(98, testMapLines[1]), -1);

	EXPECT_EQ(day5.GetDestinationValForWholeMap(0, testMapLines), 0);
	EXPECT_EQ(day5.GetDestinationValForWholeMap(1, testMapLines), 1);
	EXPECT_EQ(day5.GetDestinationValForWholeMap(48, testMapLines), 48);
	EXPECT_EQ(day5.GetDestinationValForWholeMap(49, testMapLines), 49);
	EXPECT_EQ(day5.GetDestinationValForWholeMap(50, testMapLines), 52);
	EXPECT_EQ(day5.GetDestinationValForWholeMap(51, testMapLines), 53);
	EXPECT_EQ(day5.GetDestinationValForWholeMap(96, testMapLines), 98);
	EXPECT_EQ(day5.GetDestinationValForWholeMap(97, testMapLines), 99);
	EXPECT_EQ(day5.GetDestinationValForWholeMap(98, testMapLines), 50);
	EXPECT_EQ(day5.GetDestinationValForWholeMap(99, testMapLines), 51);
}

TEST(TestDay05_2023, TestAllMaps) {
	const std::vector<std::string> test_seedInput =
	{
	  "79","14","55","13"
	};

	const std::vector<std::string> test_seed_to_soilInput =
	{
"50 98 2",
"52 50 48"
	};

	const std::vector<std::string> test_soil_to_fertiliserInput =
	{
"0 15 37",
"37 52 2",
"39 0 15"
	};

	const std::vector<std::string> test_fertiliser_to_waterInput =
	{
"49 53 8",
"0 11 42",
"42 0 7",
"57 7 4"
	};

	const std::vector<std::string> test_water_to_lightInput =
	{
"88 18 7",
"18 25 70"
	};

	const std::vector<std::string> test_light_to_temperatureInput =
	{
"45 77 23",
"81 45 19",
"68 64 13"
	};

	const std::vector<std::string> test_temperature_to_humidityInput =
	{
"0 69 1",
"1 0 69"
	};

	const std::vector<std::string> test_humidity_to_locationInput =
	{
"60 56 37",
"56 93 4"
	};

	Day5_2023 day5;
	day5.seed_soil_map = test_seed_to_soilInput;
	day5.soil_fertiliser_map = test_soil_to_fertiliserInput;
	day5.fertiliser_water_map = test_fertiliser_to_waterInput;
	day5.water_light_map = test_water_to_lightInput;
	day5.light_temperature_map = test_light_to_temperatureInput;
	day5.temperature_humidity_map = test_temperature_to_humidityInput;
	day5.humidity_location_map = test_humidity_to_locationInput;

	EXPECT_EQ(day5.GetVal(79ll, Day5_2023::SEED, Day5_2023::SOIL), 81ll);
	EXPECT_EQ(day5.GetVal(79ll, Day5_2023::SEED, Day5_2023::FERTILISER), 81ll);
	EXPECT_EQ(day5.GetVal(79ll, Day5_2023::SEED, Day5_2023::WATER), 81ll);
	EXPECT_EQ(day5.GetVal(79ll, Day5_2023::SEED, Day5_2023::LIGHT), 74ll);
	EXPECT_EQ(day5.GetVal(79ll, Day5_2023::SEED, Day5_2023::TEMPERATURE), 78ll);
	EXPECT_EQ(day5.GetVal(79ll, Day5_2023::SEED, Day5_2023::HUMIDITY), 78ll);
	EXPECT_EQ(day5.GetVal(79ll, Day5_2023::SEED, Day5_2023::LOCATION), 82ll);

	EXPECT_EQ(day5.GetVal(14ll, Day5_2023::SEED, Day5_2023::SOIL), 14ll);
	EXPECT_EQ(day5.GetVal(14ll, Day5_2023::SEED, Day5_2023::FERTILISER), 53ll);
	EXPECT_EQ(day5.GetVal(14ll, Day5_2023::SEED, Day5_2023::WATER), 49ll);
	EXPECT_EQ(day5.GetVal(14ll, Day5_2023::SEED, Day5_2023::LIGHT), 42ll);
	EXPECT_EQ(day5.GetVal(14ll, Day5_2023::SEED, Day5_2023::TEMPERATURE), 42ll);
	EXPECT_EQ(day5.GetVal(14ll, Day5_2023::SEED, Day5_2023::HUMIDITY), 43ll);
	EXPECT_EQ(day5.GetVal(14ll, Day5_2023::SEED, Day5_2023::LOCATION), 43ll);

	EXPECT_EQ(day5.GetVal(55ll, Day5_2023::SEED, Day5_2023::SOIL), 57ll);
	EXPECT_EQ(day5.GetVal(55ll, Day5_2023::SEED, Day5_2023::FERTILISER), 57ll);
	EXPECT_EQ(day5.GetVal(55ll, Day5_2023::SEED, Day5_2023::WATER), 53ll);
	EXPECT_EQ(day5.GetVal(55ll, Day5_2023::SEED, Day5_2023::LIGHT), 46ll);
	EXPECT_EQ(day5.GetVal(55ll, Day5_2023::SEED, Day5_2023::TEMPERATURE), 82ll);
	EXPECT_EQ(day5.GetVal(55ll, Day5_2023::SEED, Day5_2023::HUMIDITY), 82ll);
	EXPECT_EQ(day5.GetVal(55ll, Day5_2023::SEED, Day5_2023::LOCATION), 86ll);

	EXPECT_EQ(day5.GetVal(13ll, Day5_2023::SEED, Day5_2023::SOIL), 13ll);
	EXPECT_EQ(day5.GetVal(13ll, Day5_2023::SEED, Day5_2023::FERTILISER), 52ll);
	EXPECT_EQ(day5.GetVal(13ll, Day5_2023::SEED, Day5_2023::WATER), 41ll);
	EXPECT_EQ(day5.GetVal(13ll, Day5_2023::SEED, Day5_2023::LIGHT), 34ll);
	EXPECT_EQ(day5.GetVal(13ll, Day5_2023::SEED, Day5_2023::TEMPERATURE), 34ll);
	EXPECT_EQ(day5.GetVal(13ll, Day5_2023::SEED, Day5_2023::HUMIDITY), 35ll);
	EXPECT_EQ(day5.GetVal(13ll, Day5_2023::SEED, Day5_2023::LOCATION), 35ll);
}

TEST(TestDay05_2023, Test1)
{
	Day5_2023 day5;

	EXPECT_EQ(day5.GetVal(3737494864ll, Day5_2023::SEED, Day5_2023::SOIL), 2413597751ll);
	EXPECT_EQ(day5.GetVal(3737494864ll, Day5_2023::SEED, Day5_2023::FERTILISER), 1375228664ll);
	EXPECT_EQ(day5.GetVal(3737494864ll, Day5_2023::SEED, Day5_2023::WATER), 613104569ll);
	EXPECT_EQ(day5.GetVal(3737494864ll, Day5_2023::SEED, Day5_2023::LIGHT), 212897158ll);
	EXPECT_EQ(day5.GetVal(3737494864ll, Day5_2023::SEED, Day5_2023::TEMPERATURE), 471900538ll);
	EXPECT_EQ(day5.GetVal(3737494864ll, Day5_2023::SEED, Day5_2023::HUMIDITY), 1667372ll);
	EXPECT_EQ(day5.GetVal(3737494864ll, Day5_2023::SEED, Day5_2023::LOCATION), 525684192ll);

	EXPECT_EQ(day5.full(false), 324724204ll);
}

TEST(TestDay05_2023, Test1Alternate)
{
	Day5_2023 day5;
	EXPECT_EQ(day5.fullAlternate(false), 324724204ll);
}

TEST(TestDay05_2023, Test2Alternate)
{
	Day5_2023 day5;
	EXPECT_EQ(day5.fullAlternate(true), 104070862ll);
}

TEST(TestDay05_2023, ReorderMap)
{
	Day5_2023 day5;
	std::vector<std::string> initialMap = Input2023::day5_seed_to_soil_map;
	day5.ReorderMap(initialMap);
	EXPECT_EQ(initialMap[0], "2493001016 200414015 157177749");
	EXPECT_EQ(initialMap[11], "1442950910 1913571383 198033453");
	EXPECT_EQ(initialMap[19], "3525625564 3935480084 359487212");
}

TEST(TestDay05_2023, TestAllMapsCombine) {
	const std::vector<std::string> test_seedInput =
	{
	  "79","14","55","13"
	};

	const std::vector<std::string> test_seed_to_soilInput =
	{
"50 98 2",
"52 50 48"
	};

	const std::vector<std::string> test_soil_to_fertiliserInput =
	{
"0 15 37",
"37 52 2",
"39 0 15"
	};

	const std::vector<std::string> test_fertiliser_to_waterInput =
	{
"49 53 8",
"0 11 42",
"42 0 7",
"57 7 4"
	};

	const std::vector<std::string> test_water_to_lightInput =
	{
"88 18 7",
"18 25 70"
	};

	const std::vector<std::string> test_light_to_temperatureInput =
	{
"45 77 23",
"81 45 19",
"68 64 13"
	};

	const std::vector<std::string> test_temperature_to_humidityInput =
	{
"0 69 1",
"1 0 69"
	};

	const std::vector<std::string> test_humidity_to_locationInput =
	{
"60 56 37",
"56 93 4"
	};

	{
		Day5_2023 day5;
		std::vector<std::string> newMap = day5.CombineMaps2(test_seed_to_soilInput, test_soil_to_fertiliserInput);
		day5.seed_soil_map = newMap;
		EXPECT_EQ(day5.GetVal(79ll, Day5_2023::SEED, Day5_2023::SOIL), 81ll);
		EXPECT_EQ(day5.GetVal(14ll, Day5_2023::SEED, Day5_2023::SOIL), 53ll);

		newMap = day5.CombineMaps2(newMap, test_fertiliser_to_waterInput);
		day5.seed_soil_map = newMap;
		EXPECT_EQ(day5.GetVal(79ll, Day5_2023::SEED, Day5_2023::SOIL), 81ll);
		EXPECT_EQ(day5.GetVal(14ll, Day5_2023::SEED, Day5_2023::SOIL), 49ll);

		newMap = day5.CombineMaps2(newMap, test_water_to_lightInput);
		day5.seed_soil_map = newMap;
		EXPECT_EQ(day5.GetVal(79ll, Day5_2023::SEED, Day5_2023::SOIL), 74ll);
		EXPECT_EQ(day5.GetVal(14ll, Day5_2023::SEED, Day5_2023::SOIL), 42ll);

		newMap = day5.CombineMaps2(newMap, test_light_to_temperatureInput);
		day5.seed_soil_map = newMap;
		EXPECT_EQ(day5.GetVal(79ll, Day5_2023::SEED, Day5_2023::SOIL), 78ll);
		EXPECT_EQ(day5.GetVal(14ll, Day5_2023::SEED, Day5_2023::SOIL), 42ll);

		newMap = day5.CombineMaps2(newMap, test_temperature_to_humidityInput);
		day5.seed_soil_map = newMap;
		EXPECT_EQ(day5.GetVal(79ll, Day5_2023::SEED, Day5_2023::SOIL), 78ll);
		EXPECT_EQ(day5.GetVal(14ll, Day5_2023::SEED, Day5_2023::SOIL), 43ll);

		newMap = day5.CombineMaps2(newMap, test_humidity_to_locationInput);
		day5.seed_soil_map = newMap;
		EXPECT_EQ(day5.GetVal(79ll, Day5_2023::SEED, Day5_2023::SOIL), 82ll);
		EXPECT_EQ(day5.GetVal(14ll, Day5_2023::SEED, Day5_2023::SOIL), 43ll);
	}
}
