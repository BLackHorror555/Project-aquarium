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
	Controller controller(7, 15, 1, 1, WIDTH, HEIGHT);
	Visualizer visualizer(WIDTH, HEIGHT, &controller, &res);
	//controller.SetTimeScale(0.5);
	//установка параметров системы
	{
		controller.SetEatingDistance(5, 5);
		controller.SetHungerLifetime(150, 120);
		controller.SetLifeTime(200, 500, 700);
		controller.SetMoveRange(500, 10, 10);
		controller.SetReproductionPeriod(100, 250, 400);
		controller.SetSpeed(0.05, 0.2, 0.3);
		controller.SetViewDistance(15, 40, 55);
		visualizer.Start();
	}
	
	getchar();
}