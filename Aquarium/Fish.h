#pragma once
#include "Organism.h"
#include "Aquarium.h"
#include <iterator>

class Fish : public Organism
{
	float nearestPlancton;
public:
	std::vector<Plankton*>::iterator targetPlankton;
	float eatingDistance;

	virtual void FindFood();
	virtual void Eat();
	virtual void Death() override;
	virtual void Reproduction() override;
	virtual void Move() override;
	virtual void Update() override;

	Fish();
	virtual ~Fish();
};

