#pragma once

#include "Aquarium.h";
#include "Visualizer.h"

class Controller
{
	int timer; //отсчет времени в тиках
	int frequency; //частота обновления состояния биологической системы (количество тиков в секунду)
	int tickDuration; //длительность тика
	std::string background;
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

	float planktonMoveRange;
	float fishMoveRange;
	float sharkMoveRange;

	Controller(int frequency, std::string background, 
				int planktonNumber, int fishNumber, int sharkNumber,
				int windowWidth, int windowHeight, 
				int aquariumWidth, int aquariumHeight);
	~Controller();

	void SetParametres(int planktonLifetime_, int fishLifetime_, int sharkLifetime_, 
		int planktonReproductionPeriod_, int fishReproductionPeriod_, int sharkReproductionPeriod_, 
		int planktonSpeed_, int fishSpeed_, int sharkSpeed_, int fishHungerLifetime_, 
		int sharkHungerLifetime_, int fishViewDistance_, int sharkViewDistance_);

	
	void Start();
	

};
