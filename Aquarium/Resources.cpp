#include "Resources.h"

Resources::Resources(std::string background_, string noise_, string bubble_, std::string plankton_,
					 std::string fish1_, std::string fish2_, std::string shark1_, std::string shark2_)
{
	background.loadFromFile(background_);
	noise.loadFromFile(noise_);
	bubble.loadFromFile(bubble_);

	plankton.loadFromFile(plankton_);
	fish1.loadFromFile(fish1_);
	fish2.loadFromFile(fish2_);
	shark1.loadFromFile(shark1_);
	shark2.loadFromFile(shark2_);
}
