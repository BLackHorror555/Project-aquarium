#include "Aquarium.h"



Aquarium::Aquarium()
{
}

Aquarium::Aquarium(sf::Vector2i _size)
{

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
}

void Aquarium::p()
{

}

/*
void Aquarium::updateAnimals()
{
	for (int i = 0; i < plankton.size(); i++)
	{
		plankton[i]->Update();
	}
	for (int i = 0; i < fish.size(); i++)
	{
		fish[i]->Update();
	}
	for (int i = 0; i < shark.size(); i++)
	{
		shark[i]->Update();
	}
}*/
