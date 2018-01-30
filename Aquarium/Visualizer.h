#pragma once
#include <SFML\Graphics.hpp>
#include "Resources.h"
#include "Controller.h"
#include "Effects.h"

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

	sf::Sprite fishTex1;
	sf::Sprite fishTex2;
	sf::Sprite sharkTex1;
	sf::Sprite sharkTex2;

	Effects effects;

	int* millisTimer; //������ � �������������
	int lastFrame = 0; //����� ����������� �����
	float frameTime; //������������ ������ ������ �����
	int animationSpeed = 10; //�������� �������� � ������ � �������
	int animationCounter = 0;

	//������ ����� ������������� ���������� ���� ���������� ��� ���������
	std::vector<Organism*>* organisms;

	void SwitchFrames(); //��������
	void Display(); //������� ��� ������������ ������� �� �����
	void Update();  //���������� ������ ����
	void DrawAll(); //������������ ��� ��������� � ���������
	float CalculateAngle(sf::Vector2f dir);

public:
	Visualizer(int width, int height, Controller* controller_, Resources* resources_);
	~Visualizer();

	void Start(); //������ �������� �����
	void SetResourcepack();
};

