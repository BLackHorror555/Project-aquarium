#pragma once

#include <SFML\Graphics.hpp>
#include <vector>
#include "Plankton.h"
#include "Fish.h"
#include "Organism.h"
#include "Shark.h"

using sf::Vector3i;

class Aquarium
{
	Vector3i size;
	int plancton_amount;
	int fish_amount;
	int shark_amount;
public:
	Aquarium();
	Aquarium(Vector3i _size);
	~Aquarium();

	std::vector<Plankton> plankton;
	std::vector<Fish> fish;
	std::vector<Shark> shark;

	void updateAnimals();
};

