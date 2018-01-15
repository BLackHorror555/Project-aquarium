#pragma once
#include <SFML\Graphics.hpp>
#include "Displayable.h"
#include "Resources.h"

class Visualizer
{
	
	sf::RenderWindow* window;
public:
	Resources* res;

	Visualizer();
	Visualizer(int width, int height, Resources* res);
	~Visualizer();

	void Draw(Displayable object);
	void Display(); //выводит все отрисованные объекты на экран
};

