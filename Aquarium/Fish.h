#pragma once
#include "Organism.h"

class Fish : public Organism
{
	std::vector<Organism*>* organisms;


	std::vector<Organism*>::iterator targetPlankton;
	std::vector<Organism*>::iterator dungerShark;

	float nearestShark;
	float nearestPlankton;
	float timeWithoutEat = 0;

	//используются в Update 
	float FindPlankton(); // если нашла, возвращает новое направление, иначе 0
	//TODO
	float FindShark(); // если нашла, возвращает новое направление, иначе 0
public:

	Fish(Bioparametres* bioparametres_, sf::Vector2i aquariumSize_, int index_, float* timeScale_, sf::Vector2f position_);
	Fish(Bioparametres* bioparametres_, sf::Vector2i aquariumSize_, int index_, float* timeScale_, sf::Vector2f position_, float moveAngle_);
	~Fish();

	void SetOrganisms(std::vector<Organism*>* organisms_);

	virtual void Death() override;
	virtual void Reproduction() override;
	virtual void Update() override;
	virtual OrganismTypes GetType() override;
};

