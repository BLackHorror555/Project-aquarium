#pragma once
#include "Organism.h"
#include "Aquarium.h"

class Plankton: public Organism
{
	std::vector<Plankton*>::iterator ownIter;
public:
	virtual void Death() override;
	virtual void Reproduction() override;
	virtual void Move() override;
	virtual void Update() override;
	Plankton();
	virtual ~Plankton();
};

