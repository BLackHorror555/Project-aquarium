#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include "Plankton.h"
#include "Fish.h"
#include "Shark.h"
#include "Organism.h"
#include "Bioparametres.h"

class Aquarium
{
	sf::Vector2i size;
	std::vector<Organism*> organisms;

	Bioparametres* bioparametres;

	float* timeScale;

public:
	Aquarium();
	Aquarium(sf::Vector2i _size, Bioparametres* bioparametres_, float* timeScale_);
	~Aquarium();

	std::vector<Organism*>* GetOrganisms();

	sf::Vector2i GetSize();

	void UpdateAnimals();  // обновляется направление, и вызываются методы FindFood(), Eat(), и тд
	void MoveAnimals();    // все организмы передвигаются в соответствии с записанным в них направлением
};
