#ifndef AQUARIM_H
#define AQUARIUM_H

#include <SFML\Graphics.hpp>
#include <vector>
#include "Plankton.h"
#include "Fish.h"
#include "Organism.h"
#include "Shark.h"
using namespace sf;

class Aquarium
{
	Vector2f size;
	int plancton_amount;
	int fish_amount;
	int shark_amount;
	
public:
	Aquarium(Vector2f _size);
	~Aquarium();

	std::vector<Plankton> vecPlanktons;
	std::vector<Fish> vecFish;
	std::vector<Shark> vecSharks;

	void updateAnimals();
};

#endif
