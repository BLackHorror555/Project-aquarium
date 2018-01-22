#pragma once
#include "Organism.h"

class Fish : public Organism
{
	std::vector<Organism*>* organisms;


	std::vector<Organism*>::iterator targetPlankton;
	std::vector<Organism*>::iterator nearestShark;

	float nearestPlankton = 1000;
	float timeWithoutEat = 0;

	//������������ � Update 
	sf::Vector2f FindPlankton(); // ���� �����, ���������� ������� ����������, ����� ������� ������ 
	//TODO
	sf::Vector2f FindShark(); // ���� �����, ���������� ������� ���������, ����� ������� ������ 
public:

	Fish(Bioparametres* bioparametres_, sf::Vector2i aquariumSize_, int index_, float* timeScale_, sf::Vector2f position_);
	~Fish();

	void SetOrganisms(std::vector<Organism*>* organisms_);
	virtual void Death() override;
	virtual void Reproduction() override;
	virtual void Update() override;
	virtual OrganismTypes GetType() override;
};

