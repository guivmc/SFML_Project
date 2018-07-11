#pragma once
#include "Persona.h"

class Slime : public Persona
{
public:
	Slime(){}
   ~Slime(){}
    Slime(int x, int y, float hp, sf::Texture &texture);
	void update();
};