#pragma once
#include "Organism.h"
#include "Aquarium.h"

class Plankton: public Organism
{
	std::vector<Plankton*>* planktons;
	std::vector<Fish*>* fishs;
	std::vector<Plankton*>::iterator ownIter;
public:
	Plankton();
	virtual void Death() override;
	virtual void Reproduction() override;
	virtual void Move() override;
	virtual void Update() override;
	
	virtual ~Plankton();

	//TODO
	sf::Vector2f FindFish(); // ���� �����, ���������� ������� ���������, ����� ������� ������ 
};

