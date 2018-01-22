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
	sf::Vector2f plancPos = FindFish();
	if (plancPos.x != 0)
	{
		moveAngle = plancPos.x;
	}
	if ((age >= bioparametres->sharkLifetime) || (timeWithoutEat >= bioparametres->sharkHungerLifetime))
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

sf::Vector2f Shark::FindFish()
{
	nearestFish = 1300;
	for (auto i = fishs->begin(); i != fishs->end(); ++i)
	{

		if (nearestFish > sqrt(pow(position.x - (*i)->GetPosition().x, 2)
			+ pow(position.y - (*i)->GetPosition().y, 2)))
		{
			nearestFish = sqrt(pow(position.x - (*i)->GetPosition().x, 2)
				+ pow(position.y - (*i)->GetPosition().y, 2)); \

				targetFish = i;
		}
	}
	if (nearestFish == 1300)
	{
		return sf::Vector2f(0, 0);
	}
	if (nearestFish >= bioparametres->sharkViewDistance)
	{
		return sf::Vector2f(0, 0);
	}
	if (nearestFish <= bioparametres->sharkEatingDistance)
	{
		(*targetFish)->Death();
		timeWithoutEat = 0;
		return sf::Vector2f(0, 0);
	}
	else if (nearestFish == 1300)
	{
		return sf::Vector2f(0, 0);
	}
	else
	{
		sf::Vector2f plPos = (*targetFish)->GetPosition();
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




