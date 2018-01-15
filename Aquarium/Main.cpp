#include <iostream>
#include <SFML\Graphics.hpp>
#include "Controller.h"
#include <SFML\Graphics.hpp>

using namespace sf;

void main()
{
	Resources res("background.jpeg", "plankton.png", "fish.png", "shark.png");
	Controller controller(10, &res, 40, 10, 3, 1280, 720, 100, 100*720/1280);
	controller.SetParametres(100, 150, 100, 50, 100, 80, 10, 20, 30, 20, 30, 40, 40);
	controller.Start();
	


	getchar();
	
}