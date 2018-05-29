#pragma once
#include "State.h"
#include "Assets.h"
#include "EntityManager.h"

class LevelState : public State
{
private:

	EntityManager em;

public:
	/*LevelState();
	~LevelState();*/
	void draw(sf::RenderWindow &gameWindow);
	void update();
	void input();
};