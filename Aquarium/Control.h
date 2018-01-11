#ifndef CONTROL_H
#define CONTROL_H
#include "Aquarium.h";

class Controler
{
	int timer;
	int frequaency;

public:
	int plankton_lifetime;
	int fish_lifetime;
	int shark_lifetime;
	int plankton_reproduction_period;
	int fish_reproduction_period;
	int shark_reproduction_period;
	int plankton_speed;
	int fish_speed;
	int shark_speed;
	int fish_hunger_lifetime;
	int shark_hunger_lifetime;
	int fish_view_distance;
	int shark_view_distance;
	Aquarium aquarium;

	Controler();
	~Controler();

	void FillAquarium();
	void Update();
};

#endif