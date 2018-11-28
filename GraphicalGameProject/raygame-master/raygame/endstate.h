#pragma once
#include "gamestate.h"

class endstate : public gamestate
{
	bool readyForNext;
	GameStates nextState;

public:
	float width = (float)GetScreenWidth() / 4;
	float height = 60;
	Rectangle gameButton{ (float)GetScreenWidth() / 2 - 250 - width / 2, (float)GetScreenHeight() / 2 + 300 - height / 2, width, height };
	Rectangle menuButton{ (float)GetScreenWidth() / 2 - width / 2, (float)GetScreenHeight() / 2 + 300 - height / 2, width, height };
	Rectangle exitButton{ (float)GetScreenWidth() / 2 + 250 - width / 2, (float)GetScreenHeight() / 2 + 300 - height / 2, width, height };
	endstate()
	{
		readyForNext = false;
	}

	virtual void tick(float deltaTime)
	{
		if (GetMousePosition().x >= gameButton.x && GetMousePosition().x <= gameButton.x + width && GetMousePosition().y >= gameButton.y && GetMousePosition().y <= gameButton.y + height)
		{
			readyForNext = IsMouseButtonPressed(0) || readyForNext;
			nextState = PONG;
		}

		if (GetMousePosition().x >= menuButton.x && GetMousePosition().x <= menuButton.x + width && GetMousePosition().y >= menuButton.y && GetMousePosition().y <= menuButton.y + height)
		{
			readyForNext = IsMouseButtonDown(0) || readyForNext;
			nextState = MENU;
		}

		if (GetMousePosition().x >= exitButton.x && GetMousePosition().x <= exitButton.x + width && GetMousePosition().y >= exitButton.y && GetMousePosition().y <= exitButton.y + height)
		{
			readyForNext = IsMouseButtonDown(0) || readyForNext;
			nextState = SPLASH;
		}
	}

	virtual void draw()
	{
		const int fontSize = 35;

		DrawRectangleRec(gameButton, BLUE);
		DrawRectangleRec(menuButton, BLUE);
		DrawRectangleRec(exitButton, BLUE);
		DrawText("Start Game", gameButton.x + width / 2 - MeasureText("Start Game", fontSize) / 2, gameButton.y + height / 2 - fontSize / 2, fontSize, WHITE);
		DrawText("Menu", menuButton.x + width / 2 - MeasureText("Menu", fontSize) / 2, menuButton.y + height / 2 - fontSize / 2, fontSize, WHITE);
		DrawText("Exit", exitButton.x + width / 2 - MeasureText("Exit", fontSize) / 2, exitButton.y + height / 2 - fontSize / 2, fontSize, WHITE);
	}

	virtual GameStates next()
	{
		if (readyForNext) { return nextState; }
		else { return GameStates::END; }
	}
};