#include "Displayable.h"



Displayable::Displayable()
{
}


Displayable::~Displayable()
{
}

void Displayable::Draw()
{
	sprite.setPosition(position);
}
