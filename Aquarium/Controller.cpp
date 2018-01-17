#include "Controller.h"
#include <iostream>


/*
Controller::Controller(int frequency,
	int planktonNumber, int fishNumber, int sharkNumber
	int aquariumWidth, int aquariumHeight)
{
	this->frequency = frequency;
	tickDuration = 1 / frequency;

	visualizer = Visualizer(windowWidth, windowHeight, res);
	aquarium = Aquarium(sf::Vector3i(windowWidth, windowHeight, 0));
	aquarium.planctonAmount = planktonNumber;
	aquarium.fishAmount = fishNumber;
	aquarium.sharkAmount = sharkNumber;
	FillAquarium();
}*/

/*
void Controller::SetLifeTime(int planktonLifetime_, int fishLifetime_, int sharkLifetime_)
{
	planktonLifetime = planktonLifetime_;
	fishLifetime = fishLifetime_;
	sharkLifetime = sharkLifetime_;
}

void Controller::SetReproductionPeriod(int planktonReproductionPeriod_, int fishReproductionPeriod_, int sharkReproductionPeriod_)
{
	planktonReproductionPeriod = planktonReproductionPeriod_;
	fishReproductionPeriod = fishReproductionPeriod_;
	sharkReproductionPeriod = sharkReproductionPeriod_;
}

void Controller::SetSpeed(int planktonSpeed_, int fishSpeed_, int sharkSpeed_)
{
	planktonSpeed = planktonSpeed_;
	fishSpeed = fishSpeed_;
	sharkSpeed = sharkSpeed_;
}

void Controller::SetHungerLifetime(int fishHungerLifetime_, int sharkHungerLifetime_)
{
	fishHungerLifetime = fishHungerLifetime_;
	sharkHungerLifetime = sharkHungerLifetime_;
}

void Controller::SetViewDistance(int planktonViewDistance_, int fishViewDistance_, int sharkViewDistance_)
{
	planktonViewDistance = planktonViewDistance_;
	fishViewDistance = fishViewDistance_;
	sharkViewDistance = sharkViewDistance_;
}

void Controller::SetEatingDistance(int fishEatingDistance_, int sharkEatingDistanse_)
{
	fishEatingDistance = sharkEatingDistanse_;
}

void Controller::SetMoveRange(int planktonMoveRange_, int fishMoveRange_, int sharkMoveRange_)
{
	planktonMoveRange = planktonMoveRange_;
	fishMoveRange = fishMoveRange_;
	sharkMoveRange = sharkMoveRange_;
}*/


void Controller::FillAquarium()
{
	for (int i = 0; i < aquarium.planctonAmount; i++)
	{
		Plankton* newPlancton = new Plankton;
		newPlancton->aquarium = &aquarium;
	}
	for (int i = 0; i < aquarium.fishAmount; i++)
	{
		Fish* newFish = new Fish;
		newFish->aquarium = &aquarium;
	}
	for (int i = 0; i < aquarium.sharkAmount; i++)
	{
		Shark* newShark = new Shark;
		newShark->aquarium = &aquarium;
	}
}
/*
void Controller::Update()
{
	aquarium.updateAnimals();
	for (int i = 0; i < aquarium.plankton.size(); i++)
	{
		visualizer.Draw(*aquarium.plankton[i]);
	}
	for (int i = 0; i < aquarium.fish.size(); i++)
	{
		visualizer.Draw(*aquarium.fish[i]);
	}
	for (int i = 0; i < aquarium.shark.size(); i++)
	{
		visualizer.Draw(*aquarium.shark[i]);
	}
	visualizer.Display();
	timer++;
}
*/

Controller::Controller(int frequency_, 
	int planktonNumber, int fishNumber, int sharkNumber, 
	int aquariumWidth, int aquariumHeight)
{
	frequency = frequency_;
	tickDuration = 1.0f / frequency;
	aquarium = Aquarium(sf::Vector2i(aquariumWidth, aquariumHeight));

}

void Controller::Update()
{
	//обновляем таймеры
	GetLocalTime(&sysTime);
	int newMillisTimer = sysTime.wMilliseconds + sysTime.wSecond * 1000 +
		sysTime.wMinute * 60000 + sysTime.wHour * 3600000 - startTime - 10800000;
	deltaTime = newMillisTimer - millisTimer;
	millisTimer = newMillisTimer;
	int _ticktimer = round(millisTimer * frequency * timeScale / 1000);
	//время тикнуть
	if (_ticktimer > tickTimer)
	{
		tickTimer = _ticktimer;
		system("cls");
		std::cout << "milliseconds: " << millisTimer << "\nticks (frequency=" << frequency << "): " << tickTimer 
				  << "\ntime scale: " << timeScale << std::endl;
		aquarium.UpdateAnimals();
	}
	aquarium.MoveAnimals();
}

void Controller::SetStartTime(int startTime_)
{
	startTime = startTime_;
}

void Controller::SetTimeScale(float timeScale_)
{
	timeScale = timeScale_;
}
