#pragma once

#include <vector>

class MapGenerator
{
private:
	std::vector<int> mapData;
public:
	MapGenerator();
	void generateMap(int width, int height);
	std::vector<int> getMapData() const;
};