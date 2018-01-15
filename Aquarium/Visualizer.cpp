#include "Visualizer.h"



Visualizer::Visualizer()
{
	window = new sf::RenderWindow(sf::VideoMode(800, 600), "Aquarium");
}

Visualizer::Visualizer(int width, int height, Resources* res)
{
	this->res = res;
	window = new sf::RenderWindow(sf::VideoMode(width, height), "Aquarium");
}

Visualizer::~Visualizer()
{
}

void Visualizer::Draw(Displayable object)
{
	window->draw(object.sprite);
}

void Visualizer::Display()
{
	window->display();
}
