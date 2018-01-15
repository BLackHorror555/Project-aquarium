#pragma once
#include "SFML\Graphics.hpp"
#include "Controller.h"

class Displayable
{
public:
	sf::Vector3f position;
	sf::Sprite sprite;
	Displayable();
	~Displayable();
	void Draw();
};

