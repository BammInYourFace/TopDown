#pragma once

#include <SFML\Graphics.hpp>

class Camera : public sf::View
{
private:
	sf::Vector2f position;
	float camSpeed;
public:
	Camera(const sf::Vector2f windowSize);

	/*
	sf::Vector2f getPosition() const;
	void setPosition(sf::Vector2f);
	void setPosition(int x, int y);
	void move(sf::Vector2f);
	void move(int x, int y);
	*/

	void update(float frametime);
};