#pragma once
#include <SFML\Graphics.hpp>
#include "Displayable.h"
#include "Resources.h"

class Visualizer
{
	Resources* res;
	sf::RenderWindow* window;
public:

	Visualizer();
	Visualizer(int width, int height, Resources* res);
	~Visualizer();

	void Draw(Displayable object);
	void Display(); //выводит все отрисованные объекты на экран
};

