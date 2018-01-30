#pragma once
#include "Resources.h"
#include "SFML\Graphics.hpp"
#include "SFML\Audio\Sound.hpp"

class Effects
{
	int* millisTimer;
	sf::Sprite bubble;
	sf::Sprite noise;
	int bubbleNumber;

public:
	Effects(sf::Texture bubble_, sf::Texture noise_, int* millisTimer_);
	~Effects();
};

