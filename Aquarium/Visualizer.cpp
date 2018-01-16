#include "Visualizer.h"
#include "Visualizer.h"


Visualizer::Visualizer(int width, int height, Controller* controller_, Resources* resources_)
{
	controller = controller_;
	resources = resources_;
	window = new sf::RenderWindow(sf::VideoMode(width, height), "Aquarium");
}

Visualizer::~Visualizer()
{
}

void Visualizer::Start()
{
}

void Visualizer::Display()
{
	window->display();
}
