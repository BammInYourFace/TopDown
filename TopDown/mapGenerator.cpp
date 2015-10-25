#include "mapGenerator.hpp"

MapGenerator::MapGenerator()
{

}

void MapGenerator::generateMap(int width, int height)
{
	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			mapData.push_back(rand() % 256);
		}
	}
}


std::vector<int> MapGenerator::getMapData() const
{
	return mapData;
}


