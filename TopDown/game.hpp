#pragma once

#include <SFML\Graphics.hpp>
#include "resourceManager.hpp"
#include "map.hpp"
#include "camera.hpp"

class Game
{
private:
	sf::RenderWindow& window;
	sf::Vector2f windowSize;
	Map map;
	Camera cam;
	ResourceManager resManager;
	sf::Clock clock;
	sf::Text fpsText;
public:
	Game(sf::RenderWindow& window);
	void update();
	void render();
};