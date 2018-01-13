#pragma once

#include <SFML\Graphics.hpp>
#include <vector>
#include "Plankton.h"
#include "Fish.h"
#include "Organism.h"
#include "Shark.h"
#include "Controller.h"

using sf::Vector3f;

class Aquarium
{
	Vector3f size;
	int plancton_amount;
	int fish_amount;
	int shark_amount;
public:
	Aquarium(Vector3f _size);
	~Aquarium();

	Controller* controller;
	std::vector<Plankton*> plankton;
	std::vector<Fish*> fish;
	std::vector<Shark*> shark;

	void updateAnimals();
};

