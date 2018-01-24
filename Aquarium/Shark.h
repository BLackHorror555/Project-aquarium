#pragma once
#include "Organism.h"

class Shark: public Organism
{
	std::vector<Organism*>* organisms;

	std::vector<Organism*>::iterator targetFish;
	float nearestFish;
	float timeWithoutEat = 0;

	float FindFish();

public:
	Shark(Bioparametres* bioparametres_, sf::Vector2i aquariumSize_, int index_, float* timeScale_, sf::Vector2f position_);
	Shark(Bioparametres* bioparametres_, sf::Vector2i aquariumSize_, int index_, float* timeScale_, sf::Vector2f position_, float moveAngle_);
	~Shark();

	void SetOrganisms(std::vector<Organism*>* organisms_);

	virtual void Death() override;
	virtual void Reproduction() override;
	virtual void Update() override;
	virtual OrganismTypes GetType() override;
};

