#pragma once
#include <SFML\Graphics.hpp>
#include "Displayable.h"
#include "Aquarium.h"

class Organism : public Displayable
{
public:
	Organism();
	virtual ~Organism();
	sf::Vector3f position;
	int id;
	int age;
	float moveAngle;
	sf::Vector3f direction;
	Aquarium *aquarium;
	virtual void Death() = 0;
	virtual void Reproduction() = 0;
	virtual void Move() = 0;
	virtual void Update() = 0;
};
