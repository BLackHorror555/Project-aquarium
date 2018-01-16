#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include "Bioparametres.h"

class Organism
{
	Bioparametres* bioparametres;
	sf::Vector2i aquariumSize;
	int age;
	int index; //индекс в векторе аквариума
	sf::Vector2f direction;
	//float moveAngle;

public:
	Organism(Bioparametres* bioparametres_, sf::Vector2i aquariumSize_, int index);

	void SetIndex(int index_);
	void SetParametres(Bioparametres* bioparametres_);
	void SetAquariumSize(sf::Vector2i aquariumSize_);
	sf::Vector2f GetDirection();

	virtual void Death() = 0;
	virtual void Reproduction() = 0;
	virtual void Move() = 0; 
	virtual void Update() = 0;
};
