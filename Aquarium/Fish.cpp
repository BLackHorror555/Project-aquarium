#include "Fish.h"
#include <random>

#define PI 3.14159265



void Fish::Death()
{
	if (age >= aquarium->controller->fishLifetime)
	{
		aquarium->fish.erase(ownIter);
	}
	delete this;
}

void Fish::Reproduction()
{
	if (age % aquarium->controller->fishReproductionPeriod == 0)
	{
		Fish* newFish = new Fish();
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
	position.x += aquarium->controller->fishSpeed * cos(moveAngle * PI / 180);
	position.y += aquarium->controller->fishSpeed * sin(moveAngle * PI / 180);
	moveAngle += rand() % aquarium->controller->fishMoveRange / 2 - aquarium->controller->fishMoveRange / 2;
	if (moveAngle >= 360)
		moveAngle -= 360;

	sprite.setPosition(position.x, position.y);

}

void Fish::FindFood()
{
	//���� �������� �� ���������� ��������, �� ���� ���
	if (sqrt(pow((*targetPlankton)->position.x - position.x, 2) + pow((*targetPlankton)->position.y - position.y, 2) <= aquarium->controller->fishEatingDistance))
	{
		(*targetPlankton)->Death();
	}
	else
	{
		//���� ���, �� ������ ���� ��������
		moveAngle = atan((*targetPlankton)->position.y / (*targetPlankton)->position.x) * 180 / PI;
	}
}

void Fish::Update()
{
	age++;
	Move();
}

Fish::Fish()
{
	age = 0;
	moveAngle = rand() % 360;
	aquarium->fish.push_back(this);
	ownIter = aquarium->fish.end() - 1;

	position = sf::Vector3f(rand() % 1240 + 40, rand() % 700 + 20, 0);
	sprite.setPosition(position.x, position.y);
}


Fish::~Fish()
{
}
