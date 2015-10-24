#include <iostream>
#include "resourceManager.hpp"

ResourceManager::ResourceManager()
	:texturePaths()
	,textures()
	,fontPaths()
	,fonts()
{
	fontPaths.insert(std::pair<std::string, std::string>("medieval", "Resources/Fonts/medieval.ttf"));
}


void ResourceManager::loadResources()
{
	for (auto it = texturePaths.begin(), end = texturePaths.end(); it != end; ++it)
	{
		sf::Texture texture;
		if (texture.loadFromFile(it->second))
		{
			textures.insert(std::pair<std::string, sf::Texture>(it->first, texture));
			std::cout << "Texture loaded: " << it->first << " | " << it->second << std::endl;
		}
	}

	std::cout << "Textures loaded!" << std::endl;

	for (auto it = fontPaths.begin(), end = fontPaths.end(); it != end; ++it)
	{
		sf::Font font;
		if (font.loadFromFile(it->second))
		{
			fonts.insert(std::pair<std::string, sf::Font>(it->first, font));
			std::cout << "Font loaded: " << it->first << " | " << it->second << std::endl;
		}
	}
	std::cout << "Fonts loaded!" << std::endl;
}


const sf::Texture& ResourceManager::getTexture(const std::string identifier) const
{
	if (textures.find(identifier) != textures.end())
	{
		return textures.at(identifier);
	}
	else
	{
		std::cout << "Tried to access a non-existing texture!" << std::endl;
		return sf::Texture();
	}
}

const sf::Font& ResourceManager::getFont(const std::string identifier) const
{
	if (fonts.find(identifier) != fonts.end())
	{
		return fonts.at(identifier);
	}
	else
	{
		std::cout << "Tried to access a non-existing font!" << std::endl;
		return sf::Font();
	}
}