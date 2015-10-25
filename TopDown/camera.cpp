#include "camera.hpp"

Camera::Camera(const sf::Vector2f windowSize)
	:position(sf::Vector2f())
	,camSpeed(200.0f)
{
	setSize(windowSize);
	setCenter(position);
}

/*
sf::Vector2f Camera::getPosition() const
{
	return position;
}

void Camera::setPosition(sf::Vector2f _position)
{
	position = _position;
}

void Camera::setPosition(int x, int y)
{
	setPosition(sf::Vector2f(x, y));
}

void Camera::move(sf::Vector2f movementVector)
{
	position += movementVector;
}

void Camera::move(int x, int y)
{
	move(sf::Vector2f(x, y));
}
*/

void Camera::update(float frametime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		position += sf::Vector2f(-camSpeed * frametime, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		position += sf::Vector2f(camSpeed * frametime, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		position += sf::Vector2f(0, -camSpeed * frametime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		position += sf::Vector2f(0, camSpeed * frametime);
	}

	setCenter(position);
}