#include "Plankton.h"
#include <random>

void Plankton::Death()
{
	if (age >= aquarium->controller->planktonLifetime)
	{
		for (auto org = aquarium->plankton.begin(); org != aquarium->plankton.end(); ++org)
		{
			if (id == (*org)->id)
			{	
				aquarium->plankton.erase(org);
				break;
			}
		}
	}
	delete this;
}

void Plankton::Reproduction()
{
	if (age % aquarium->controller->planktonReproduction_period == 0)
	{
		Plankton* newPlancton = new Plankton();
		aquarium->plankton.push_back(newPlancton);
	}
}

void Plankton::Move()
{

}

void Plankton::Update()
{
}

Plankton::Plankton()
{
	age = 0;
}


Plankton::~Plankton()
{
}
