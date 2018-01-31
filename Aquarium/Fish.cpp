#include "Fish.h"
#include <random>

#define PI 3.14159265

#define FRAME 45


void Fish::SetOrganisms(std::vector<Organism*>* organisms_)
{
	organisms = organisms_;
}

void Fish::Death()
{
	auto it = std::find(organisms->begin(), organisms->end(), this);
	if (it != organisms->end()) organisms->erase(it);
	delete this;
}

void Fish::Reproduction()
{
	if ((age % bioparametres->fishReproductionPeriod == 0) && (age > 0) && (isHungry == false))
	{
		Fish* newFish = new Fish(bioparametres, aquariumSize, 0, timeScale, position, moveAngle + 170 + rand() % 20);
		newFish->SetOrganisms(organisms);
		isHungry = true;
		organisms->push_back(newFish);
	}
}


void Fish::Update()
{
	float newAngle = FindPlankton();
	if ((newAngle != 0) && (age > 10))
	{
		moveAngle = newAngle + rand() % 20 - 10;
	}
	newAngle = FindShark();
	if (newAngle != 0)
	{
		moveAngle = newAngle + rand() % 20 - 10;
	}
	//чтоб не выплывали за стенки
	if (position.x <= 0)
	{
		moveAngle = 0 + rand() % 40 - 20;
	}
	if (position.x >= GetAquariumSize().x - FRAME)
	{
		moveAngle = 180 + rand() % 40 - 20;
	}
	if (position.y <= 0)
	{
		moveAngle = 90 + rand() % 40 - 20;
	}
	if (position.y >= GetAquariumSize().y - FRAME)
	{
		moveAngle = 270 + rand() % 40 - 20;
	}
	if ((age >= bioparametres->fishLifetime) || (timeWithoutEat >= bioparametres->fishHungerLifetime))
	{
		Death();
		return;
	}
	Reproduction();
	direction.x = 1 * cos(moveAngle * PI / 180);
	direction.y = 1 * sin(moveAngle * PI / 180);

	moveAngle += rand() % bioparametres->fishMoveRange - bioparametres->fishMoveRange / 2;

	if (moveAngle >= 360)
		moveAngle -= 360;
	if (moveAngle < 0)
	{
		moveAngle += 360;
	}

	age++;
	timeWithoutEat++;
}

OrganismTypes Fish::GetType()
{
	return OrganismTypes::FISH;
}

Fish::Fish(Bioparametres * bioparametres_, sf::Vector2i aquariumSize_, int index_, float * timeScale_, sf::Vector2f position_)
	: Organism(bioparametres_, aquariumSize_, index_, timeScale_, position_)
{
	age = 0;
	moveAngle = rand() % 360;
}

Fish::Fish(Bioparametres * bioparametres_, sf::Vector2i aquariumSize_, int index_, float * timeScale_, sf::Vector2f position_, float moveAngle_)
	:Organism(bioparametres_, aquariumSize_, index_, timeScale_, position_)
{
	age = 0;
	moveAngle = moveAngle_;
}

Fish::~Fish()
{
}

float Fish::FindPlankton()
{
	nearestPlankton = 1300;
	for (auto i = organisms->begin(); i != organisms->end(); ++i)
	{
		if ((*i)->GetType() == OrganismTypes::PLANKTON)
		{
			if (nearestPlankton >= sqrt(pow(position.x - (*i)->GetPosition().x, 2)
				+ pow(position.y - (*i)->GetPosition().y, 2)))
			{
				nearestPlankton = sqrt(pow(position.x - (*i)->GetPosition().x, 2)
					+ pow(position.y - (*i)->GetPosition().y, 2)); \

					targetPlankton = i;
			}
		}
	}
	if ((nearestPlankton == 1300) || (nearestPlankton >= bioparametres->fishViewDistance))
	{
		return 0;
	}
	if (nearestPlankton <= bioparametres->fishEatingDistance)
	{
		(*targetPlankton)->Death();
		isHungry = false;
		timeWithoutEat = 0;
		return 0;
	}
	else
	{
		sf::Vector2f plPos = (*targetPlankton)->GetPosition();
		if (plPos.x >= position.x)
		{
			if (plPos.y <= position.y)
			{
				return 360 - atan(abs(plPos.y - position.y) / abs(plPos.x - position.x)) * 180 / PI;
			}
			return atan(abs(plPos.y - position.y) / abs(plPos.x - position.x)) * 180 / PI;
		}
		if (plPos.x < position.x)
		{
			if (plPos.y <= position.y)
			{
				return 180 + atan(abs(plPos.y - position.y) / abs(plPos.x - position.x)) * 180 / PI;
			}
			return 180 - atan(abs(plPos.y - position.y) / abs(plPos.x - position.x)) * 180 / PI;
		}
	}
}

float Fish::FindShark()
{
	nearestShark = 1300;
	for (auto i = organisms->begin(); i != organisms->end(); ++i)
	{
		if ((*i)->GetType() == OrganismTypes::SHARK)
		{
			if (nearestShark >= sqrt(pow(position.x - (*i)->GetPosition().x, 2)
				+ pow(position.y - (*i)->GetPosition().y, 2)))
			{
				nearestShark = sqrt(pow(position.x - (*i)->GetPosition().x, 2)
					+ pow(position.y - (*i)->GetPosition().y, 2)); \

					dungerShark = i;
			}
		}
	}
	if ((nearestShark > bioparametres->fishRunningDistance) || (nearestShark == 1300))
	{
		return 0;
	}

	sf::Vector2f shPos = (*dungerShark)->GetPosition();
	if (shPos.x >= position.x)
	{
		if (shPos.y <= position.y)
		{
			return 180 - atan(abs(shPos.y - position.y) / abs(shPos.x - position.x)) * 180 / PI + rand() % 30 - 15;
		}
		return atan(abs(shPos.y - position.y) / abs(shPos.x - position.x)) * 180 / PI + rand() % 30 - 15;
	}
	if (shPos.x < position.x)
	{
		if (shPos.y <= position.y)
		{
			return atan(abs(shPos.y - position.y) / abs(shPos.x - position.x)) * 180 / PI + rand() % 30 - 15;
		}
		return atan(abs(shPos.y - position.y) / abs(shPos.x - position.x)) * 180 / PI + rand() % 30 - 15;
	}
}



