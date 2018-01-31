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
	Resources res("background.jpg", "noise.png", "bubble.png", "plankton.png", 
				  "fish1.png", "fish2.png", "shark1.png", "shark2.png");
	Controller controller(8, 27, 22, 4, WIDTH, HEIGHT);
	Visualizer visualizer(WIDTH, HEIGHT, &controller, &res);
	controller.SetTimeScale(1);
	//установка параметров системы
	{
		controller.SetEatingDistance(5, 15);
		controller.SetHungerLifetime(130, 150);
		controller.SetLifeTime(74, 159, 270);
		controller.SetMoveRange(20, 14, 17);
		controller.SetReproductionPeriod(35, 80, 90);
		controller.SetSpeed(0.07, 0.09, 0.1);
		controller.SetViewDistance(50, 300, 400, 100);
		controller.SetMaxAnimals(250, 0, 0); //робит только для планктона
		visualizer.Start();
	}
	
	getchar();
}