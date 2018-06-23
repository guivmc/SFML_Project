#include "stdafx.h"
#include "LevelOne.h"

LevelOne::LevelOne(GameDataRef data) : _data(data), entityManager(data)
{

}

void LevelOne::init()
{
	p = new Player(10, 10, 100);
	_data->_assets.loadTexture("Chars","res/textures/Chars.png");
	p->setSprite(_data->_assets.getTexture("Chars"));
}

void LevelOne::draw(float dt)
{
	_data->_window.draw(p->getSprite());
}

void LevelOne::update(float dt)
{
	
}

void LevelOne::input()
{

}