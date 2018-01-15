#pragma once
#include "Organism.h"
#include <iterator>

class Fish : public Organism
{
	std::vector<Plankton*>::iterator targetPlankton;
	std::vector<Fish*>::iterator ownIter;
	float nearestPlankton;
public:

	Fish();
	virtual ~Fish();

	virtual void Death() override;
	virtual void Reproduction() override;
	virtual void Move() override;
	virtual void Update() override;

	sf::Vector2f FindPlankton(); // если нашла, возвращает позицию ближайшего, иначе нулевой вектор 
	//TODO
	sf::Vector2f FindShark(); // если нашла, возвращает позицию ближайшей, иначе нулевой вектор 

	
	
};

