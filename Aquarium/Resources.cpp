#include "Resources.h"

Resources::Resources(std::string background, std::string plankton, std::string fish, std::string shark,
					 std::string fish1, std::string fish2, std::string shark1, std::string shark2)
{
	this->background.loadFromFile(background);
	this->plankton.loadFromFile(plankton);
	this->fish.loadFromFile(fish);
	this->shark.loadFromFile(shark);

	fishTex1.loadFromFile(fish1);
	fishTex2.loadFromFile(fish2);
	sharkTex1.loadFromFile(shark1);
	sharkTex2.loadFromFile(shark2);
}
