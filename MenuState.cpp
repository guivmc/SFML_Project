#include "stdafx.h"
#include "MenuState.h"

MenuState::MenuState(){}
MenuState::~MenuState(){}

MenuState::MenuState(int width, StateHandler &state) : l1()
{
		sfFont.loadFromFile("res/fonts/square-deal.ttf");
		sfText[0].setString(texts[0]);
		sfText[0].setPosition((float) (width / 2 - 100), 100);
		sfText[0].setFont(sfFont);

		sfText[1].setString(texts[1]);
		sfText[1].setPosition((float)(width / 2 - 100), 150);
		sfText[1].setFont(sfFont);

		st = &state;
}

void MenuState::draw(sf::RenderWindow &gameWindow)
{
	gameWindow.draw(sfText[0]);
	gameWindow.draw(sfText[1]);
}

void MenuState::update()
{
	input();
}

void MenuState::input()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		st->changeState(&l1);
	}
}