#pragma once
#include "State.h"
#include "Engine.h"
#include "Player.h"

class LevelOne : public State
{
private:
	GameDataRef _data;
	Player *p;
public:
	LevelOne(GameDataRef data);

	void init();

	void draw(float dt);
	void update(float dt);
	void input();
};

