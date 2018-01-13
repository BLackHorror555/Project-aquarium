#include "Fish.h"



void Fish::FindFood()
{
}

void Fish::Eat()
{
}

void Fish::Death()
{
	if (age >= aquarium->controller->fishLifetime)
	{
		for (auto org = aquarium->fish.begin(); org != aquarium->fish.end(); ++org)
		{
			if (id == (*org)->id)
			{
				aquarium->fish.erase(org);
				break;
			}
		}
	}
	delete this;
}

void Fish::Reproduction()
{
	if (age % aquarium->controller->fishReproduction_period == 0)
	{
		Fish* newFish = new Fish();
		aquarium->fish.push_back(newFish);
	}
}

void Fish::Move()
{
}

void Fish::Update()
{
}

Fish::Fish()
{
}


Fish::~Fish()
{
}
