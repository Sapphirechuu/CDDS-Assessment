#pragma once
#include "gamestate.h"

#include <cmath>

class splashstate : public gamestate
{
	float duration;
	float timeLimit;

public:
	Font splashFont = LoadFont("barcade.ttf");
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
		const int fontSize = 60;

		float xPos = GetScreenWidth() / 2 - (MeasureTextEx(splashFont, "Sapphire Games", fontSize, 0).x)/2;
		float yPos = GetScreenHeight() / 2 - fontSize / 2;
		//DrawText("Sapphire Games", xPos, yPos, fontSize, DARKBLUE);
		DrawTextEx(splashFont, "Sapphire Games", { xPos, yPos }, fontSize, 0, DARKBLUE);
	}

	virtual GameStates next()
	{
		if (duration >= timeLimit) { return GameStates::MENU; }
		return GameStates::SPLASH;
	}
};