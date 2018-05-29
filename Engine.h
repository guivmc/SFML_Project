#pragma once
#include <SFML\Graphics.hpp>
#include "StateHandler.h"
#include "LevelState.h"
#include "Player.h"
#include "Assets.h"

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
	LevelState ls;

public:
	Engine();
	~Engine();
	Engine(int screenWidth, int screenHeight, std::string title);

	void run();

	

	//Getters
	int getScreenWidth();
	int getScreenHeight();

	//setters
	void setScreenWidth(int screenWidth);
	void setScreenHeight(int screenHeight);
};
