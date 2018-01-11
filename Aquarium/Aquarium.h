#ifndef AQUARIM_H
#define AQUARIUM_H

#include <vector>
#include "Plankton.h"
#include "Fish.h"
#include "Organism.h"
#include "Shark.h"

class Aquarium
{
	int plancton_amount;
	int fish_amount;
	int shark_amount;
	std::vector<Plankton> vecPlanktons;
	std::vector<Fish> vecFish;
	std::vector<Shark> vecSharks;
public:
	Aquarium();
	~Aquarium();
};

#endif
