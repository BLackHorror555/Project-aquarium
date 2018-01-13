#pragma once
#include "SFML\Graphics.hpp"

class Displayable
{
public:
	sf::Vector2f position;
	sf::Sprite sprite;
	Displayable();
	~Displayable();
	void Draw();
};

