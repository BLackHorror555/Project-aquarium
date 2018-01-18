#pragma once
#include "Organism.h"
#include "Plankton.h"
//class Plankton;
class Shark;

class Fish : public Organism
{
	std::vector<Plankton*>* planktons;
	std::vector<Fish*>* fishs;
	std::vector<Shark*>* sharks;

	std::vector<Plankton*>::iterator targetPlankton;
	std::vector<Fish*>::iterator nearestShark;

	float nearestPlankton = 1000;
	float timeWithoutEat = 0;

	//������������ � Update 
	sf::Vector2f FindPlankton(); // ���� �����, ���������� ������� ����������, ����� ������� ������ 
	//TODO
	sf::Vector2f FindShark(); // ���� �����, ���������� ������� ���������, ����� ������� ������ 
public:

	Fish(Bioparametres* bioparametres_, sf::Vector2i aquariumSize_, int index_, float* timeScale_, sf::Vector2f position_);
	~Fish();

	void SetOrganisms(std::vector<Plankton*>* planktons_, std::vector<Fish*>* fishs_, std::vector<Shark*>* sharks_);
	virtual void Death() override;
	virtual void Reproduction() override;
	virtual void Update() override;
};

