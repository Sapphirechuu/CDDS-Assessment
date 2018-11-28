#pragma once
#include <string>
#include "player.h"
#include "ball.h"
#include "pickups.h"
#include "bots.h"
#include "raylib.h"


class pongstate : public gamestate
{

	bool clicked;
	// Initialize Pickups
public:

	int screenWidth = GetScreenWidth();
	int screenHeight = GetScreenHeight();


	// Initialize Walls
	Rectangle topWall{ 0, 0, (float)screenWidth, 5 };
	Rectangle bottomWall{ 0, (float)screenHeight - 5, (float)screenWidth, 5 };
	Rectangle leftWall{ 0,0, 5, (float)screenHeight };
	Rectangle rightWall{ (float)screenWidth - 5, 0, 5, (float)screenHeight };


	// Initialize players and player Rectangles (user)
	player players[4]
	{
		{ { 25, ((float)screenHeight / 2), 20.0f, 80.0f }, true, false, 1, GREEN },
	{ { (float)screenWidth / 2.0f, 25, 80.0f, 20.0f }, false, true, 2, RED },
	{ { (float)screenWidth - 40.0f, (float)screenHeight / 2.0f, 20.0f, 80.0f }, false, false, 3, BLUE },
	{ { (float)screenWidth / 2.0f, (float)screenHeight - 40.0f, 80.0f, 20.0f }, false, true, 4, YELLOW }
	};

	// Initialize Game ball
	ball ball{ { (float)screenWidth / 2, (float)screenHeight / 2 }, 15.0f, 100.0f, 90.0f };

	
	std::string playerScore = "Player 1 : " + std::to_string(players[0].score);
	std::string botAScore = "Player 2 : " + std::to_string(players[1].score);
	std::string botBScore = "Player 3 : " + std::to_string(players[2].score);
	std::string botCScore = "Player 4 : " + std::to_string(players[3].score);

	float posax = rand() % screenWidth;
	float posay = rand() % screenHeight;
	float posbx = rand() % screenWidth;
	float posby = rand() % screenHeight;
	float poscx = rand() % screenWidth;
	float poscy = rand() % screenHeight;
	float posdx = rand() % screenWidth;
	float posdy = rand() % screenHeight;
	float posex = rand() % screenWidth;
	float posey = rand() % screenHeight;
	pickup pickups[5] =
	{
	{ { posax, posay }, 8.0f, 1 },
	{ { posbx, posby }, 8.0f, 1 },
	{ { poscx, poscy }, 8.0f, 1 },
	{ { posdx, posdy }, 8.0f, 1 },
	{ { posex, posey }, 8.0f, 1 }
	};

	pongstate()
	{
		clicked = false;
	}

	virtual void tick(float deltaTime)
	{
		pickups->checkSpace(pickups);
		for (size_t i = 0; i < 4; i++)
		{
			paddleMovement(deltaTime, players, ball);
			ball.paddleUpdate(deltaTime, players[i]);
		}
		pickups->pickupUpdate(pickups, players, ball);
		ball.wallUpdate(topWall, bottomWall, leftWall, rightWall, players);
		//ball.paddleMovement(GetFrameTime(), botA, botB, botC);

		playerScore = "Player 1 : " + std::to_string(players[0].score);
		botAScore = "Player 2 : " + std::to_string(players[1].score);
		botBScore = "Player 3 : " + std::to_string(players[2].score);
		botCScore = "Player 4 : " + std::to_string(players[3].score);
	}

	virtual void draw()
	{
		const int fontSize = 32;

		if (!clicked)
		{
			DrawRectangleRec(topWall, PINK);
			DrawRectangleRec(bottomWall, PINK);
			DrawRectangleRec(leftWall, PINK);
			DrawRectangleRec(rightWall, PINK);

			// Draw Pickups
			for (size_t i = 0; i < 5; i++)
			{
				pickups[i].draw();
			}

			// Draw Game Objects
			for (size_t i = 0; i < 4; i++)
			{
				players[i].draw();
			}
			ball.draw();

			// Draw Text
			DrawText(playerScore.c_str(), 5, 5, 25, players[0].recColor);
			DrawText(botAScore.c_str(), screenWidth - MeasureText(botAScore.c_str(), 25) - 5, 5, 25, players[1].recColor);
			DrawText(botBScore.c_str(), 5, screenHeight - 35, 25, players[2].recColor);
			DrawText(botCScore.c_str(), screenWidth - MeasureText(botCScore.c_str(), 25) - 5, screenHeight - 35, 25, players[3].recColor);
		}
		else
		{
			
		}

		clicked = IsMouseButtonPressed(1) || clicked;
	}

	virtual GameStates next()
	{
		if (clicked) { return GameStates::END; }
		else { return GameStates::PONG; }
	}
};