#pragma once
#include <stack>
#include "State.h"

class StateHandler
{
private:
	//states container
	std::stack<State*> states;
public:
	//handler logic
	void pushState(State* state);
	void popStateTop();
	void popAll();
	void changeState(State* state);
	//Getters
	State* getTopState();
	bool isStatesEmpty();

};