#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include "Bioparametres.h"

class Organism
{
protected:
	Bioparametres* bioparametres;
	sf::Vector2i aquariumSize;
	int age;
	int index; //индекс в векторе аквариума
	sf::Vector2f position;
	sf::Vector2f direction;
	float* timeScale; //общая скорость работы программы (все скорости передвижений домножать на это)
	//float moveAngle;

public:
	Organism(Bioparametres* bioparametres_, sf::Vector2i aquariumSize_, int index_, float* timeScale_);

	void SetIndex(int index_);
	void SetParametres(Bioparametres* bioparametres_);
	void SetAquariumSize(sf::Vector2i aquariumSize_);
	sf::Vector2f GetDirection();
	sf::Vector2f GetPosition();

	virtual void Death() = 0;
	virtual void Reproduction() = 0;
	virtual void Move() = 0; 
	virtual void Update() = 0;
};
