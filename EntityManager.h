#pragma once
#include "Player.h"

#include "Assets.h"

class EntityManager
{
private:
	Player player;
	Assets assets;

public:
	EntityManager();
	~EntityManager();

	void update();
	void draw(sf::RenderWindow &gameWindow);
};