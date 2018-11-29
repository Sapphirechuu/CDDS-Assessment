#pragma once
#include "gamestate.h"


class menustate : public gamestate
{
	bool readyForNext;
	GameStates nextState;

public:
	float width = (float)GetScreenWidth()/4;
	float height = 60;
	Rectangle gameButton{(float)GetScreenWidth()/2 - width/2, (float)GetScreenHeight()/2 - 100 - height/2, width, height };
	Rectangle scoreButton{ (float)GetScreenWidth() / 2 - width/2, (float)GetScreenHeight() / 2 - height/2, width, height };
	Rectangle exitButton{ (float)GetScreenWidth() / 2 - width/2, (float)GetScreenHeight() / 2 + 100 - height/2, width, height };
	menustate()
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
		
		if (GetMousePosition().x >= scoreButton.x && GetMousePosition().x <= scoreButton.x + width && GetMousePosition().y >= scoreButton.y && GetMousePosition().y <= scoreButton.y + height)
		{
			readyForNext = IsMouseButtonDown(0) || readyForNext;
			nextState = END;
		}

		if (GetMousePosition().x >= exitButton.x && GetMousePosition().x <= exitButton.x + width && GetMousePosition().y >= exitButton.y && GetMousePosition().y <= exitButton.y + height)
		{
			readyForNext = IsMouseButtonDown(0) || readyForNext;
			nextState = NONE;
		}
	}

	virtual void draw()
	{
		const int fontSize = 35;

		/*int xPos = GetScreenWidth() / 2 - MeasureText("Menu", fontSize) / 2;
		int yPos = GetScreenHeight() / 2 - fontSize / 2;
		DrawText("Menu", xPos, yPos, fontSize, DARKBLUE);*/
		DrawRectangleRec(gameButton, BLUE);
		DrawRectangleRec(scoreButton, BLUE);
		DrawRectangleRec(exitButton, BLUE);
		DrawText("Start Game", gameButton.x + width/2 - MeasureText("Start Game", fontSize)/2, gameButton.y + height/2 - fontSize/2, fontSize, WHITE);
		DrawText("Scores", scoreButton.x + width / 2 - MeasureText("Scores", fontSize) / 2, scoreButton.y + height / 2 - fontSize / 2, fontSize, WHITE);
		DrawText("Exit", exitButton.x + width / 2 - MeasureText("Exit", fontSize) / 2, exitButton.y + height / 2 - fontSize / 2, fontSize, WHITE);
	}

	virtual GameStates next()
	{
		if (readyForNext) { return nextState; }
		else { return GameStates::MENU; }
	}
};
