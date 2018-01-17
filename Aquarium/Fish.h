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

	//������������ � Update 
	sf::Vector2f FindPlankton(); // ���� �����, ���������� ������� ����������, ����� ������� ������ 
	//TODO
	sf::Vector2f FindShark(); // ���� �����, ���������� ������� ���������, ����� ������� ������ 
public:

	Fish(Bioparametres* bioparametres_, sf::Vector2i aquariumSize_, int index_, float* timeScale_);
	~Fish();

	virtual void Death() override;
	virtual void Reproduction() override;
	virtual void Move() override;
	virtual void Update() override;
};

