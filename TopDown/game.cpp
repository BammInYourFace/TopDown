#include "game.hpp"

Game::Game(sf::RenderWindow& _window)
	:window(_window)
	,windowSize(_window.getSize())
	,resManager()
	,clock()
	,fpsText()
{
	resManager.loadResources();

	fpsText.setFont(resManager.getFont("medieval"));
	fpsText.setPosition(0, 0);
	fpsText.setCharacterSize(12);
	fpsText.setColor(sf::Color::Yellow);
}

void Game::update()
{
	float frametime = clock.restart().asSeconds();
	fpsText.setString(sf::String("fps: " + std::to_string(static_cast<int>(1.0f/frametime))));
}

void Game::render()
{
	window.draw(fpsText);
}