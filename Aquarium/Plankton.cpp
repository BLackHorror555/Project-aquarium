#include "Plankton.h"
#include <random>
#include <cmath>


#define FRAME 20

#define PI 3.14159265

void Plankton::SetOrganisms(std::vector<Plankton*>* planktons_, std::vector<Fish*>* fishs_)
{
	planktons = planktons_;
	fishs = fishs_;
}


void Plankton::Death()
{
	auto it = std::find(planktons->begin(), planktons->end(), this);
	if (it != planktons->end()) planktons->erase(it);
	delete this;

}

void Plankton::Reproduction()
{
	if ((age % bioparametres->planktonReproductionPeriod == 0) && (age > 0))
	{
		Plankton* newPlankton = new Plankton(bioparametres, aquariumSize, 0, timeScale, position);
		newPlankton->SetOrganisms(planktons, fishs);
		planktons->push_back(newPlankton);
	}
}


void Plankton::Update()
{
	if (age >= bioparametres->planktonLifetime)
	{
		Death();
		return;
	}
	Reproduction();
	direction.x = 1 * cos(moveAngle * PI / 180);
	direction.y = 1 * sin(moveAngle * PI / 180);
	/*if (position.y >= 705)
	{
		if (position.x <= 30)
			moveAngle = rand() % 360 + 270;
		else if (position.x >= 1200)
			moveAngle = rand() % 270 + 180;
		else
			moveAngle = rand() % 360 + 180;
	}
	else if (position.x <= 30)
	{
		if (position.y >= 680)
			moveAngle = rand() % 360 + 270;
		else if (position.y <= 30)
			moveAngle = rand() % 90;
		else
			moveAngle = rand() % 450 + 270;
	}
	else if (position.y <= 30)
	{
		if (position.x <= 30)
			moveAngle = rand() % 450 + 270;
		else if (position.x >= 1200)
			moveAngle = rand() % 180 + 90;
		else
			moveAngle = rand() % 180;
	}
	else if(position.x >= 1200)
	{
		if (position.y >= 680)
			moveAngle = rand() % 270 + 180;
		else if (position.y <= 30)
			moveAngle = rand() % 180 + 90;
		else
			moveAngle = rand() % 270 + 90;
	}*/
	if (position.x <= 0)
	{
		moveAngle = 0;
	}
	else if (position.x >= GetAquariumSize().x - FRAME)
	{
		moveAngle = 180;
	}
	else if (position.y <= 0)
	{
		moveAngle = 90;
	}
	else if (position.y >= GetAquariumSize().y - FRAME)
	{
		moveAngle = 270;
	}
	else
	{
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


