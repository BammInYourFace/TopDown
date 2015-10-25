#include <time.h>
#include <SFML/Graphics.hpp>
#include "game.hpp"

int main()
{
	srand(time(NULL));
	sf::RenderWindow window(sf::VideoMode(1280, 720), "TopDown");
	Game game(window);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		game.update();
		game.render();
		window.display();
	}

	return 0;
}