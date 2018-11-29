#pragma once
#include "raylib.h"
#include <iostream>

enum GameStates
{
	NONE,
	SPLASH,
	MENU,
	PONG,
	END
};

class gamestate
{
public:
	virtual void tick(float deltaTime) {};
	virtual void draw() {};
	virtual GameStates next() { return NONE; };
};

void setupGameState(gamestate *&ptr, GameStates newState);