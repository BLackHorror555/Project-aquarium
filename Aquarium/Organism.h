#pragma once
#include <SFML\Graphics.hpp>
#include "Displayable.h"

class Organism : public Displayable
{
	int age;
	sf::Vector3f position;
public:
	Organism();
	virtual ~Organism();

	virtual void Death() = 0;
	virtual void Reproduction() = 0;
	virtual void Move() = 0;
	virtual void Update() = 0;
};
