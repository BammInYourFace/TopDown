#pragma once

#include <SFML\Graphics.hpp>
#include "resourceManager.hpp"

class Game
{
private:
	sf::RenderWindow& window;
	sf::Vector2f windowSize;
	ResourceManager resManager;
	sf::Clock clock;
	sf::Text fpsText;
public:
	Game(sf::RenderWindow& window);
	void update();
	void render();
};