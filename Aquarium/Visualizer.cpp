#include "Visualizer.h"
#include "Visualizer.h"


Visualizer::Visualizer(int width, int height, Controller* controller_, Resources* resources_)
{
	//инициализация
	screenSize = sf::Vector2i(width, height);
	controller = controller_;
	resources = resources_;
	window = new sf::RenderWindow(sf::VideoMode(width, height), "Aquarium");
	//фон
	background.setTexture(resources->background);
	background.setPosition(0, 0);
}

Visualizer::~Visualizer()
{
}

//запуск игрового цикла тут
void Visualizer::Start()
{
	//фиксируем время запуска
	SYSTEMTIME st;
	GetSystemTime(&st);
	int startTime = st.wMilliseconds + st.wSecond * 1000 + st.wMinute * 60000 + st.wHour * 3600000;
	controller->SetStartTime(startTime);


	while (window->isOpen())
	{
		//события


		//вычисления
		Update();

		//отрисовка
		window->draw(background);
		Display();
	}
}

void Visualizer::Display()
{
	window->display();
}

void Visualizer::Update()
{
	controller->Update();
}
