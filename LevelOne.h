#pragma once
#include "LevelState.h"

class LevelOne : public LevelState
{

public:
	LevelOne();
	~LevelOne();

	void draw(sf::RenderWindow &gameWindow);
	void update();
	void input();
};

