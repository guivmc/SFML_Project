#include "stdafx.h"
#include "Engine.h"
#include "MenuState.h"

Engine::Engine(int screenWidth, int screenHeight, std::string title) 
{
	this->screenWidth = screenWidth;
	this->screenHeight = screenHeight;							//Window with title and close buttons
	_data->_window.create(sf::VideoMode(screenWidth, screenHeight), title, 
						  sf::Style::Titlebar + sf::Style::Close);
}

//Methods
void Engine::createMenu()
{
	_data->_stateMachine.addState(StateRef(new MenuState(this->_data)), false);
}

void Engine::drawEngine(float dt)
{
	this->_data->_window.clear(sf::Color::Black);

	this->_data->_stateMachine.getActiveState()->draw(dt);

	this->_data->_window.display();
}

void Engine::handleInputEngine()
{
	sf::Event event;

	while (this->_data->_window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			this->_data->_window.close();
		}

		this->_data->_stateMachine.getActiveState()->input();
	}
}

void Engine::run()
{
	float newTime, frameTime, interpolation, accumulator = 0, 
		  currentTime = this->_clock.getElapsedTime().asSeconds();
																			
	createMenu();

	while (this->_data->_window.isOpen())
	{
		this->_data->_stateMachine.processStateChanges();
		
		newTime = this->_clock.getElapsedTime().asSeconds();
		//Frame diference 
		frameTime = newTime - currentTime;
		if (frameTime > 0.25f) frameTime = 0.25f;
		currentTime = newTime;
		accumulator += frameTime;
		//update with frame
		while (accumulator >= dt)
		{
			handleInputEngine();
			this->_data->_stateMachine.getActiveState()->update(dt);
			accumulator -= dt;
		}
		interpolation = accumulator / dt;
		drawEngine(interpolation);
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