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
	Controller controller(15, 20, 10, 5, WIDTH, HEIGHT);
	Visualizer visualizer(WIDTH, HEIGHT, &controller, &res);
	controller.SetTimeScale(1);
	//установка параметров системы
	{
		controller.SetEatingDistance(5, 15);
		controller.SetHungerLifetime(70, 70);
		controller.SetLifeTime(60, 90, 100);
		controller.SetMoveRange(50, 30, 20);
		controller.SetReproductionPeriod(40, 60, 71);
		controller.SetSpeed(0.12, 0.17, 0.2);
		controller.SetViewDistance(50, 120, 120);
		visualizer.Start();
	}
	
	getchar();
}