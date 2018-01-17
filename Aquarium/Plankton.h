#pragma once
#include "Organism.h"

class Fish;

class Plankton: public Organism
{
	std::vector<Plankton*> * planktons;
	std::vector<Fish*> * fishs;

	std::vector<Fish*>::iterator nearestFish;

	//TODO
	sf::Vector2f FindFish(); // если нашла, возвращает позицию ближайшей, иначе нулевой вектор 
public:
	Plankton(Bioparametres* bioparametres_, sf::Vector2i aquariumSize_, int index_, float* timeScale_, sf::Vector2f position_);
	~Plankton();

	void SetOrganisms(std::vector<Plankton*>* planktons_, std::vector<Fish*>* fishs_);
	void SetOwnIterator(std::vector<Plankton*>::iterator ownIter_);
	virtual void Death() override;
	virtual void Reproduction() override;
	virtual void Update() override;
};

