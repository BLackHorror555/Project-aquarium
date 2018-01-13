#pragma once
#include <SFML\Graphics.hpp>


class Visualizer
{
	sf::Texture background;
	sf::RenderWindow* window;
public:

	
	Visualizer(int width, int height, std::string background);
	~Visualizer();

	void Draw()
};

