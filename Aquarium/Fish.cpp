#include "Fish.h"
#include <random>

#define PI 3.14159265



void Fish::SetOrganisms(std::vector<Plankton*>* planktons_, std::vector<Fish*>* fishs_, std::vector<Shark*>* sharks_)
{
	planktons = planktons_;
	fishs = fishs_;
	sharks = sharks_;
}

void Fish::Death()
{
	/*if (age >= aquarium->controller->fishLifetime)
	{
		aquarium->fish.erase(ownIter);
	}
	delete this;*/
}

void Fish::Reproduction()
{
	/*if (age % aquarium->controller->fishReproductionPeriod == 0)
	{
		Fish* newFish = new Fish();
	}*/
}


void Fish::Update()
{
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

Fish::Fish(Bioparametres * bioparametres_, sf::Vector2i aquariumSize_, int index_, float * timeScale_, sf::Vector2f position_)
	: Organism(bioparametres_, aquariumSize_, index_, timeScale_, position_)
{
	age = 0;
	moveAngle = rand() % 360;
}

Fish::~Fish()
{
}

/*
sf::Vector2f Fish::FindPlankton()
{
	//если планктон на расстоянии поедания, то жрем его
	if (sqrt(pow((*targetPlankton)->position.x - position.x, 2) + pow((*targetPlankton)->position.y - position.y, 2) <= aquarium->controller->fishEatingDistance))
	{
		(*targetPlankton)->Death();
	}
	else
	{
		//если нет, то меняем угол движения
		moveAngle = atan((*targetPlankton)->position.y / (*targetPlankton)->position.x) * 180 / PI;
	}
}

sf::Vector2f Fish::FindShark()
{

}

Fish::Fish()
{
	age = 0;
	moveAngle = rand() % 360;
	aquarium->fish.push_back(this);
	aquarium->fishAmount++;
	ownIter = aquarium->fish.end() - 1;

	position = sf::Vector3f(rand() % 1240 + 40, rand() % 700 + 20, 0);
	sprite.setTexture(res->fish);
	sprite.setPosition(position.x, position.y);
}

*/


