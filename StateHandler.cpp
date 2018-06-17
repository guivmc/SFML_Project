#include "stdafx.h"
#include "StateHandler.h"

void StateHandler::addState(StateRef newState, bool isReplacingTop)
{
	this->_isAdding = true;
	this->_isReplacingTop = isReplacingTop;

	this->_newState = std::move(newState);
}

void StateHandler::removeState()
{
	this->_isRemoving = true;
}

void StateHandler::processStateChanges()
{
	//If we were to remove
	if (this->_isRemoving && !this->_states.empty())
	{
		this->_states.pop();

		if (!this->_states.empty())
		{
			//Put the top state to run
			this->_states.top()->resume();
		}

		this->_isRemoving = false;
	}

	//If we were to add
	if (this->_isAdding)
	{
		if (!this->_states.empty())
		{
			//Replace for a new one
			if (this->_isReplacingTop)
			{
				this->_states.pop();
			}
			else
			{
				//Pause top as it will no longer be on top
				this->_states.top()->pause();
			}
		}
		//Add state to pile
		this->_states.push(std::move(this->_newState));
		//Init the added state
		this->_states.top()->init();
		this->_isAdding = false;
	}
}

StateRef &StateHandler::getActiveState()
{
	return this->_states.top();
}