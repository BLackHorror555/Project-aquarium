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
	Resources res("background.jpg", "plankton.png", "fish.png", "shark.png", "fish1.png", "fish2.png",
		"shark1.png", "shark2.png");
	Controller controller(15, 15, 10, 3, WIDTH, HEIGHT);
	Visualizer visualizer(WIDTH, HEIGHT, &controller, &res);
	controller.SetTimeScale(3);
	//установка параметров системы
	{
		controller.SetEatingDistance(5, 15);
		controller.SetHungerLifetime(300, 500);
		controller.SetLifeTime(325, 600, 1000);
		controller.SetMoveRange(30, 30, 25);
		controller.SetReproductionPeriod(160, 100, 300);
		controller.SetSpeed(0.09, 0.07, 0.1);
		controller.SetViewDistance(50, 300, 400, 100);
		visualizer.Start();
	}
	
	getchar();
}