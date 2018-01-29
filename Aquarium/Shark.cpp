#include "Shark.h"
#include <cmath>

#define PI 3.14159265

#define FRAME 55


void Shark::Death()
{
	auto it = std::find(organisms->begin(), organisms->end(), this);
	if (it != organisms->end()) organisms->erase(it);
	delete this;
}

void Shark::Reproduction()
{
	if ((age % bioparametres->sharkReproductionPeriod == 0) && (age > 0))
	{
		Shark* newShark = new Shark(bioparametres, aquariumSize, 0, timeScale, position, moveAngle + 170 + rand() % 20);
		newShark->SetOrganisms(organisms);
		organisms->push_back(newShark);
	}
}


void Shark::Update()
{
	float newAngle = FindFish();
	if ((newAngle != 0) && (age > 100))
	{
		moveAngle = newAngle;
	}
	if ((age >= bioparametres->sharkLifetime) || (timeWithoutEat >= bioparametres->sharkHungerLifetime))
	{
		Death();
		return;
	}
	if (position.x <= 0)
	{
		moveAngle = 0 + rand() % 20 - 10;
	}
	if (position.x >= GetAquariumSize().x - FRAME)
	{
		moveAngle = 180 + rand() % 20 - 10;
	}
	if (position.y <= 0)
	{
		moveAngle = 90 + rand() % 20 - 10;
	}
	if (position.y >= GetAquariumSize().y - FRAME)
	{
		moveAngle = 270 + rand() % 20 - 10;
	}
	Reproduction();
	direction.x = 1 * cos(moveAngle * PI / 180);
	direction.y = 1 * sin(moveAngle * PI / 180);

	
	moveAngle += rand() % bioparametres->sharkMoveRange - bioparametres->sharkMoveRange / 2;

	if (moveAngle >= 360)
		moveAngle -= 360;
	if (moveAngle < 0)
	{
		moveAngle += 360;
	}
	age++;
}

OrganismTypes Shark::GetType()
{
	return OrganismTypes::SHARK;
}

float Shark::FindFish()
{
	nearestFish = 1300;
	for (auto i = organisms->begin(); i != organisms->end(); ++i)
	{
		if ((*i)->GetType() == OrganismTypes::FISH)
		{
			if (nearestFish >= sqrt(pow(position.x - (*i)->GetPosition().x, 2)
				+ pow(position.y - (*i)->GetPosition().y, 2)))
			{
				nearestFish = sqrt(pow(position.x - (*i)->GetPosition().x, 2)
					+ pow(position.y - (*i)->GetPosition().y, 2)); \

					targetFish = i;
			}
		}
	}
	if (nearestFish == 1300)
	{
		return 0;
	}
	if (nearestFish >= bioparametres->sharkViewDistance)
	{
		return 0;
	}
	if (nearestFish <= bioparametres->sharkEatingDistance)
	{
		(*targetFish)->Death();
		timeWithoutEat = 0;
		return 0;
	}
	else if (nearestFish == 1300)
	{
		return 0;
	}
	else
	{
		sf::Vector2f plPos = (*targetFish)->GetPosition();
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

Shark::Shark(Bioparametres * bioparametres_, sf::Vector2i aquariumSize_, int index_, float * timeScale_, sf::Vector2f position_)
	:Organism(bioparametres_, aquariumSize_, index_, timeScale_, position_)
{
	age = 0;
	moveAngle = rand() % 360;
}

Shark::Shark(Bioparametres * bioparametres_, sf::Vector2i aquariumSize_, int index_, float * timeScale_, sf::Vector2f position_, float moveAngle_)
	:Organism(bioparametres_, aquariumSize_, index_, timeScale_, position_)
{
	age = 0;
	moveAngle = moveAngle_;
}

Shark::~Shark()
{
}

void Shark::SetOrganisms(std::vector<Organism*>* organisms_)
{
	organisms = organisms_;
}




