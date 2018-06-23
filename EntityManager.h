#pragma once
#include "Engine.h"
#include "Persona.h"
#include <vector>

class EntityManager
{
private:
	GameDataRef _data;
	std::vector<Persona> entities;
public:
	EntityManager(GameDataRef data);
   ~EntityManager(){}

    void addEntity(Persona e);
	void update();
	void draw();
};