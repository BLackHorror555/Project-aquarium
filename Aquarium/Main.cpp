#include <iostream>
#include <SFML\Graphics.hpp>
#include "Controller.h"
#include <SFML\Graphics.hpp>

using namespace sf;

void main()
{
	Resources res("background.jpeg", "plankton.png", "fish.png", "shark.png");
	Controller controller(10, &res, 40, 10, 3, 1280, 720, 100, 100*720/1280);
	controller.SetEatingDistance(5, 5);
	controller.SetHungerLifetime(150, 120);
	controller.SetLifeTime(200, 500, 700);
	controller.SetMoveRange(20, 10, 10);
	controller.SetReproductionPeriod(100, 250, 400);
	controller.SetSpeed(2, 3, 4);
	controller.SetViewDistance(15, 40, 55);
	controller.Start();
	


	getchar();
	
}