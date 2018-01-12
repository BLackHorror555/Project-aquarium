#pragma once
#include "Organism.h"

class Plankton: public Organism
{
public:
	virtual void Death() override;
	virtual void Reproduction() override;
	virtual void Move() override;
	virtual void Update() override;
	Plankton();
	virtual ~Plankton();
};

