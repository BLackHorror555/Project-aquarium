#pragma once

#include <Windows.h>
#include "Aquarium.h";
#include "Bioparametres.h"

class Controller
{
	SYSTEMTIME sysTime;
	int startTime;     // время запуска программы
	int millisTimer;   // отсчет времени в миллисекундах
	int tickTimer;     // отсчет времени в тиках
	int frequency;     // частота обновления состояния биологической системы (количество тиков в секунду)
	int tickDuration;  // длительность тика
	int timeScale;     //общая скорость работы программы

	Bioparametres bioparametres;  //параметры биологической системы
	Aquarium aquarium;

	void FillAquarium();
	void Tick(); //вызывается в соответствии с параметром frequency из метода Update()
public:
	
	Controller( int frequency, 
				int planktonNumber, int fishNumber, int sharkNumber,
				int aquariumWidth, int aquariumHeight );

	void SetLifeTime(int planktonLifetime_, int fishLifetime_, int sharkLifetime_);
	void SetReproductionPeriod( int planktonReproductionPeriod_, 
								int fishReproductionPeriod_, 
								int sharkReproductionPeriod_ );
	void SetSpeed(int planktonSpeed_, int fishSpeed_, int sharkSpeed_);
	void SetHungerLifetime(int fishHungerLifetime_, int sharkHungerLifetime_);
	void SetViewDistance(int planktonViewDistance_, int fishViewDistance_, int sharkViewDistance_);
	void SetEatingDistance(int fishEatingDistance_, int sharkEatingDistanse_);
	void SetMoveRange(int planktonMoveRange_, int fishMoveRange_, int sharkMoveRange_);

	void Update();
	void SetStartTime(int startTime_);
};
