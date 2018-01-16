#pragma once

#include <SFML\Graphics.hpp>
#include <vector>
#include "Plankton.h"
#include "Fish.h"
#include "Shark.h"

using sf::Vector3i;

class Aquarium
{
	Vector3i size;
	std::vector<Plankton*> plankton;
	std::vector<Fish*> fish;
	std::vector<Shark*> shark;

public:
	Aquarium();
	Aquarium(Vector3i _size);
	~Aquarium();

	int GetPlanctonNumber();
	int GetFishNumber();
	int GetSharkNumber();

	void updateAnimals();
};

