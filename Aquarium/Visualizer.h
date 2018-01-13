#pragma once
#include <SFML\Graphics.hpp>
#include "Displayable.h"
class Visualizer
{
	sf::Texture background;
	sf::RenderWindow* window;
public:

	Visualizer();
	Visualizer(int width, int height, std::string background);
	~Visualizer();

	void Draw(Displayable object);
	void Display(); //выводит все отрисованные объекты на экран
};

