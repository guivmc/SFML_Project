#pragma once
#include <SFML\Graphics.hpp>
#include <unordered_map>

class Assets
{
private:
	std::unordered_map<std::string, sf::Texture> textureMap;
public:
	Assets(){}
   ~Assets(){}

	void loadTexture(const std::string &keyName);
	void unloadAll();

	bool isTextureLoaded(const std::string &keyName);

	sf::Texture &getTexture(const std::string &keyName);
};