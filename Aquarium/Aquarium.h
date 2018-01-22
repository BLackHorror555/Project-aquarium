#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include "Plankton.h"
#include "Fish.h"
#include "Shark.h"
#include "Organism.h"
#include "Bioparametres.h"

class Aquarium
{
	sf::Vector2i size;
	std::vector<Organism*> organisms;

	Bioparametres* bioparametres;

	float* timeScale;

public:
	Aquarium();
	Aquarium(sf::Vector2i _size, Bioparametres* bioparametres_, float* timeScale_);
	~Aquarium();

	std::vector<Organism*>* GetOrganisms();

	sf::Vector2i GetSize();

	void UpdateAnimals();  // ����������� �����������, � ���������� ������ FindFood(), Eat(), � ��
	void MoveAnimals();    // ��� ��������� ������������� � ������������ � ���������� � ��� ������������
};
