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

	void loadTexture(const std::string &name, const std::string &fileName);

	sf::Texture &getTexture(const std::string &name);
};