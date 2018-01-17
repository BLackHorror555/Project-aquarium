#pragma once
#include <SFML\Graphics.hpp>
#include "Resources.h"
#include "Controller.h"

class Visualizer
{
	sf::Vector2i screenSize;
	Controller* controller;
	Resources* resources;
	sf::RenderWindow* window;
	sf::Sprite planktonSprite;
	sf::Sprite fishSprite;
	sf::Sprite sharkSprite;
	sf::Sprite background;

	//������ ����� ������������� ���������� ���� ���������� ��� ���������
	std::vector<Plankton*>* plankton;
	std::vector<Fish*>* fish;
	std::vector<Shark*>* shark;

	void DrawPlankton(Plankton& p);
	void DrawFish(Fish& p);
	void DrawShark(Shark& s);

	void Display(); //������� ��� ������������ ������� �� �����
	void Update();  //���������� ������ ����
	void DrawAll(); //������������ ��� ��������� � ���������

public:
	Visualizer(int width, int height, Controller* controller_, Resources* resources_);
	~Visualizer();

	void Start(); //������ �������� �����
	void SetResourcepack();
};

