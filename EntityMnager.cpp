#include "stdafx.h"
#include "EntityManager.h"

EntityManager::EntityManager() : player(70, 70, 4)
{
	assets.loadTexture("Chars", "res/textures/Chars.png");
	player.setSprite(assets.getTexture("Chars"));
}

EntityManager::~EntityManager(){}

void EntityManager::draw(sf::RenderWindow &gameWindow)
{
	player.draw(gameWindow);
}

void EntityManager::update()
{
	player.update();
}