#include "stdafx.h"
#include "LevelState.h"

//LevelState::LevelState(){}
//
//LevelState::~LevelState() {}


void LevelState::draw(sf::RenderWindow &gameWindow)
{
	em.draw(gameWindow);
}

void LevelState::input()
{

}

void LevelState::update()
{
	em.update();
}