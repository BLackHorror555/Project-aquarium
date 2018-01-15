#pragma once
#include <SFML\Graphics.hpp>
#include "Resources.h"
#include "Controller.h"

class Visualizer
{
	void Start(); //������ �������� �����

public:
	Visualizer(int width, int height, Resources* resources_);
	~Visualizer();

	void DrawPlankton(Plankton& p);
	void DrawFish(Fish& p);
	void DrawShark(Shark& s);

	void Display(); //������� ��� ������������ ������� �� �����
	void Update(); //���������� ������ ����

	Controller* controller;
	Resources* resources;
	sf::RenderWindow* window;
	sf::Sprite planktonSprite;
	sf::Sprite fishSprite;
	sf::Sprite sharkSprite;
	sf::Sprite background;
};

