#pragma once
#include "Resources.h"
#include "SFML\Graphics.hpp"
#include "SFML\Audio\Sound.hpp"

class Effects
{
	int fps = 50;
	int lastFrame = 0;
	int* millisTimer;
	sf::Sprite bubble;
	sf::Sprite noise;
	int bubbleNumber;
	sf::RenderWindow* window;
	Resources* res;

	int noiseSpeed = 1;
	int currNoiseOffset = 0;
	
	sf::Vector2i bubblesFreq; //каждые Х миллисекунд (случайно в диапазоне)
	int nextBubble = 0;
	int bubblesSpeed = 1;
	int bubbleLifeTime = 5; //в секундах
	std::vector<sf::Vector3f> bubbles;

	void MoveNoise();

public:
	Effects();
	Effects(int* millisTimer_, sf::RenderWindow* window, Resources* res_);
	~Effects();
	void Start();
	void Update();
	
};

