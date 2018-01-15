#include "Resources.h"

Resources::Resources(std::string background, std::string plankton, std::string fish, std::string shark)
{
	this->background.loadFromFile(background);
	this->plankton.loadFromFile(plankton);
	this->fish.loadFromFile(fish);
	this->shark.loadFromFile(shark);
}
