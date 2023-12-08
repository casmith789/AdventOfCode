#pragma once
#include <string>
#include <iostream>
#include <algorithm>
#include <set>
#include "input_day5_2023.h"
#include "Util.h"

class Day5_2023
{
public:
    Day5_2023() = default;
    ~Day5_2023() = default;

    std::vector<std::string> seed_soil_map = Input2023::day5_seed_to_soil_map;
    std::vector<std::string> soil_fertiliser_map = Input2023::day5_soil_to_fertiliser_map;
    std::vector<std::string> fertiliser_water_map = Input2023::day5_fertiliser_to_water_map;
    std::vector<std::string> water_light_map = Input2023::day5_water_to_light_map;
    std::vector<std::string> light_temperature_map = Input2023::day5_light_to_temperature_map;
    std::vector<std::string> temperature_humidity_map = Input2023::day5_temperature_to_humidity_map;
    std::vector<std::string> humidity_location_map = Input2023::day5_humidity_to_location_map;

    enum GrowthStage
    {
        SEED,
        SOIL,
        FERTILISER,
        WATER,
        LIGHT,
        TEMPERATURE,
        HUMIDITY,
        LOCATION
    };

    // returns -1 if doesn't exist
    int64_t GetDestinationVal(int64_t source, std::string mapLine)
    {
        std::vector<std::string> eachNum = Util::split(mapLine, " ");
        int64_t mapDest = std::stoll(eachNum[0]);
        int64_t mapSource = std::stoll(eachNum[1]);
        int64_t totalNumbers = std::stoll(eachNum[2]);

        int64_t mapSourceMin = mapSource;
        int64_t mapSourceMax = mapSource + totalNumbers;

        if (source >= mapSourceMin && source < mapSourceMax)
        {
            // found in map
            return (source - mapSource) + mapDest;
        }

        return -1;
    }

    void ReorderMap(std::vector<std::string>& mapLines)
    {
        std::sort(mapLines.begin(), mapLines.end(), [](const std::string& mapLine1, const std::string& mapLine2) {
            return std::stoll(Util::split(mapLine1, " ")[1]) < std::stoll(Util::split(mapLine2, " ")[1]);
            });
    }

    std::set<int64_t> WhereToSplitMaps(std::vector<std::string> map1, std::vector<std::string> map2)
    {
        std::set<int64_t> ret;
        for (std::string map1Line : map1)
        {
            std::vector<std::string> eachNum = Util::split(map1Line, " ");
            int64_t map1Dest = std::stoll(eachNum[0]);
            int64_t map1Source = std::stoll(eachNum[1]);
            int64_t totalNumbers1 = std::stoll(eachNum[2]);
            ret.insert(map1Dest);
            ret.insert(map1Dest + totalNumbers1 + 1);
        }

        for (std::string map2Line : map2)
        {
            std::vector<std::string> eachNum2 = Util::split(map2Line, " ");
            int64_t map2Dest = std::stoll(eachNum2[0]);
            int64_t map2Source = std::stoll(eachNum2[1]);
            int64_t totalNumbers2 = std::stoll(eachNum2[2]);
            ret.insert(map2Source);
            ret.insert(map2Source + totalNumbers2 + 1);
        }

        return ret;
    }

