#pragma once
#include "Organism.h"
#include "Aquarium.h"

class Fish : public Organism
{
public:
	virtual void FindFood();
	virtual void Eat();
	virtual void Death() override;
	virtual void Reproduction() override;
	virtual void Move() override;
	virtual void Update() override;

	Fish();
	virtual ~Fish();
};

