#include "Shark.h"



void Shark::FindFood()
{
}

void Shark::Eat()
{
}

void Shark::Death()
{
	if (age >= aquarium->controller->sharkLifetime)
	{
		for (auto org = aquarium->shark.begin(); org != aquarium->shark.end(); ++org)
		{
			if (id == (*org)->id)
			{
				aquarium->shark.erase(org);
				break;
			}
		}
	}
	delete this;
}

void Shark::Reproduction()
{
	if (age % aquarium->controller->sharkReproduction_period == 0)
	{
		Shark* newShark = new Shark();
		aquarium->shark.push_back(newShark);
	}
}

void Shark::Move()
{
}

void Shark::Update()
{
}

Shark::Shark()
{
}


Shark::~Shark()
{
}
