#include "stdafx.h"
#include "StateHandler.h"

//Methods
void StateHandler::pushState(State* state)
{
	//add element
	states.push(state);
}

void StateHandler::popStateTop()
{
	//Make the memory liberate the space memory where this is located, 
										//to allow new data to be stored at that same space.
	delete states.top();
	//remove top element
	states.pop();
}

void StateHandler::popAll()
{
	while (!states.empty()) states.pop();
}

void StateHandler::changeState(State* state)
{
	if (!states.empty()) states.pop();;
	states.push(state);
}

//Getters
State* StateHandler::getTopState()
{
						//null pointer
	if (states.empty()) return nullptr;
	return states.top();
}

bool StateHandler::isStatesEmpty()
{
	return states.empty();
}