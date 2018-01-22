#include "Aquarium.h"



Aquarium::Aquarium()
{
}

Aquarium::Aquarium(sf::Vector2i _size, Bioparametres* bioparametres_, float* timeScale_)
{
	bioparametres = bioparametres_;
	timeScale = timeScale_;
	size = _size;
}

Aquarium::~Aquarium()
{
}


std::vector<Organism*>* Aquarium::GetOrganisms()
{
	return &organisms;
}



sf::Vector2i Aquarium::GetSize()
{
	return size;
}

void Aquarium::UpdateAnimals()
{
	for (size_t i = 0; i < organisms.size(); ++i)
	{
		organisms[i]->Update();
	}
}

void Aquarium::MoveAnimals()
{
	sf::Vector2f position;
	sf::Vector2f direction;
	for (auto org = organisms.begin(); org != organisms.end(); ++org)
	{
		position = (*org)->GetPosition();
		direction = (*org)->GetDirection();
		if ((*org)->GetType() == OrganismTypes::PLANKTON)
			(*org)->SetPosition(position + sf::Vector2f(direction.x * bioparametres->planktonSpeed * *timeScale, direction.y * bioparametres->planktonSpeed * *timeScale));
		else if ((*org)->GetType() == OrganismTypes::FISH)
			(*org)->SetPosition(position + sf::Vector2f(direction.x * bioparametres->fishSpeed * *timeScale, direction.y * bioparametres->fishSpeed * *timeScale));
		else
			(*org)->SetPosition(position + sf::Vector2f(direction.x * bioparametres->sharkSpeed * *timeScale, direction.y * bioparametres->sharkSpeed * *timeScale));
	}
}