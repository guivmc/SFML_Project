#include "stdafx.h"
#include "Engine.h"

//Assets Engine::assets;

Engine::Engine() {}

Engine::~Engine()
{
	stateHandler.popAll();
}

Engine::Engine(int screenWidth, int screenHeight, std::string title) 
{
	this->screenWidth = screenWidth;
	this->screenHeight = screenHeight;							//Window with title and close buttons
	gameWindow.create(sf::VideoMode(screenWidth, screenHeight), title, sf::Style::Titlebar + sf::Style::Close);
	gameWindow.setFramerateLimit(60);

	stateHandler.pushState(&ls);
}

//Methods
void Engine::draw()
{
	gameWindow.clear();

	stateHandler.getTopState()->draw(gameWindow);

	gameWindow.display();
}

void Engine::update()
{
	stateHandler.getTopState()->update();
}

void Engine::run()
{
	while (gameWindow.isOpen())
	{
		sf::Event gameEvent;
		while (gameWindow.pollEvent(gameEvent))
		{
			if (gameEvent.type == sf::Event::Closed)
			{
				//stateHandler.popState();
				gameWindow.close();
			}
			if (gameEvent.type == sf::Event::KeyPressed) stateHandler.getTopState()->input();
		}

		update();
		draw();
	}
}

//Getters
int Engine::getScreenWidth()
{
	return screenWidth;
}

int Engine::getScreenHeight()
{
	return screenHeight;
}

//Setters
void Engine::setScreenWidth(int screenWidth)
{
	this->screenWidth = screenWidth;
}

void Engine::setScreenHeight(int screenHeight)
{
	this->screenHeight = screenHeight;
}
