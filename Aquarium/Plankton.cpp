#include "Plankton.h"
#include <random>
#include <cmath>

#define PI 3.14159265

void Plankton::Death()
{
	/*if (age >= aquarium->controller->planktonLifetime)
	{
		aquarium->plankton.erase(ownIter);
	}
	delete this;*/
}

void Plankton::Reproduction()
{
	/*if (age % aquarium->controller->planktonReproductionPeriod == 0)
	{
		Plankton* newPlancton = new Plankton();
	}*/
}


void Plankton::Update()
{
	
	direction.x += bioparametres->planktonSpeed * cos(moveAngle * PI / 180);
	direction.y += bioparametres->planktonSpeed * sin(moveAngle * PI / 180);
	if ((position.y <= 15) && (position.x <= 15))
	{
		moveAngle = rand() % 90
	}
	moveAngle += rand() % bioparametres->planktonMoveRange / 2 - bioparametres->planktonMoveRange / 2;
	if (moveAngle >= 360)
		moveAngle -= 360;
	
	age++;
}

Plankton::Plankton(Bioparametres* bioparametres_, sf::Vector2i aquariumSize_, int index_, float* timeScale_)
	: Organism(bioparametres_, aquariumSize_, index_, timeScale_)
{
	age = 0;
	moveAngle = rand() % 360;
	planktons->push_back(this);
	position = sf::Vector2f(rand() % 1240 + 40, rand() % 700 + 20);
}

Plankton::~Plankton()
{
}

/*
Plankton::Plankton(float moveAngle_, Aquarium* aquarium_): Organism(moveAngle_, aquarium_)
{
	aquarium->planctonAmount++;
	ownIter = aquarium->plankton.end() - 1;
}*/


