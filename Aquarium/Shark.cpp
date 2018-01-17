#include "Shark.h"
#include <cmath>
#include <random>

#define PI 3.14159265

#define FRAME 55


void Shark::Death()
{
	auto it = std::find(sharks->begin(), sharks->end(), this);
	if (it != sharks->end()) sharks->erase(it);
	delete this;
}

void Shark::Reproduction()
{
	if ((age % bioparametres->sharkReproductionPeriod == 0) && (age > 0))
	{
		Shark* newShark = new Shark(bioparametres, aquariumSize, 0, timeScale, position);
		newShark->SetOrganisms(fishs, sharks);
		sharks->push_back(newShark);
	}
}


void Shark::Update()
{
	if (age >= bioparametres->sharkLifetime)
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
		moveAngle += rand() % bioparametres->sharkMoveRange - bioparametres->sharkMoveRange / 2;
	}

	if (moveAngle >= 360)
		moveAngle -= 360;
	if (moveAngle < 0)
	{
		moveAngle += 360;
	}
	age++;
}

Shark::Shark(Bioparametres * bioparametres_, sf::Vector2i aquariumSize_, int index_, float * timeScale_, sf::Vector2f position_)
	:Organism(bioparametres_, aquariumSize_, index_, timeScale_, position_)
{
	age = 0;
	moveAngle = rand() % 360;
}

Shark::~Shark()
{
}

void Shark::SetOrganisms(std::vector<Fish*>* fishs_, std::vector<Shark*>* sharks_)
{
	fishs = fishs_;
	sharks = sharks_;
}

/*
void Shark::FindFood()
{
	//если рыба на расстоянии поедания, то жрем его
	if (sqrt(pow((*targetFish)->position.x - position.x, 2) + pow((*targetFish)->position.y - position.y, 2) <= aquarium->controller->sharkEatingDistanse))
	{
		(*targetFish)->Death();
	}
	else
	{
		//если нет, то меняем угол движения
		moveAngle = atan((*targetFish)->position.y / (*targetFish)->position.x) * 180 / PI;
	}
}

Shark::Shark(float moveAngle_, Aquarium* aquarium_): Fish(moveAngle_, aquarium_)
{
	age = 0;
	moveAngle = rand() % 360;
	aquarium->shark.push_back(this);
	aquarium->sharkAmount++;
	ownIter = aquarium->shark.end() - 1;

	position = sf::Vector3f(rand() % 1240 + 40, rand() % 700 + 20, 0);
	sprite.setTexture(res->shark);
	sprite.setPosition(position.x, position.y);
}
*/


