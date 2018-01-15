#include "Displayable.h"



Displayable::Displayable(Aquarium* aquarium_)
{
	res = aquarium->controller->visualizer.res;
}


Displayable::~Displayable()
{
}

