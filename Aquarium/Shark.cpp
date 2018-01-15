#include "Shark.h"
#include <cmath>
#include <random>

#define PI 3.14159265


void Shark::Death()
{
	/*if (age >= aquarium->controller->sharkLifetime)
	{
		aquarium->shark.erase(ownIter);
	}
	delete this;*/
}

void Shark::Reproduction()
{
	/*if (age % aquarium->controller->sharkReproductionPeriod == 0)
	{
		Shark* newShark = new Shark();
	}*/
}

void Shark::Move()
{
	/*targetFish = aquarium->fish.end();
	for (auto org = aquarium->fish.begin(); org != aquarium->fish.end(); ++org)
	{
		if (sqrt(pow((*org)->position.x - position.x, 2) + pow((*org)->position.y - position.y, 2) <= aquarium->controller->sharkViewDistance)
			&& sqrt(pow((*org)->position.x - position.x, 2) + pow((*org)->position.y - position.y, 2) < nearestFish))
		{
			nearestFish = sqrt(pow((*org)->position.x - position.x, 2) + pow((*org)->position.y - position.y, 2));
			targetFish = org;
		}
	}
	if (targetFish != aquarium->fish.end())
	{
		FindFood();
	}
	position.x += aquarium->controller->sharkSpeed * cos(moveAngle * PI / 180);
	position.y += aquarium->controller->sharkSpeed * sin(moveAngle * PI / 180);
	moveAngle += rand() % aquarium->controller->sharkMoveRange / 2 - aquarium->controller->sharkMoveRange / 2;
	if (moveAngle >= 360)
		moveAngle -= 360;

	sprite.setPosition(position.x, position.y);*/
}

void Shark::FindFood()
{
	//если рыба на расстоянии поедания, то жрем его
	/*if (sqrt(pow((*targetFish)->position.x - position.x, 2) + pow((*targetFish)->position.y - position.y, 2) <= aquarium->controller->sharkEatingDistanse))
	{
		(*targetFish)->Death();
	}
	else
	{
		//если нет, то меняем угол движения
		moveAngle = atan((*targetFish)->position.y / (*targetFish)->position.x) * 180 / PI;
	}*/
}

void Shark::Update()
{
	/*age++;
	Move();*/
}

Shark::Shark(float moveAngle_, Aquarium* aquarium_): Fish(moveAngle_, aquarium_)
{
	/*age = 0;
	moveAngle = rand() % 360;
	aquarium->shark.push_back(this);
	aquarium->sharkAmount++;
	ownIter = aquarium->shark.end() - 1;

	position = sf::Vector3f(rand() % 1240 + 40, rand() % 700 + 20, 0);
	sprite.setTexture(res->shark);
	sprite.setPosition(position.x, position.y);*/
}


Shark::~Shark()
{
}
