#pragma once
#include "SFML\Graphics.hpp"
#include "Resources.h"
#include "Aquarium.h"

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

