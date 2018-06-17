#pragma once
#include <SFML\Graphics.hpp>

class State
{
public:
	virtual void init() = 0;

	virtual void draw(float dt) = 0;
	virtual void update(float dt) = 0;
	virtual void input() = 0;

	virtual void pause() {}
	virtual void resume() {}
};