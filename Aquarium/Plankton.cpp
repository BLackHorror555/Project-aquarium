#include "Plankton.h"
#include <random>
#include <cmath>

#define PI 3.14159265

void Plankton::SetOrganisms(std::vector<Plankton*>* planktons_, std::vector<Fish*>* fishs_)
{
	planktons = planktons_;
	fishs = fishs_;
}

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
	
	direction.x = 1 * cos(moveAngle * PI / 180);
	direction.y = 1 * sin(moveAngle * PI / 180);
	/*if (position.y >= 705)
	{
		if (position.x <= 15)
			moveAngle = rand() % 360 + 270;
		else if (position.x >= 1265)
			moveAngle = rand() % 270 + 180;
		else
			moveAngle = rand() % 360 + 180;
	}
	else if (position.x <= 15)
	{
		if (position.y >= 705)
			moveAngle = rand() % 360 + 270;
		else if (position.y <= 15)
			moveAngle = rand() % 90; 
		else
			moveAngle = rand() % 450 + 270;
	}
	else if (position.y <= 15)
	{
		if (position.x <= 15)
			moveAngle = rand() % 450 + 270;
		else if (position.x >= 1265)
			moveAngle = rand() % 180 + 90;
		else
			moveAngle = rand() % 180;
	}
	else if(position.x >= 1275)
	{
		if (position.y >= 705)
			moveAngle = rand() % 270 + 180;
		else if (position.y <= 15)
			moveAngle = rand() % 180 + 90;
		else
			moveAngle = rand() % 270 + 90;
	}
	else*/
	if (position.x <= 20)
	{
		moveAngle = 0;
	}
	else if (position.x >= 1270)
	{
		moveAngle = 180;
	}
	else if (position.y <= 20)
	{
		moveAngle = 90;
	}
	else if (position.y >= 710)
	{
		moveAngle = 270;
	}
	else
	{ 
		int a = rand() % bioparametres->planktonMoveRange  - bioparametres->planktonMoveRange / 2;
		moveAngle += rand() % bioparametres->planktonMoveRange - bioparametres->planktonMoveRange / 2;
	}

	if (moveAngle >= 360)
		moveAngle -= 360;
	if (moveAngle < 0)
	{
		moveAngle += 360;
	}

	
	age++;
}


Plankton::Plankton(Bioparametres* bioparametres_, sf::Vector2i aquariumSize_, int index_, float* timeScale_, sf::Vector2f position_)
	: Organism(bioparametres_, aquariumSize_, index_, timeScale_, position_)
{
	age = 0;
	moveAngle = rand() % 360;
	
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


