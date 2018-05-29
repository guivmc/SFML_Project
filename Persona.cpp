#include "stdafx.h"
#include "Persona.h"

Persona::Persona() {}

Persona::~Persona() {}

Persona::Persona(int x, int y, float hp, sf::Texture &texture) : Entity(x, y)
{
	this->hp = hp;
	sprite.setTexture(texture);
}

//Methods
bool Persona::isDead()
{
	if (hp > 0) return false;
	return true;
}

void Persona::drawPersona(sf::RenderWindow &gameWindow)
{
	gameWindow.draw(sprite);
}

void Persona::draw(sf::RenderWindow &gameWindow)
{
	drawPersona(gameWindow);
}

void Persona::updatePersona()
{

}

void Persona::update()
{
	updatePersona();
}