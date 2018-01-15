#pragma once
#include <SFML\Graphics.hpp>


class Resources
{
public :
	sf::Texture background;
	sf::Texture plankton;
	sf::Texture fish;
	sf::Texture shark;

	Resources(std::string background, std::string plankton, std::string fish, std::string shark);
};