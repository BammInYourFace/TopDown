#include "game.hpp"

Game::Game(sf::RenderWindow& window)
	:window(window)
	,windowSize(window.getSize())
	,map()
	,cam(windowSize)
	,resManager()
	,clock()
	,fpsText()
{
	resManager.loadResources();
	

	fpsText.setFont(resManager.getFont("medieval"));
	fpsText.setPosition(0, 0);
	fpsText.setCharacterSize(24);
	fpsText.setColor(sf::Color::Yellow);

	map.setPosition(0, 0);
}

void Game::update()
{
	float frametime = clock.restart().asSeconds();
	fpsText.setString(sf::String("fps: " + std::to_string(static_cast<int>(1.0f/frametime))));
	cam.update(frametime);
	fpsText.setPosition(cam.getCenter() - sf::Vector2f(cam.getSize().x / 2, cam.getSize().y / 2));
	
}

void Game::render()
{
	window.setView(cam);
	window.draw(map);
	window.draw(fpsText);
}