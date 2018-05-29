#pragma once
#include <SFML\Graphics.hpp>

class State
{
public:
	virtual void draw(sf::RenderWindow &gameWindow) = 0;
	virtual void update() = 0;
	virtual void input() = 0;
};

