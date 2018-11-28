#pragma once
#include "gamestate.h"

#include <cmath>

class splashstate : public gamestate
{
	float duration;
	float timeLimit;

public:
	splashstate()
	{
		duration = 0.0f;
		timeLimit = 3.0f;
	}

	virtual void tick(float deltaTime)
	{
		duration += deltaTime;
	}

	virtual void draw()
	{
		const int fontSize = 40;

		int xPos = GetScreenWidth() / 2 - MeasureText("Sapphire Games", fontSize) / 2;
		int yPos = GetScreenHeight() / 2 - fontSize / 2;
		DrawText("Sapphire Games", xPos, yPos, fontSize, DARKBLUE);
	}

	virtual GameStates next()
	{
		if (duration >= timeLimit) { return GameStates::MENU; }
		return GameStates::SPLASH;
	}
};