#pragma once

#include <SFML\Graphics.hpp>
#include <vector>
#include "Plankton.h"
#include "Fish.h"
#include "Organism.h"
#include "Shark.h"
#include "Controller.h"

using sf::Vector3i;

class Aquarium
{
	Vector3i size;
	
public:
	Aquarium();
	Aquarium(Vector3i _size);
	~Aquarium();

	int planctonAmount;
	int fishAmount;
	int sharkAmount;

	Controller *controller;
	std::vector<Plankton*> plankton;
	std::vector<Fish*> fish;
	std::vector<Shark*> shark;

	void updateAnimals();
};

