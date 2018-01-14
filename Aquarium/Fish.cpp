#include "Fish.h"
#include <random>

#define PI 3.14159265


void Fish::Eat()
{
}

void Fish::Death()
{
	if (age >= aquarium->controller->fishLifetime)
	{
		for (auto org = aquarium->fish.begin(); org != aquarium->fish.end(); ++org)
		{
			if (id == (*org)->id)
			{
				aquarium->fish.erase(org);
				break;
			}
		}
	}
	delete this;
}

void Fish::Reproduction()
{
	if (age % aquarium->controller->fishReproductionPeriod == 0)
	{
		Fish* newFish = new Fish();
		aquarium->fish.push_back(newFish);
	}
}

void Fish::Move()
{
	targetPlankton = aquarium->plankton.end();
	for (auto org = aquarium->plankton.begin(); org != aquarium->plankton.end(); ++org)
	{
		if (sqrt(pow((*org)->position.x - position.x, 2) + pow((*org)->position.y - position.y, 2) <= aquarium->controller->fishViewDistance)
			&& sqrt(pow((*org)->position.x - position.x, 2) + pow((*org)->position.y - position.y, 2) < nearestPlancton))
		{
			nearestPlancton = sqrt(pow((*org)->position.x - position.x, 2) + pow((*org)->position.y - position.y, 2));
			targetPlankton = org;
		}
	}
	if (targetPlankton != aquarium->plankton.end())
	{
		FindFood();
	}
	else
	{
		position.x += aquarium->controller->fishSpeed * cos(moveAngle * PI / 180);
		position.y += aquarium->controller->fishSpeed * sin(moveAngle * PI / 180);
		moveAngle += rand() % aquarium->controller->fishMoveRange / 2 - aquarium->controller->fishMoveRange / 2;
		if (moveAngle >= 360)
			moveAngle -= 360;

		sprite.setPosition(position.x, position.y);
	}
}

void Fish::FindFood()
{
	if (sqrt(pow((*targetPlankton)->position.x - position.x, 2) + pow((*targetPlankton)->position.y - position.y, 2) <= eatingDistance))
	{
		(*targetPlankton)->Death();
	}
	else
	{
		//тут перемещение к targetPlankton
	}
}

void Fish::Update()
{
	Move();
}

Fish::Fish()
{
}


Fish::~Fish()
{
}
