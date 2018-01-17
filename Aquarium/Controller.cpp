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


void Controller::SetLifeTime(int planktonLifetime_, int fishLifetime_, int sharkLifetime_)
{
	bioparametres.planktonLifetime = planktonLifetime_;
	bioparametres.fishLifetime = fishLifetime_;
	bioparametres.sharkLifetime = sharkLifetime_;
}

void Controller::SetReproductionPeriod(int planktonReproductionPeriod_, int fishReproductionPeriod_, int sharkReproductionPeriod_)
{
	bioparametres.planktonReproductionPeriod = planktonReproductionPeriod_;
	bioparametres.fishReproductionPeriod = fishReproductionPeriod_;
	bioparametres.sharkReproductionPeriod = sharkReproductionPeriod_;
}

void Controller::SetSpeed(int planktonSpeed_, int fishSpeed_, int sharkSpeed_)
{
	bioparametres.planktonSpeed = planktonSpeed_;
	bioparametres.fishSpeed = fishSpeed_;
	bioparametres.sharkSpeed = sharkSpeed_;
}

void Controller::SetHungerLifetime(int fishHungerLifetime_, int sharkHungerLifetime_)
{
	bioparametres.fishHungerLifetime = fishHungerLifetime_;
	bioparametres.sharkHungerLifetime = sharkHungerLifetime_;
}

void Controller::SetViewDistance(int planktonViewDistance_, int fishViewDistance_, int sharkViewDistance_)
{
	bioparametres.planktonViewDistance = planktonViewDistance_;
	bioparametres.fishViewDistance = fishViewDistance_;
	bioparametres.sharkViewDistance = sharkViewDistance_;
}

void Controller::SetEatingDistance(int fishEatingDistance_, int sharkEatingDistanse_)
{
	bioparametres.fishEatingDistance = sharkEatingDistanse_;
}

void Controller::SetMoveRange(int planktonMoveRange_, int fishMoveRange_, int sharkMoveRange_)
{
	bioparametres.planktonMoveRange = planktonMoveRange_;
	bioparametres.fishMoveRange = fishMoveRange_;
	bioparametres.sharkMoveRange = sharkMoveRange_;
}


void Controller::FillAquarium()
{
	for (int i = 0; i < aquarium.GetPlanktonNumber(); i++)
	{
		Plankton* newPlancton = new Plankton(&bioparametres, aquarium.GetSize(), 0, &timeScale, sf::Vector2f(rand() % 1240 + 40, rand() % 700 + 20));
	}
	for (int i = 0; i < aquarium.GetFishNumber(); i++)
	{
		Fish* newFish = new Fish(&bioparametres, aquarium.GetSize(), 0, &timeScale, sf::Vector2f(rand() % 1240 + 40, rand() % 700 + 20));
	}
	for (int i = 0; i < aquarium.GetSharkNumber(); i++)
	{
		Shark* newShark = new Shark(&bioparametres, aquarium.GetSize(), 0, &timeScale, sf::Vector2f(rand() % 1240 + 40, rand() % 700 + 20));
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
	//��������� �������
	GetLocalTime(&sysTime);
	int newMillisTimer = sysTime.wMilliseconds + sysTime.wSecond * 1000 +
		sysTime.wMinute * 60000 + sysTime.wHour * 3600000 - startTime - 10800000;
	deltaTime = newMillisTimer - millisTimer;
	millisTimer = newMillisTimer;
	int _ticktimer = round(millisTimer * frequency * timeScale / 1000);
	//����� �������
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

Aquarium * Controller::GetAquarium()
{
	return &aquarium;
}
