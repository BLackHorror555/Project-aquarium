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

	int* millisTimer; //таймер в миллисекундах
	int lastFrame = 0; //время предыдущего кадра
	float frameTime; //длительность показа одного кадра
	int animationSpeed = 10; //скорость анимации в кадрах в секунду
	int animationCounter = 0;

	//отсюда будут вытаскиваться координаты всех организмов для отрисовки
	std::vector<Organism*>* organisms;

	void SwitchFrames(); //анимация
	void Display(); //выводит все отрисованные объекты на экран
	void Update();  //вызывается каждый кадр
	void DrawAll(); //отрисовывает все организмы в аквариуме
	float CalculateAngle(sf::Vector2f dir);

public:
	Visualizer(int width, int height, Controller* controller_, Resources* resources_);
	~Visualizer();

	void Start(); //запуск игрового цикла
	void SetResourcepack();
};

