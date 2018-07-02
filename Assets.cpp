#include "stdafx.h"
#include "Assets.h"
//Methods
void Assets::loadTexture(const std::string &keyName, const std::string &fileName)
{
	sf::Texture tex;
	if (tex.loadFromFile(fileName))
	{
		textureMap[keyName] = tex;
	}
}

void Assets::unloadAll()
{
	textureMap.clear();
}

bool Assets::isTextureLoaded(const std::string &keyName)
{
	if (textureMap.count(keyName) > 0) return true;
	else return false;
}

//Getters
sf::Texture &Assets::getTexture(const std::string &keyName)
{
	return textureMap.at(keyName);
}
