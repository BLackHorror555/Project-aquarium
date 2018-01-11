#ifndef ORGANISM_H
#define ORGANISM_H
#include <SFML\Graphics.hpp>
class Organism
{
	int age;
	sf::Vector2f position;
public:
	Organism();
	~Organism();

	virtual void Death();
	virtual void Reproduction();
	virtual void Move();
	virtual void Update();
};
#endif
