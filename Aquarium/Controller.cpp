#include "Controller.h"



Controller::Controller(int frequency, Resources* res, 
	int planktonNumber, int fishNumber, int sharkNumber,
	int windowWidth, int windowHeight,
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
}


Controller::~Controller()
{

}

void Controller::SetParametres(int planktonLifetime_, int fishLifetime_, int sharkLifetime_,
	int planktonReproductionPeriod_, int fishReproductionPeriod_, int sharkReproductionPeriod_,
	int planktonSpeed_, int fishSpeed_, int sharkSpeed_,
	int fishHungerLifetime_, int sharkHungerLifetime_,
	int fishViewDistance_, int sharkViewDistance_,
	int fishEatingDistance_, int sharkEatingDistanse_,
	int planktonMoveRange_, int fishMoveRange_, int sharkMoveRange_)
{
	planktonLifetime = planktonLifetime_;
	fishHungerLifetime = fishHungerLifetime_;
	sharkLifetime = sharkLifetime_;

	planktonReproductionPeriod = planktonReproductionPeriod_;
	fishReproductionPeriod = fishReproductionPeriod_;
	sharkReproductionPeriod = sharkReproductionPeriod_;
	
	planktonSpeed = planktonSpeed_;
	fishSpeed = fishSpeed_;
	sharkSpeed = sharkSpeed_;

	fishHungerLifetime = fishHungerLifetime_;
	sharkHungerLifetime = sharkHungerLifetime_;

	fishViewDistance = fishViewDistance_;
	sharkViewDistance = sharkViewDistance_;

	fishEatingDistance = fishEatingDistance_;
	sharkEatingDistanse = sharkEatingDistanse_;

	planktonMoveRange = planktonMoveRange_;
	fishMoveRange = fishMoveRange_;
	sharkMoveRange = sharkMoveRange_;
}

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

void Controller::SetViewDistance(int fishViewDistance_, int sharkViewDistance_)
{
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
}


void Controller::Start()
{
	while (1) //game loop
	{
		Update();
	}
}

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
