#pragma once

#include "Aquarium.h";

class Controller
{
	int timer; //отсчет времени в 
	int frequency; //частота обновления состояния биологической системы
public:
	int planktonLifetime;
	int fishLifetime;
	int sharkLifetime;
	int planktonReproduction_period;
	int fishReproduction_period;
	int sharkReproduction_period;
	int planktonSpeed;
	int fishSpeed;
	int sharkSpeed;
	int fishHungerLifetime;
	int sharkHungerLifetime;
	int fishViewDistance;
	int sharkViewDistance;
	Aquarium* aquarium;

	Controller();
	~Controller();

	void FillAquarium();
	void Update();
};
