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

void Plankton::Move()
{
	/*position.x += aquarium->controller->planktonSpeed * cos(moveAngle * PI / 180);
	position.y += aquarium->controller->planktonSpeed * sin(moveAngle * PI / 180);
	moveAngle += rand() % aquarium->controller->planktonMoveRange / 2 - aquarium->controller->planktonMoveRange / 2;
	if (moveAngle >= 360)
		moveAngle -= 360;

	sprite.setPosition(position.x, position.y);*/
}

void Plankton::Update()
{
	/*age++;
	Move();*/
}

Plankton::Plankton(Bioparametres* bioparametres_, sf::Vector2i aquariumSize_, int index_, float* timeScale_)
	: Organism(bioparametres_, aquariumSize_, index_, timeScale_)
{
}

Plankton::~Plankton()
{
}

/*
Plankton::Plankton(float moveAngle_, Aquarium* aquarium_): Organism(moveAngle_, aquarium_)
{
	age = 0;
	moveAngle = rand() % 360;
	aquarium->plankton.push_back(this);
	aquarium->planctonAmount++;
	ownIter = aquarium->plankton.end() - 1;

	position = sf::Vector3f(rand() % 1240 + 40, rand() % 700 + 20, 0);
	sprite.setTexture(res->plankton);
	sprite.setPosition(position.x, position.y);
}*/


