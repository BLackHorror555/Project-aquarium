#pragma once
#include "Organism.h"

//class Fish;

class Plankton: public Organism
{
	std::vector<Organism*> * organisms;

	std::vector<Organism*>::iterator nearestFish;

	
public:
	Plankton(Bioparametres* bioparametres_, sf::Vector2i aquariumSize_, int index_, float* timeScale_, sf::Vector2f position_);
	Plankton(Bioparametres* bioparametres_, sf::Vector2i aquariumSize_, int index_, float* timeScale_, sf::Vector2f position_, float moveAngle_);
	~Plankton();

	void SetOrganisms(std::vector<Organism*>* organisms_);

	virtual void Death() override;
	virtual void Reproduction() override;
	virtual void Update() override;
	virtual OrganismTypes GetType() override;
};

