#include "Organism.h"
#include <random>


Organism::Organism(Bioparametres* bioparametres_, sf::Vector2i aquariumSize_, int index_, float* timeScale_)
{
	bioparametres = bioparametres_;
	aquariumSize = aquariumSize_;
	index = index_;
	timeScale = timeScale_;
}