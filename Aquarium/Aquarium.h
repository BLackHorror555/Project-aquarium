#pragma once

#include <SFML\Graphics.hpp>
#include <vector>
#include "Plankton.h"
#include "Fish.h"
#include "Organism.h"
#include "Shark.h"

using sf::Vector2f;

class Aquarium
{
	Vector2f size;
	int plancton_amount;
	int fish_amount;
	int shark_amount;
public:
	Aquarium(Vector2f _size);
	~Aquarium();

	std::vector<Plankton> plankton;
	std::vector<Fish> fish;
	std::vector<Shark> shark;

	void updateAnimals();
};

