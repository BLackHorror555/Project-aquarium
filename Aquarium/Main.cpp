#include <iostream>
#include <SFML\Graphics.hpp>
#include "Controller.h"
#include "Resources.h"
#include "Visualizer.h"

using namespace sf;

#define WIDTH 1280
#define HEIGHT 720

void main()
{
	Resources res("background.jpg", "plankton.png", "fish.png", "shark.png");
	Controller controller(15, 10, 5, 3, WIDTH, HEIGHT);
	Visualizer visualizer(WIDTH, HEIGHT, &controller, &res);
	//controller.SetTimeScale(0.5);
	//установка параметров системы
	{
		controller.SetEatingDistance(5, 5);
		controller.SetHungerLifetime(150, 120);
		controller.SetLifeTime(60, 70, 80);
		controller.SetMoveRange(50, 30, 10);
		controller.SetReproductionPeriod(50, 60, 70);
		controller.SetSpeed(0.12, 0.2, 0.25);
		controller.SetViewDistance(1000, 40, 55);
		visualizer.Start();
	}
	
	getchar();
}