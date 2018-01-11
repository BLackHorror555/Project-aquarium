#pragma once
#include <SFML\Graphics.hpp>

class Organism
{
	int age;
	sf::Vector2f position;
public:
	Organism();
	virtual ~Organism();

	virtual void Death() = 0;
	virtual void Reproduction() = 0;
	virtual void Move() = 0;
	virtual void Update() = 0;
};
