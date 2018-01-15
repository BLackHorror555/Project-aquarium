#include "Plankton.h"
#include <random>
#include <cmath>

#define PI 3.14159265

void Plankton::Death()
{
	if (age >= aquarium->controller->planktonLifetime)
	{
		for (auto org = aquarium->plankton.begin(); org != aquarium->plankton.end(); ++org)
		{
			if (id == (*org)->id)
			{	
				aquarium->plankton.erase(org);
				break;
			}
		}
	}
	delete this;
}

void Plankton::Reproduction()
{
	if (age % aquarium->controller->planktonReproductionPeriod == 0)
	{
		Plankton* newPlancton = new Plankton();
		aquarium->plankton.push_back(newPlancton);
	}
}

void Plankton::Move()
{
	position.x += aquarium->controller->planktonSpeed * cos(moveAngle * PI / 180);
	position.y += aquarium->controller->planktonSpeed * sin(moveAngle * PI / 180);
	moveAngle += rand() % aquarium->controller->planktonMoveRange / 2 - aquarium->controller->planktonMoveRange / 2;
	if (moveAngle >= 360)
		moveAngle -= 360;

	sprite.setPosition(position.x, position.y);
}

void Plankton::Update()
{
	Move();
}

Plankton::Plankton()
{
	age = 0;
	moveAngle = rand() % 360;
	aquarium->plankton.push_back(this);
}


Plankton::~Plankton()
{
}
