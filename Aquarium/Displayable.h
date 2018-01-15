#pragma once
#include "SFML\Graphics.hpp"
#include "Controller.h"
#include "Resources.h"

class Displayable
{
	
public:
	Resources* res;
	sf::Vector3f position;
	sf::Sprite sprite;
	
	Aquarium* aquarium;
	Displayable(Aquarium* aquarium_);
	~Displayable();
};

