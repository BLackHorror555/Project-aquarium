#pragma once
#include <SFML\Graphics.hpp>
#include <vector>

class Organism
{
public:
	Organism();
	virtual ~Organism();
	int age;
	//float moveAngle;
	sf::Vector2f direction;
	virtual void Death() = 0;
	virtual void Reproduction() = 0;
	virtual void Move() = 0; 
	virtual void Update() = 0;
};
