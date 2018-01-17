#include "Organism.h"
#include <random>


Organism::Organism(Bioparametres* bioparametres_, sf::Vector2i aquariumSize_, int index_, float* timeScale_, sf::Vector2f position_)
{
	bioparametres = bioparametres_;
	aquariumSize = aquariumSize_;
	index = index_;
	timeScale = timeScale_;
}

void Organism::SetParametres(Bioparametres * bioparametres_)
{
	bioparametres = bioparametres_;
}

sf::Vector2f Organism::GetDirection()
{
	return direction;
}

sf::Vector2f Organism::GetPosition()
{
	return position;
}
