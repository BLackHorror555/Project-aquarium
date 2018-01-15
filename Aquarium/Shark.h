#pragma once
#include "Fish.h"

class Shark :public Fish
{
	std::vector<Shark*>::iterator ownIter;
	std::vector<Fish*>::iterator targetFish;
	float nearestFish;
public:
	virtual void FindFood() override;
	virtual void Death() override;
	virtual void Reproduction() override;
	virtual void Move() override;
	virtual void Update() override;
	Shark();
	virtual ~Shark();
};

