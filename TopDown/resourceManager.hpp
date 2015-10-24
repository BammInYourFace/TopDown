#pragma once

#include "SFML\Graphics.hpp"
#include <list>

class ResourceManager
{
private:
	std::map<std::string, std::string> texturePaths;
	std::map<std::string, sf::Texture> textures;
	std::map<std::string, std::string> fontPaths;
	std::map<std::string, sf::Font> fonts;
public:
	ResourceManager();
	void loadResources();
	const sf::Texture& getTexture(const std::string identifier) const;
	const sf::Font& getFont(const std::string identifier) const;
};