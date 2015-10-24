#include <SFML/Graphics.hpp>
#include "game.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 768), "TopDown");
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