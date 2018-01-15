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
	FillAquarium(planktonNumber, fishNumber, sharkNumber);
}


Controller::~Controller()
{

}

void Controller::SetParametres(int planktonLifetime_, int fishLifetime_, int sharkLifetime_, 
	int planktonReproductionPeriod_, int fishReproductionPeriod_, int sharkReproductionPeriod_, 
	int planktonSpeed_, int fishSpeed_, int sharkSpeed_, 
	int fishHungerLifetime_, int sharkHungerLifetime_, 
	int fishViewDistance_, int sharkViewDistance_)
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
}

void Controller::Start()
{
	while (1) //game loop
	{
		Update();
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
