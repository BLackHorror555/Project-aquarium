#include "Fish.h"
#include <random>

#define PI 3.14159265

#define FRAME 45


void Fish::SetOrganisms(std::vector<Plankton*>* planktons_, std::vector<Fish*>* fishs_, std::vector<Shark*>* sharks_)
{
	planktons = planktons_;
	fishs = fishs_;
	sharks = sharks_;
}

void Fish::Death()
{
	auto it = std::find(fishs->begin(), fishs->end(), this);
	if (it != fishs->end()) fishs->erase(it);
	delete this;
}

void Fish::Reproduction()
{
	if ((age % bioparametres->fishReproductionPeriod == 0) && (age > 0))
	{
		Fish* newFish = new Fish(bioparametres, aquariumSize, 0, timeScale, position);
		newFish->SetOrganisms(planktons, fishs, sharks);
		fishs->push_back(newFish);
	}
}


void Fish::Update()
{
	/*sf::Vector2f plancPos = FindPlankton();
	if (plancPos.x != 0)
	{
		moveAngle = plancPos.x;
	}*/
	if (age >= bioparametres->fishLifetime)
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
		moveAngle += rand() % bioparametres->fishMoveRange - bioparametres->sharkMoveRange / 2;
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

sf::Vector2f Fish::FindPlankton()
{
	nearestPlankton = 1300;
	for (auto i = planktons->begin(); i != planktons->end(); ++i)
	{
		
		if (nearestPlankton >= sqrt(pow(position.x - (*i)->GetPosition().x, 2) 
			+ pow(position.y - (*i)->GetPosition().y, 2)))
		{
			nearestPlankton = sqrt(pow(position.x - (*i)->GetPosition().x, 2)
				+ pow(position.y - (*i)->GetPosition().y, 2));\

			targetPlankton = i;
		}
	}
	if (nearestPlankton <= bioparametres->fishEatingDistance)
	{
		(*targetPlankton)->Death();
		return sf::Vector2f(0, 0);
	}
	else if (nearestPlankton == 1300)
	{
		return sf::Vector2f(0, 0);
	}
	else
	{
		sf::Vector2f plPos = (*targetPlankton)->GetPosition();
		//if (plPos.x >= position.x)
			return sf::Vector2f(360 - atan((plPos.y - position.y) / (plPos.x - position.x)) * 180 / PI, 0);
		//if (plPos.x < position.x)
			//return sf::Vector2f(180 + atan((plPos.y - position.y) / (plPos.x - position.x)) * 180 / PI, 0);
	}
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
*/


