#pragma once

#include "Aquarium.h";
#include "Visualizer.h"
#include "Resources.h"

class Controller
{
	int timer; //отсчет времени в тиках
	int frequency; //частота обновления состояния биологической системы (количество тиков в секунду)
	int tickDuration; //длительность тика
	Visualizer visualizer;
	Aquarium aquarium;

	void FillAquarium(int planktonNumber, int fishNumber, int sharkNumber);
	void Update();

public:
	int planktonLifetime;
	int fishLifetime;
	int sharkLifetime;

	int planktonReproductionPeriod;
	int fishReproductionPeriod;
	int sharkReproductionPeriod;

	int planktonSpeed;
	int fishSpeed;
	int sharkSpeed;

	int fishHungerLifetime;
	int sharkHungerLifetime;

	int fishViewDistance;
	int sharkViewDistance;

	int fishEatingDistance;
	int sharkEatingDistanse;

	int planktonMoveRange;
	int fishMoveRange;
	int sharkMoveRange;

	Controller(int frequency, Resources* resources, int planktonNumber, int fishNumber, int sharkNumber,
				int windowWidth, int windowHeight, 
				int aquariumWidth, int aquariumHeight);
	~Controller();

	void SetParametres(int planktonLifetime_, int fishLifetime_, int sharkLifetime_,
		int planktonReproductionPeriod_, int fishReproductionPeriod_, int sharkReproductionPeriod_,
		int planktonSpeed_, int fishSpeed_, int sharkSpeed_,
		int fishHungerLifetime_, int sharkHungerLifetime_,
		int fishViewDistance_, int sharkViewDistance_,
		int fishEatingDistance_, int sharkEatingDistanse_,
		int planktonMoveRange_, int fishMoveRange_, int sharkMoveRange_);

	
	void Start();
	

};
