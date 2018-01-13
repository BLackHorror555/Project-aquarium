#include "Visualizer.h"



Visualizer::Visualizer()
{
	window = new sf::RenderWindow(sf::VideoMode(800, 600), "Aquarium");
}

Visualizer::Visualizer(int width, int height, std::string background)
{
	this->background.loadFromFile(background);
	window = new sf::RenderWindow(sf::VideoMode(width, height), "Aquarium");
}


Visualizer::~Visualizer()
{
}
