#include <iostream>
#include "mapGenerator.hpp"
#include "map.hpp"

Map::Map()
	: vertices()
	, mapData()
	, mapSize(64, 64)
	, tileSize(32, 32)
{
	load();
}

void Map::load()
{
	MapGenerator mapGen;
	mapGen.generateMap(mapSize.x, mapSize.y);
	mapData = mapGen.getMapData();
	vertices.setPrimitiveType(sf::Quads);
	vertices.resize(mapSize.x * mapSize.y * 4);
	for (unsigned int y = 0; y < mapSize.x; ++y)
	{
		for (unsigned int x = 0; x < mapSize.x; ++x)
		{
			
			int tileData = mapData[x + y * mapSize.x];
			sf::Vertex* quad = &vertices[(x + y * mapSize.x) * 4];

			quad[0].position = sf::Vector2f(x * tileSize.x, y * tileSize.y);
			quad[1].position = sf::Vector2f((x + 1) * tileSize.x, y * tileSize.y);
			quad[2].position = sf::Vector2f((x + 1) * tileSize.x, (y + 1) * tileSize.y);
			quad[3].position = sf::Vector2f(x * tileSize.x, (y + 1) * tileSize.y);

			quad[0].color = sf::Color(tileData, 0, 0);
			quad[1].color = sf::Color(tileData, 0, 0);
			quad[2].color = sf::Color(tileData, 0, 0);
			quad[3].color = sf::Color(tileData, 0, 0);

		}
	}
}


void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// apply the transform
	states.transform *= getTransform();

	// apply the tileset texture
	//states.texture = &m_tileset;

	// draw the vertex array
	target.draw(vertices, states);
}