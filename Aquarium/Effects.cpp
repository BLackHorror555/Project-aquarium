#include "Effects.h"



Effects::Effects()
{
}

Effects::Effects(int* millisTimer_, sf::RenderWindow* window_, Resources* res_)
{
	res = res_;
	bubble.setTexture(res->bubble);
	res->noise.setRepeated(true);
	noise.setTexture(res->noise);
	millisTimer = millisTimer_;
	noise.setPosition(0, 0);
	window = window_;
	bubblesFreq = sf::Vector2i(1500, 3000);
}

Effects::~Effects()
{

}

void Effects::Start()
{

}

void Effects::Update()
{
	//window->draw(bubble);
	//шум
	if (*millisTimer - lastFrame >= 1.0 / 60 * 1000) {
		currNoiseOffset += noiseSpeed;
		noise.setTextureRect(sf::IntRect(currNoiseOffset, 0, res->noise.getSize().x, res->noise.getSize().x));
		lastFrame = *millisTimer;
	}
	window->draw(noise);
	
	// пузыри
	if (*millisTimer > nextBubble) // время пустить пузырь
	{
		// расчитываем время для следущего пузыря
		nextBubble = *millisTimer + 1000 * rand() % (bubblesFreq.y - bubblesFreq.x) + bubblesFreq.x;
		// пускаем новый
		sf::Vector3f bbl = sf::Vector3f(rand() % 1280, 720, *millisTimer);
		bubbles.push_back(bbl);
	}
	//обновляем все пузыри
	for (int i = 0; i < bubbles.size(); i++)
	{
		if (*millisTimer - bubbles[i].z > bubbleLifeTime * 1000)
		{
			bubbles.erase(bubbles.begin() + i);
		}
		else
		{
			bubbles[i] += sf::Vector3f(0, -bubblesSpeed, 0);
			bubble.setPosition(bubbles[i].x, bubbles[i].y);
			window->draw(bubble);
			//window->draw(bubble);
		}	
	}
}