#pragma once
#include "Organism.h"

class Plankton;
class Shark;

class Fish : public Organism
{
	std::vector<Plankton*>* planktons;
	std::vector<Fish*>* fishs;
	std::vector<Shark*>* sharks;

	std::vector<Plankton*>::iterator targetPlankton;
	std::vector<Fish*>::iterator ownIter;
	std::vector<Fish*>::iterator nearestShark;
	//float nearestPlankton;

	//используются в Update 
	sf::Vector2f FindPlankton(); // если нашла, возвращает позицию ближайшего, иначе нулевой вектор 
	//TODO
	sf::Vector2f FindShark(); // если нашла, возвращает позицию ближайшей, иначе нулевой вектор 
public:

	Fish(Bioparametres* bioparametres_, sf::Vector2i aquariumSize_, int index_, float* timeScale_);
	~Fish();

	virtual void Death() override;
	virtual void Reproduction() override;
	virtual void Move() override;
	virtual void Update() override;
};

