#pragma once
#include "Organism.h"
#include "Fish.h"
//class Fish;

class Shark: public Organism
{
	//std::vector<Fish*>* fishs;
	//std::vector<Shark*>* sharks;

	std::vector<Fish*>::iterator targetFish;
	float nearestFish;
	float timeWithoutEat = 0;

	sf::Vector2f FindFish();

public:
	Shark(Bioparametres* bioparametres_, sf::Vector2i aquariumSize_, int index_, float* timeScale_, sf::Vector2f position_);
	~Shark();

	void SetOrganisms(std::vector<Fish*>* fishs_, std::vector<Shark*>* sharks_);

	virtual void Death() override;
	virtual void Reproduction() override;
	//virtual void Move() override;
	virtual void Update() override;
	virtual void GetType() override;
};

