#pragma once
#include "Entity.h"
#include <SFML\Graphics.hpp>

class Persona : public Entity
{
protected:
	//Logic
	sf::RectangleShape bounds;
	float speedX, speedY, hp;
	//Graphics
	sf::Sprite sprite;
	//For inheritance calls
	virtual void drawPersona(sf::RenderWindow &gameWindow);
	virtual void updatePersona();

public:
	Persona();
	~Persona();
	Persona(int x, int y, float hp, sf::Texture &texture);

	bool isDead();
	//Engine calls
	void draw(sf::RenderWindow &gameWindow);
	void update();
};