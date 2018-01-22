#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include "Bioparametres.h"

enum OrganismTypes {
	PLANKTON = 0,
	FISH = 1,
	SHARK = 2
};

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
	float moveAngle;
	std::vector<Organism*>* organisms;

public:
	Organism(Bioparametres* bioparametres_, sf::Vector2i aquariumSize_, int index_, float* timeScale_, sf::Vector2f position_);
	
	void SetIndex(int index_);
	void SetParametres(Bioparametres* bioparametres_);
	void SetAquariumSize(sf::Vector2i aquariumSize_);
	sf::Vector2i GetAquariumSize();
	sf::Vector2f GetDirection();
	sf::Vector2f GetPosition();

	Bioparametres* GetParametres();

	void SetPosition(sf::Vector2f position_);

	virtual void Death() = 0;
	virtual void Reproduction() = 0;
	virtual void Update() = 0;
	virtual OrganismTypes GetType() = 0; //возвращает тип огранизма
};
