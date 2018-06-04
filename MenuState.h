#pragma once
#include "State.h"
#include "Engine.h"
#include "LevelOne.h"

class MenuState : public State
{
private:

	std::string texts[2] = { "Menu.", "Press Enter." };
	sf::Text sfText[2];
	sf::Font sfFont;

	LevelOne l1;

	StateHandler *st;

public:

	MenuState();
	MenuState(int width, StateHandler &state);
   ~MenuState();

	void draw(sf::RenderWindow &gameWindow);
	void update();
	void input();
};