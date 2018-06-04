#pragma once
#include <SFML\Graphics.hpp>
#include "StateHandler.h"

class Engine
{
private:

	//window
	sf::RenderWindow gameWindow;
	int screenWidth, screenHeight;

	//Logic
	void draw();
	void update();
	StateHandler stateHandler;

public:
	Engine();
	~Engine();
	Engine(int screenWidth, int screenHeight, std::string title);

	void run();


	//Getters
	int getScreenWidth();
	int getScreenHeight();
	StateHandler getStateHandler();

	//setters
	void setScreenWidth(int screenWidth);
	void setScreenHeight(int screenHeight);
};
