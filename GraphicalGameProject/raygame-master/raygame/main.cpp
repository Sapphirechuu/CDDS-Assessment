/*******************************************************************************************
*
*   raylib [core] example - basic window
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "player.h"
#include "ball.h"
#include "pickups.h"
#include "bots.h"

#include <iostream>
#include <ctime>
#include <string>

int main()
{
	srand(time(NULL));
	// Initialization
	int screenWidth = 800;
	int screenHeight = 800;

	InitWindow(screenWidth, screenHeight, "A-Pong");

	SetTargetFPS(60);

	// Initialize Walls
	Rectangle topWall{ 0, 0, screenWidth, 5 };
	Rectangle bottomWall{ 0, screenHeight - 5, screenWidth, 5 };
	Rectangle leftWall{ 0,0, 5, screenHeight };
	Rectangle rightWall{ screenWidth - 5, 0, 5, screenHeight };

	
	// Initialize players and player Rectangles (user)
	player players[4]
	{
		{ { 25, ((float)screenHeight / 2), 20.0f, 80.0f }, true, false, 1, GREEN},
		{ { (float)screenWidth / 2.0f, (float)screenHeight - 40.0f, 80.0f, 20.0f }, false, true, 2, RED},
		{ { (float)screenWidth - 40.0f, (float)screenHeight / 2.0f, 20.0f, 80.0f }, false, false, 3, BLUE},
		{ { (float)screenWidth / 2.0f, 25, 80.0f, 20.0f }, false, true, 4, YELLOW}
	};

	// Initialize Game ball
	ball ball {	{ (float)screenWidth / 2, (float)screenHeight / 2 }, 15.0f, 100.0f, 90.0f};

	// Initialize Pickups
	pickup pickups[5] =
	{
	{ { rand() % screenWidth, rand() % screenHeight }, 8.0f, 1 },
	{ { rand() % screenWidth, rand() % screenHeight }, 8.0f, 1 },
	{ { rand() % screenWidth, rand() % screenHeight }, 8.0f, 1 },
	{ { rand() % screenWidth, rand() % screenHeight }, 8.0f, 1 },
	{ { rand() % screenWidth, rand() % screenHeight }, 8.0f, 1 }
	};
	pickups->checkSpace(pickups);

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		for (size_t i = 0; i < 4; i++)
		{
			paddleMovement(GetFrameTime(), players, ball);
			ball.paddleUpdate(GetFrameTime(), players[i]);
		}
		pickups->pickupUpdate(pickups, players, ball);
		ball.wallUpdate(topWall, bottomWall, leftWall, rightWall, players);
		//ball.paddleMovement(GetFrameTime(), botA, botB, botC);
		
		std::string playerScore = "Player 1 : " + std::to_string(players[0].score);
		std::string botAScore = "Player 2 : " + std::to_string(players[1].score);
		std::string botBScore = "Player 3 : " + std::to_string(players[2].score);
		std::string botCScore = "Player 4 : " + std::to_string(players[3].score);
		// Draw
		BeginDrawing();

		ClearBackground(BLACK);

		// Draw Walls
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
		DrawText(botAScore.c_str(), screenWidth - MeasureText(botAScore.c_str(), 25), 5, 25, players[1].recColor);
		DrawText(botBScore.c_str(), 5, screenHeight - 35, 25, players[2].recColor);
		DrawText(botCScore.c_str(), screenWidth - 150, screenHeight - 35, 25, players[3].recColor);

		// End Drawing
		EndDrawing();
	}

	// De-Initialization
	CloseWindow();        // Close window

	return 0;
}