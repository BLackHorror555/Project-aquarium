#pragma once
#include "Organism.h"

class Fish;

class Plankton: public Organism
{
	std::vector<Plankton*>* planktons;
	std::vector<Fish*>* fishs;

	std::vector<Plankton*>::iterator ownIter;
	std::vector<Fish*>::iterator nearestFish;

	//TODO
	sf::Vector2f FindFish(); // если нашла, возвращает позицию ближайшей, иначе нулевой вектор 
public:
	Plankton(Bioparametres* bioparametres_, sf::Vector2i aquariumSize_, int index_, float* timeScale_);
	~Plankton();

	virtual void Death() override;
	virtual void Reproduction() override;
	virtual void Move() override;
	virtual void Update() override;
};

