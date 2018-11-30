#pragma once
#include "gamestate.h"
#include <filesystem>
#include <iostream>
#include <fstream>

class endstate : public gamestate
{
	bool readyForNext;
	GameStates nextState;

public:
	float width = (float)GetScreenWidth() / 4;
	float height = 60;
	bool scoreAdded = false;
	Rectangle gameButton{ (float)GetScreenWidth() / 2 - 250 - width / 2, (float)GetScreenHeight() / 2 + 300 - height / 2, width, height };
	Rectangle menuButton{ (float)GetScreenWidth() / 2 - width / 2, (float)GetScreenHeight() / 2 + 300 - height / 2, width, height };
	Rectangle exitButton{ (float)GetScreenWidth() / 2 + 250 - width / 2, (float)GetScreenHeight() / 2 + 300 - height / 2, width, height };

	Texture2D butterfly[6];
	int currentFrame = 0;
	float timer = 0;
	bool texturesLoaded = false;

	

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
			nextState = NONE;
		}

		if (!texturesLoaded)
		{
			butterfly[0] = LoadTexture("Textures/Butterfly-1.png");
			butterfly[1] = LoadTexture("Textures/Butterfly-2.png");
			butterfly[2] = LoadTexture("Textures/Butterfly-3.png");
			butterfly[3] = LoadTexture("Textures/Butterfly-4.png");
			butterfly[4] = LoadTexture("Textures/Butterfly-5.png");
			butterfly[5] = LoadTexture("Textures/Butterfly-6.png");
			texturesLoaded = true;
		}

		timer += deltaTime;
		if (timer > 0.2f)
		{
			currentFrame++;
			timer = 0.0f;
			if (currentFrame == 6)
			{
				currentFrame = 0;
			}
		}

		//Leaderboard stuff that is under maintenance
		/*std::fstream file;
		file.open("Highscores.bin", std::ios_base::in | std::ios::binary);
		if (!file.is_open()) {
			std::cout << "Failed." << std::endl;
		}
		int good = 0;
		while (good = !10)
		{
			int temp;
			good = 0;
			for (int i = 0; i < 10; ++i)
			{
				if(leaderboard[i])
			}
		}
		DrawText(buffer.c_str(), GetScreenWidth() / 2, GetScreenHeight() / 2, 30, SKYBLUE);*/
	}

	virtual void draw()
	{
		const int fontSize = 35;

		DrawTexture(butterfly[currentFrame], GetScreenWidth()/2 - butterfly[currentFrame].width/2, GetScreenHeight()/2 - butterfly[currentFrame].height/2, WHITE);
		DrawRectangleRec(gameButton, BLUE);
		DrawRectangleRec(menuButton, BLUE);
		DrawRectangleRec(exitButton, BLUE);
		DrawText("Start Game", gameButton.x + width / 2 - MeasureText("Start Game", fontSize) / 2, gameButton.y + height / 2 - fontSize / 2, fontSize, WHITE);
		DrawText("Menu", menuButton.x + width / 2 - MeasureText("Menu", fontSize) / 2, menuButton.y + height / 2 - fontSize / 2, fontSize, WHITE);
		DrawText("Exit", exitButton.x + width / 2 - MeasureText("Exit", fontSize) / 2, exitButton.y + height / 2 - fontSize / 2, fontSize, WHITE);
		DrawText("The score menu is currently under maintenance. Thank you for you patience.", GetScreenWidth() / 2 - MeasureText("The score menu is currently under maintenance. Thank you for you patience.", 18) / 2 , (GetScreenHeight() / 2) - (fontSize / 2 ) + 90, 18, RED);
		
	}

	virtual GameStates next()
	{
		if (readyForNext) { return nextState; }
		else { return GameStates::END; }
	}
};