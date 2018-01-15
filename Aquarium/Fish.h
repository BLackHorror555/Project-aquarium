#pragma once
#include "Organism.h"
#include "Aquarium.h"
#include <iterator>

class Fish : public Organism
{
	std::vector<Plankton*>::iterator targetPlankton;
	std::vector<Fish*>::iterator ownIter;
	float nearestPlankton;
public:
	virtual void FindFood();
	virtual void Death() override;
	virtual void Reproduction() override;
	virtual void Move() override;
	virtual void Update() override;

	Fish(float moveAngle_, Aquarium* aquarium_);
	virtual ~Fish();
};

