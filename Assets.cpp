#include "stdafx.h"
#include "Assets.h"
//Methods
void Assets::loadTexture(const std::string &name, const std::string &fileName)
{
	sf::Texture tex;
	if (tex.loadFromFile(fileName))
	{
		textureMap[name] = tex;
	}
}

//Getters
sf::Texture &Assets::getTexture(const std::string &name)
{
	return textureMap.at(name);
}
