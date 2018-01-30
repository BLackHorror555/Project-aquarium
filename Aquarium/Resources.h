#pragma once
#include <SFML\Graphics.hpp>

using sf::Texture;
using std::string;

class Resources
{
public :
	Texture background;
	Texture noise;
	Texture bubble;
	
	Texture plankton;
	Texture fish1;
	Texture fish2;
	Texture shark1;
	Texture shark2;

	Resources(string background, string noise, string bubble, string plankton,
		string fish1, string fish2, string shark1, string shark2);
};