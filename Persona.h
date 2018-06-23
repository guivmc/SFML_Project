#pragma once
#include <SFML\Graphics.hpp>

class Persona 
{
protected:
	//Logic
	float speedX, speedY, hp;
	sf::RectangleShape bounds;

	//Graphics
	int x, y;
	sf::Sprite sprite;
public:
	Persona() {}
   ~Persona() {}
	Persona(int x, int y, float hp, sf::Texture &texture);

	bool isDead();
};