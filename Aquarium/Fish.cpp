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
	if ((age % bioparametres->fishReproductionPeriod == 0) && (age > 0))
	{
		Fish* newFish = new Fish(bioparametres, aquariumSize, 0, timeScale, position);
		newFish->SetOrganisms(organisms);
		organisms->push_back(newFish);
	}
}


void Fish::Update()
{
	sf::Vector2f plancPos = FindPlankton();
	if (plancPos.x != 0)
	{
		moveAngle = plancPos.x;
	}
	if ((age >= bioparametres->fishLifetime) || (timeWithoutEat >= bioparametres->fishHungerLifetime))
	{
		Death();
		return;
	}
	Reproduction();
	direction.x = 1 * cos(moveAngle * PI / 180);
	direction.y = 1 * sin(moveAngle * PI / 180);

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

Fish::~Fish()
{
}

sf::Vector2f Fish::FindPlankton()
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
	if (nearestPlankton == 1300)
	{
		return sf::Vector2f(0, 0);
	}
	if (nearestPlankton >= bioparametres->fishViewDistance)
	{
		return sf::Vector2f(0, 0);
	}
	if (nearestPlankton <= bioparametres->fishEatingDistance)
	{
		(*targetPlankton)->Death();
		timeWithoutEat = 0;
		return sf::Vector2f(0, 0);
	}
	else if (nearestPlankton == 1300)
	{
		return sf::Vector2f(0, 0);
	}
	else
	{
		sf::Vector2f plPos = (*targetPlankton)->GetPosition();
		if (plPos.x >= position.x)
		{
			if (plPos.y <= position.y)
			{
				return sf::Vector2f(360 - atan(abs(plPos.y - position.y) / abs(plPos.x - position.x)) * 180 / PI, 0);
			}
			return sf::Vector2f(atan(abs(plPos.y - position.y) / abs(plPos.x - position.x)) * 180 / PI, 0);
		}
		if (plPos.x < position.x)
		{
			if (plPos.y <= position.y)
			{
				return sf::Vector2f(180 + atan(abs(plPos.y - position.y) / abs(plPos.x - position.x)) * 180 / PI, 0);
			}
			return sf::Vector2f(180 - atan(abs(plPos.y - position.y) / abs(plPos.x - position.x)) * 180 / PI, 0);
		}
			
		
	}
}



