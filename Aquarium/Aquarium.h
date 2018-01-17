#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include "Plankton.h"
#include "Fish.h"
#include "Shark.h"

class Aquarium
{
	sf::Vector2i size;
	std::vector<Plankton*> plankton;
	std::vector<Fish*> fish;
	std::vector<Shark*> shark;

public:
	Aquarium();
	Aquarium(sf::Vector2i _size);
	~Aquarium();

	int GetPlanktonNumber();
	int GetFishNumber();
	int GetSharkNumber();

	std::vector<Plankton*>* GetPlanktons();
	std::vector<Fish*>* GetFishs();
	std::vector<Shark*>* GetSharks();

	void UpdateAnimals();  // ����������� �����������, � ���������� ������ FindFood(), Eat(), � ��
	void MoveAnimals();    // ��� ��������� ������������� � ������������ � ���������� � ��� ������������
};
