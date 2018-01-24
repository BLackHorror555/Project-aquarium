#pragma once
#include <SFML\Graphics.hpp>


class Resources
{
public :
	sf::Texture background;
	sf::Texture plankton;
	sf::Texture fish;
	sf::Texture shark;
	
	sf::Texture fishTex1;
	sf::Texture fishTex2;
	sf::Texture sharkTex1;
	sf::Texture sharkTex2;

	Resources(std::string background, std::string plankton, std::string fish, std::string shark,
		std::string fish1, std::string fish2, std::string shark1, std::string shark2);
};