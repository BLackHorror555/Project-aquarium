#pragma once
#include <SFML\Graphics.hpp>
#include "Resources.h"
#include "Controller.h"

class Visualizer
{
	void Start(); //запуск игрового цикла

public:
	Visualizer(int width, int height, Resources* resources_);
	~Visualizer();

	void DrawPlankton(Plankton& p);
	void DrawFish(Fish& p);
	void DrawShark(Shark& s);

	void Display(); //выводит все отрисованные объекты на экран
	void Update(); //вызывается каждый кадр

	Controller* controller;
	Resources* resources;
	sf::RenderWindow* window;
	sf::Sprite planktonSprite;
	sf::Sprite fishSprite;
	sf::Sprite sharkSprite;
	sf::Sprite background;
};

