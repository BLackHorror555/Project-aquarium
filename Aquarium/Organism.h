#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include "Bioparametres.h"

class Organism
{
public:
	Organism();
	virtual ~Organism();

	Bioparametres* bioparametres;
	int age;
	int index; //индекс в векторе аквариума
	//float moveAngle;
	sf::Vector2f direction;
	
	virtual void Death() = 0;
	virtual void Reproduction() = 0;
	virtual void Move() = 0; 
	virtual void Update() = 0;
};
