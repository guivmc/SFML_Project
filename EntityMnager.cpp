#include "stdafx.h"
#include "EntityManager.h"

EntityManager::EntityManager(GameDataRef data) : _data(data)
{
}

void EntityManager::addEntity(Persona e)
{

}

void EntityManager::addEntity(int x, int y, float hp, const std::string &keyName)
{
	if (!_data->_assets.isTextureLoaded(keyName))
	{
		_data->_assets.loadTexture(keyName, "res/textures/"+ keyName +".png");
	}
	Persona *per = new Persona(x, y, hp, _data->_assets.getTexture(keyName));

	entities.push_back(per);
}

void EntityManager::clearAll()
{
	for (int i = 0; i < entities.size(); i++)
	{		
		delete entities.at(i);
	}
	entities.clear();
}

void EntityManager::draw()
{
	for (int i = 0; i < entities.size(); i++)
	{
		_data->_window.draw(entities.at(i)->getSprite());
	}
}

void EntityManager::update()
{
	for (int i = 0; i < entities.size(); i++)
	{
		if (entities.at(i)->isDead())
		{
			delete entities.at(i);
			entities.erase(entities.begin() + i);
		}
	}
}

