#include "Controller.h"



Controller::Controller()
{



	Start();
}


Controller::~Controller()
{

}

void Controller::Start()
{
	while (1) //game loop ûûûûûûûûûû
	{
		Update();

	}
	
}
