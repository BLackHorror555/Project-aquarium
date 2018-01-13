#pragma once
#include <SFML\Graphics.hpp>
#include "Displayable.h"
#include "Aquarium.h"

class Organism : public Displayable
{
	sf::Vector3f position;
public:
	Organism();
	virtual ~Organism();
	int id;
	int age;
	Aquarium *aquarium;
	virtual void Death() = 0;
	virtual void Reproduction() = 0;
	virtual void Move() = 0;
	virtual void Update() = 0;
};