    std::vector<std::pair<int64_t, int64_t>> SplitMap1(std::vector<std::string> map1, std::set<int64_t> onSplit)
    {
        ReorderMap(map1);
        std::vector<std::pair<int64_t, int64_t>> newMap1;

        for (int64_t a : onSplit)
        {
            bool found = false;
            for (std::string map1Line : map1)
            {
                std::vector<std::string> eachNum = Util::split(map1Line, " ");
                int64_t map1Dest = std::stoll(eachNum[0]);
                int64_t map1Source = std::stoll(eachNum[1]);
                int64_t totalNumbers1 = std::stoll(eachNum[2]);
                if (a >= map1Dest && a < map1Dest + totalNumbers1)
                {
                    newMap1.push_back(std::make_pair(map1Source + a - map1Dest, a));
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                newMap1.push_back(std::make_pair(a, a));
            }
        }

        return newMap1;
    }

    std::vector<std::pair<int64_t, int64_t>> SplitMap2(std::vector<std::string> map2, std::set<int64_t> onSplit)
    {
        ReorderMap(map2);
        std::vector<std::pair<int64_t, int64_t>> newMap2;

        for (int64_t a : onSplit)
        {
            bool found = false;
            for (std::string map2Line : map2)
            {
                std::vector<std::string> eachNum = Util::split(map2Line, " ");
                int64_t map2Dest = std::stoll(eachNum[0]);
                int64_t map2Source = std::stoll(eachNum[1]);
                int64_t totalNumbers1 = std::stoll(eachNum[2]);
                if (a >= map2Source && a < map2Source + totalNumbers1)
                {
                    newMap2.push_back(std::make_pair(a, map2Dest + a - map2Source));
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                newMap2.push_back(std::make_pair(a, a));
            }
        }

        return newMap2;
    }


    std::vector<std::string> CombineMaps2(std::vector<std::string> map1, std::vector<std::string> map2)
    {
        ReorderMap(map1);
        ReorderMap(map2);
        std::set<int64_t> splits = WhereToSplitMaps(map1, map2);
        std::vector<std::pair<int64_t, int64_t>> res = SplitMap1(map1, splits);
        std::vector<std::pair<int64_t, int64_t>> res2 = SplitMap2(map2, splits);

        std::vector<std::string> newMap;

        for (int i = 0; i < res.size() - 1; ++i)
        {
            int64_t source = res[i].first;
            int64_t dest = res2[i].second;
            int64_t totalNum = res[i + 1].second - res[i].second;

            std::string newMapLine = std::to_string(dest) + " " + std::to_string(source) + " " + std::to_string(totalNum);
            newMap.push_back(newMapLine);
        }
        ReorderMap(newMap);
        return newMap;
    }


  //  std::vector<std::string> CombineMaps(std::vector<std::string> map1, std::vector<std::string> map2)
  //  {
  //      std::vector<std::string> newMap;
  //      ReorderMap(map1);
  //      ReorderMap(map2);
  //      // map 1: get first source section (source + number of values)
  //      // map 1: figure out destination section (dest + number of values)
  //      // map 2: find destination section, across potentially many sections
  //      // new map: map source to destination for each section
  //      // add this to new map
  //      // repeat
  //      // add remaining map1 that did not go forwards
  //      for (std::string map1Line : map1)
  //      {
  //          std::vector<std::string> eachNum = Util::split(map1Line, " ");
  //          int64_t map1Dest = std::stoll(eachNum[0]);
  //          int64_t map1Source = std::stoll(eachNum[1]);
  //          int64_t totalNumbers1 = std::stoll(eachNum[2]);

  //          int64_t map1DestMin = map1Dest;
  //          int64_t map1DestMax = map1Dest + totalNumbers1;
  //          for (std::string map2Line : map2)
  //          {
  //              std::vector<std::string> eachNum2 = Util::split(map2Line, " ");
  //              int64_t map2Dest = std::stoll(eachNum2[0]);
  //              int64_t map2Source = std::stoll(eachNum2[1]);
  //              int64_t totalNumbers2 = std::stoll(eachNum2[2]);

  //              int64_t map2SourceMin = map2Source;
  //              int64_t map2SourceMax = map2Source + totalNumbers2;

  //              int64_t map2sourceMinComp = map2SourceMin > map1DestMin ? map2SourceMin : map1DestMin;
  //              int64_t map2sourceMaxComp = map2SourceMax < map1DestMax ? map2SourceMax : map1DestMax;

  //              int64_t sourceMin = (map2sourceMinComp - map1DestMin) + map1Source;
  //              int64_t sourceMax = (map2sourceMaxComp - map1DestMin) + map1Source;
  //              if (sourceMax <= sourceMin)
  //              {
  //                  continue;
  //              }

  //              int64_t totalNumbers = sourceMax - sourceMin;
  //              int64_t sourceNum = sourceMin;
  //              int64_t destNum = (sourceMin - map1Source + map1Dest) - map2Source + map2Dest;
  //              std::string newMapLine = std::to_string(destNum) + " " + std::to_string(sourceNum) + " " + std::to_string(totalNumbers);
  //              newMap.push_back(newMapLine);
  //          }
  //      }

  //      {
  //          std::vector<std::string> beforeChanges;
  //          while (map1 != beforeChanges)
  //          {
  //              beforeChanges = map1;
  //              int index = 0;
  //              bool changed = false;
  //              for (std::string map1Line : map1)
  //              {
  //                  std::vector<std::string> eachNum = Util::split(map1Line, " ");
  //                  int64_t map1Dest = std::stoll(eachNum[0]);
  //                  int64_t map1Source = std::stoll(eachNum[1]);
  //                  int64_t totalNumbers1 = std::stoll(eachNum[2]);

  //                  int64_t map1SourceMin = map1Source;
  //                  int64_t map1SourceMax = map1Source + totalNumbers1;
  //                  for (std::string map2Line : newMap)
  //                  {
  //                      std::vector<std::string> eachNum2 = Util::split(map2Line, " ");
  //                      int64_t map2Dest = std::stoll(eachNum2[0]);
  //                      int64_t map2Source = std::stoll(eachNum2[1]);
  //                      int64_t totalNumbers2 = std::stoll(eachNum2[2]);
  //                      if (map2Source + totalNumbers2 <= map1SourceMax && map2Source >= map1SourceMin)
  //                      {
  //                          if (map2Source > map1SourceMin)
  //                          {
  //                              int64_t newSourceMin = map1SourceMin;
  //                              int64_t newTotalNum = map2Source - map1SourceMin;
  //                              int64_t newDest = map1Dest;
  //                              std::string newMapLine = std::to_string(newDest) + " " + std::to_string(newSourceMin) + " " + std::to_string(newTotalNum);
  //                              map1.push_back(newMapLine);


  //                          }
  //                          if (map2Source + totalNumbers2 < map1SourceMax - 1)
  //                          {
  //                              int64_t newSourceMin = map2Source + totalNumbers2;
  //                              int64_t newTotalNum = map1SourceMax - newSourceMin;
  //                              int64_t newDest = map1Dest + (newSourceMin - map1SourceMin);
  //                              std::string newMapLine = std::to_string(newDest) + " " + std::to_string(newSourceMin) + " " + std::to_string(newTotalNum);
  //                              map1.push_back(newMapLine);
  //                          }
  //                          // if neither above is true - remove line with same source
  //                          changed = true;
  //                      }
  //                      if (changed)
  //                      {
  //                          break;
  //                      }
  //                  }
  //                  if (changed)
  //                  {
  //                      map1.erase(map1.begin() + index);
  //                      break;
  //                  }
  //                  ++index;
  //              }
  //          }
  //      }
  //      for (auto i : map1)
  //      {
  //          newMap.push_back(i);
  //      }

		//{
		//	std::vector<std::string> beforeChanges;
		//	while (map2 != beforeChanges)
		//	{
		//		beforeChanges = map2;
		//		int index = 0;
		//		bool changed = false;
		//		for (std::string map1Line : map2)
		//		{
		//			std::vector<std::string> eachNum = Util::split(map1Line, " ");
		//			int64_t map1Dest = std::stoll(eachNum[0]);
		//			int64_t map1Source = std::stoll(eachNum[1]);
		//			int64_t totalNumbers1 = std::stoll(eachNum[2]);

		//			int64_t map1SourceMin = map1Source;
		//			int64_t map1SourceMax = map1Source + totalNumbers1;
		//			for (std::string map2Line : newMap)
		//			{
		//				std::vector<std::string> eachNum2 = Util::split(map2Line, " ");
		//				int64_t map2Dest = std::stoll(eachNum2[0]);
		//				int64_t map2Source = std::stoll(eachNum2[1]);
		//				int64_t totalNumbers2 = std::stoll(eachNum2[2]);
		//				if (map2Source + totalNumbers2 <= map1SourceMax && map2Source >= map1SourceMin)
		//				{
		//					if (map2Source > map1SourceMin)
		//					{
		//						int64_t newSourceMin = map1SourceMin;
		//						int64_t newTotalNum = map2Source - map1SourceMin;
		//						int64_t newDest = map1Dest;
		//						std::string newMapLine = std::to_string(newDest) + " " + std::to_string(newSourceMin) + " " + std::to_string(newTotalNum);
		//						map2.push_back(newMapLine);


		//					}
		//					if (map2Source + totalNumbers2 < map1SourceMax - 1)
		//					{
		//						int64_t newSourceMin = map2Source + totalNumbers2;
		//						int64_t newTotalNum = map1SourceMax - newSourceMin;
		//						int64_t newDest = map1Dest + (newSourceMin - map1SourceMin);
		//						std::string newMapLine = std::to_string(newDest) + " " + std::to_string(newSourceMin) + " " + std::to_string(newTotalNum);
		//						map2.push_back(newMapLine);
		//					}
		//					// if neither above is true - remove line with same source
		//					changed = true;
		//				}
  //                      if (map2Source < map1SourceMax && map2Source >= map1SourceMin)
  //                      {
  //                          changed = true;
  //                      }
		//				if (changed)
		//				{
		//					break;
		//				}
		//			}
		//			if (changed)
		//			{
		//				map2.erase(map2.begin() + index);
		//				break;
		//			}
		//			++index;
		//		}
		//	}
		//}
  //      for (auto i : map2)
  //      {
  //          newMap.push_back(i);
  //      }
  //              

  //      return newMap;
  //  }

    int64_t GetDestinationValForWholeMap(int64_t source, std::vector<std::string> mapLines)
    {
        for (std::string mapLine : mapLines)
        {
            int64_t ans = GetDestinationVal(source, mapLine);
            if (ans != -1)
            {
                return ans;
            }
        }
        return source;
    }

    int64_t GetVal(int64_t source, GrowthStage sourceSt, GrowthStage destSt)
    {
        if (sourceSt == SEED)
        {
            source = GetDestinationValForWholeMap(source, seed_soil_map);
            sourceSt = SOIL;
        }

        if (destSt == SOIL)
        {
            return source;
        }

        if (sourceSt == SOIL)
        {
            source = GetDestinationValForWholeMap(source, soil_fertiliser_map);
            sourceSt = FERTILISER;
        }

        if (destSt == FERTILISER)
        {
            return source;
        }

        if (sourceSt == FERTILISER)
        {
            source = GetDestinationValForWholeMap(source, fertiliser_water_map);
            sourceSt = WATER;
        }

        if (destSt == WATER)
        {
            return source;
        }

        if (sourceSt == WATER)
        {
            source = GetDestinationValForWholeMap(source, water_light_map);
            sourceSt = LIGHT;
        }

        if (destSt == LIGHT)
        {
            return source;
        }

        if (sourceSt == LIGHT)
        {
            source = GetDestinationValForWholeMap(source, light_temperature_map);
            sourceSt = TEMPERATURE;
        }

        if (destSt == TEMPERATURE)
        {
            return source;
        }

        if (sourceSt == TEMPERATURE)
        {
            source = GetDestinationValForWholeMap(source, temperature_humidity_map);
            sourceSt = HUMIDITY;
        }

        if (destSt == HUMIDITY)
        {
            return source;
        }

        if (sourceSt == HUMIDITY)
        {
            source = GetDestinationValForWholeMap(source, humidity_location_map);
            sourceSt = LOCATION;
        }

        if (destSt == LOCATION)
        {
            return source;
        }

        return -1;
    }

    int64_t fullAlternate(bool secondPart)
    {
        int64_t lowestLocation = std::numeric_limits<int64_t>::max();
        if (!secondPart)
        {
            std::vector<std::string> newMap = CombineMaps2(seed_soil_map, soil_fertiliser_map);
            newMap = CombineMaps2(newMap, fertiliser_water_map);
            newMap = CombineMaps2(newMap, water_light_map);
            newMap = CombineMaps2(newMap, light_temperature_map);
            newMap = CombineMaps2(newMap, temperature_humidity_map);
            newMap = CombineMaps2(newMap, humidity_location_map);
            ReorderMap(newMap);
            std::vector<std::string> input = Input2023::day5_seedInput;
            for (std::string s : input)
            {
                int64_t seed = std::stoll(s);
                int64_t location = GetDestinationValForWholeMap(seed, newMap);
                if (location < lowestLocation)
                {
                    lowestLocation = location;
                }
            }

            return lowestLocation;
        }
        else
        {
            // make fake seed map
            std::vector<std::string> seedMap;
            std::vector<std::string> input = Input2023::day5_seedInput;
            bool odd = false;
            int64_t seed = 0;
            for (std::string s : input)
            {
                if (!odd)
                {
                    seed = std::stoll(s);
                    odd = true;
                }
                else
                {
                    int64_t length = std::stoll(s);
                    odd = false;
                    std::string newMapLine = std::to_string(seed) + " " + std::to_string(seed) + " " + std::to_string(length);
                    seedMap.push_back(newMapLine);
                }
            }


            std::vector<std::string> newMap = CombineMaps2(seedMap, seed_soil_map);
            newMap = CombineMaps2(seed_soil_map, soil_fertiliser_map);
            newMap = CombineMaps2(newMap, fertiliser_water_map);
            newMap = CombineMaps2(newMap, water_light_map);
            newMap = CombineMaps2(newMap, light_temperature_map);
            newMap = CombineMaps2(newMap, temperature_humidity_map);
            newMap = CombineMaps2(newMap, humidity_location_map);
            ReorderMap(newMap);

            int64_t lowestLocation = std::numeric_limits<int64_t>::max();
            std::set<int64_t> splits = WhereToSplitMaps(newMap, newMap);
            std::vector<std::pair<int64_t, int64_t>> res = SplitMap1(newMap, splits);
            for (auto& split : res)
            {
                bool found = false;
                for (std::string map1Line : seedMap)
                {
                    std::vector<std::string> eachNum = Util::split(map1Line, " ");
                    int64_t map1Dest = std::stoll(eachNum[0]);
                    int64_t map1Source = std::stoll(eachNum[1]);
                    int64_t totalNumbers1 = std::stoll(eachNum[2]);
                    if (map1Source <= split.first && map1Source + totalNumbers1 >= split.first)
                    {
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    continue;
                }
                if (split.second < lowestLocation)
                {
                    lowestLocation = split.second;
                }
            }
            return lowestLocation;
        }

    }



    int64_t full(bool secondPart)
    {
        int64_t lowestLocation = std::numeric_limits<int64_t>::max();

        if (!secondPart)
        {
            std::vector<std::string> input = Input2023::day5_seedInput;
            for (std::string s : input)
            {
                int64_t seed = std::stoll(s);
                int64_t location = GetVal(seed, SEED, LOCATION);
                if (location < lowestLocation)
                {
                    lowestLocation = location;
                }
            }

            return lowestLocation;
        }
        std::vector<std::string> input = Input2023::day5_seedInput;
        bool odd = false;
        int64_t seed = 0;
        for (std::string s : input)
        {
            if (!odd)
            {
                seed = std::stoll(s);
                odd = true;
            }
            else
            {
                int64_t length = std::stoll(s);
                odd = false;
                for (int64_t i = 0; i < length; ++i)
                {
                    int64_t location = GetVal(seed + i, SEED, LOCATION);
                    if (location < lowestLocation)
                    {
                        lowestLocation = location;
                    }
                }
            }
        }

        return lowestLocation;
    }



};

