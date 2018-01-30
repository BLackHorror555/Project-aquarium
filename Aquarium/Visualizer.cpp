#include "Visualizer.h"

Visualizer::Visualizer(int width, int height, Controller* controller_, Resources* resources_)
{
	//инициализация
	screenSize = sf::Vector2i(width, height);
	resources = resources_;
	window = new sf::RenderWindow(sf::VideoMode(width, height), "Aquarium");

	controller = controller_;
	organisms = controller->GetAquarium()->GetOrganisms();

	//фон
	background.setTexture(resources->background);
	background.setPosition(0, 0);

	//спрайты рыб
	planktonSprite.setTexture(resources->plankton);
	fishSprite.setTexture(resources->fish2);
	sharkSprite.setTexture(resources->shark2);

	planktonSprite.setScale(0.75, 0.75);
	fishSprite.setScale(1.75, 1.75);
	sharkSprite.setScale(2.5, 2.5);

	planktonSprite.setOrigin(resources->plankton.getSize().x / 2, resources->plankton.getSize().y / 2);
	fishSprite.setOrigin(resources->fish1.getSize().x / 2, resources->fish1.getSize().y / 2);
	sharkSprite.setOrigin(resources->shark1.getSize().x / 2, resources->shark1.getSize().y / 2);

	//анимация
	millisTimer = &(controller->millisTimer);
	animationSpeed = 3;
	frameTime = 1.0 / animationSpeed * 1000;

	effects = Effects(millisTimer, window, resources);
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
	effects.Start(); //инициализация системы эффектов

	while (window->isOpen())
	{
		//события

		//вычисления
		if (*millisTimer - lastFrame >= frameTime)
		{
			SwitchFrames();
		}

		Update();

		//отрисовка
		window->draw(background);
		DrawAll();
		effects.Update();
		Display();
	}
}

void Visualizer::SwitchFrames()
{
	if (animationCounter % 2 == 0)
	{
		fishSprite.setTexture(resources->fish1);
		sharkSprite.setTexture(resources->shark1);
	}
	else
	{
		fishSprite.setTexture(resources->fish2);
		sharkSprite.setTexture(resources->shark2);
	}
	lastFrame = *millisTimer;
	animationCounter++;
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
			fishSprite.setRotation(57 * CalculateAngle((*organisms)[i]->GetDirection()));
			fishSprite.setPosition((*organisms)[i]->GetPosition());
			window->draw(fishSprite);
		} 
		else if ((*organisms)[i]->GetType() == OrganismTypes::SHARK)
		{
			sharkSprite.setRotation(57 * CalculateAngle((*organisms)[i]->GetDirection()));
			sharkSprite.setPosition((*organisms)[i]->GetPosition());
			window->draw(sharkSprite);
		}
	}

}

float Visualizer::CalculateAngle(sf::Vector2f dir)
{
	float angle1 = acos(dir.x);
	float angle2 = asin(dir.y);
	if (dir.y >= 0)
		return angle1;
	else if (dir.x > 0)
		return angle2;
	else
		return 3 * 3.14 - angle2;
}
