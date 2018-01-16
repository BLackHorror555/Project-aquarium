#pragma once
#include "Organism.h"

class Fish;

class Shark: public Organism
{
	std::vector<Fish*>* fishs;
	std::vector<Shark*>* sharks;

	std::vector<Shark*>::iterator ownIter;
	std::vector<Fish*>::iterator targetFish;
	//float nearestFish;

	sf::Vector2f FindFish();

public:
	Shark();
	~Shark();

	virtual void Death() override;
	virtual void Reproduction() override;
	virtual void Move() override;
	virtual void Update() override;
	
};

