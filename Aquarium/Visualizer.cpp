#include "Visualizer.h"


Visualizer::Visualizer(int width, int height, Controller* controller_, Resources* resources_)
{
	//инициализация
	screenSize = sf::Vector2i(width, height);
	resources = resources_;
	window = new sf::RenderWindow(sf::VideoMode(width, height), "Aquarium");

	controller = controller_;
	//plankton = controller->GetAquarium()->GetPlanktons();
	//fish = controller->GetAquarium()->GetFishs();
	//shark = controller->GetAquarium()->GetSharks();
	organisms = controller->GetAquarium()->GetOrganisms();

	//фон
	background.setTexture(resources->background);
	background.setPosition(0, 0);

	planktonSprite.setTexture(resources->plankton);
	fishSprite.setTexture(resources->fish);
	sharkSprite.setTexture(resources->shark);
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
		//planktonSprite.setPosition(100, 100);
		//window->draw(planktonSprite);
		DrawAll();
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

void Visualizer::DrawAll()
{
	for (int i = 0; i < organisms->size(); i++)
	{
		if ((*organisms)[i]->GetType() == OrganismTypes::PLANKTON)
		{
			planktonSprite.setPosition((*organisms)[i]->GetPosition());
			window->draw(planktonSprite);
		}
		else if ((*organisms)[i]->GetType() == OrganismTypes::FISH)
		{
			planktonSprite.setPosition((*organisms)[i]->GetPosition());
			window->draw(fishSprite);
		} 
		else if ((*organisms)[i]->GetType() == OrganismTypes::SHARK)
		{
			planktonSprite.setPosition((*organisms)[i]->GetPosition());
			window->draw(sharkSprite);
		}
	}

}
