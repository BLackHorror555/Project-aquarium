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

int Aquarium::GetPlanktonNumber()
{
	return plankton.size();
}

int Aquarium::GetFishNumber()
{
	return fish.size();
}

int Aquarium::GetSharkNumber()
{
	return shark.size();
}

std::vector<Plankton*>* Aquarium::GetPlanktons()
{
	return &plankton;
}

std::vector<Fish*>* Aquarium::GetFishs()
{
	return &fish;
}

std::vector<Shark*>* Aquarium::GetSharks()
{
	return &shark;
}


sf::Vector2i Aquarium::GetSize()
{
	return size;
}

void Aquarium::UpdateAnimals()
{
	for (size_t i = 0; i < plankton.size(); ++i)
	{
		plankton[i]->Update();
	}

	for (size_t i = 0; i < fish.size(); ++i)
	{
		fish[i]->Update();
	}

	for (size_t i = 0; i < shark.size(); ++i)
	{
		shark[i]->Update();
	}
}

void Aquarium::MoveAnimals()
{
	sf::Vector2f position;
	sf::Vector2f direction;
	for (auto pl = plankton.begin(); pl != plankton.end(); ++pl)
	{
		position = (*pl)->GetPosition();
		direction = (*pl)->GetDirection();
		(*pl)->SetPosition(position + sf::Vector2f(direction.x * bioparametres->planktonSpeed * *timeScale, direction.y * bioparametres->planktonSpeed * *timeScale));
	}

	for (auto f = fish.begin(); f != fish.end(); ++f)
	{
		position = (*f)->GetPosition();
		direction = (*f)->GetDirection();
		(*f)->SetPosition(position + sf::Vector2f(direction.x * bioparametres->fishSpeed * *timeScale, direction.y * bioparametres->fishSpeed * *timeScale));
	}

	for (auto sh = shark.begin(); sh != shark.end(); ++sh)
	{
		position = (*sh)->GetPosition();
		direction = (*sh)->GetDirection();
		(*sh)->SetPosition(position + sf::Vector2f(direction.x * bioparametres->sharkSpeed * *timeScale, direction.y * bioparametres->sharkSpeed * *timeScale));
	}
}
