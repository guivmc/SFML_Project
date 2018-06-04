#pragma once
#include "State.h"
#include "Assets.h"
#include "EntityManager.h"

class LevelState : public State
{
protected:
	EntityManager entityManager;
};