#pragma once

#include <vector>
#include <SFML\Graphics.hpp>

class Map : public sf::Drawable, public sf::Transformable
{
private:
	sf::VertexArray vertices;
	std::vector<int> mapData;
	sf::Vector2i mapSize;
	sf::Vector2i tileSize;

	void load();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
	Map();

	//void update();
	
};