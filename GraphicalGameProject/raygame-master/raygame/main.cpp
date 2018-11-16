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

#include <iostream>
#include <ctime>
#include <string>

int main()
{
	srand(time(NULL));
	// Initialization
	int screenWidth = 800;
	int screenHeight = 800;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);

	// Initialize Walls
	Rectangle topWall{ 0, 0, screenWidth, 5 };
	Rectangle bottomWall{ 0, screenHeight - 5, screenWidth, 5 };
	Rectangle leftWall{ 0,0, 5, screenHeight };
	Rectangle rightWall{ screenWidth - 5, 0, 5, screenHeight };

	
	// Initialize players and player Rectangles (user)
	player player1;
	player1.isPlayer = true;
	player1.rec = { 25, ((float)screenHeight / 2), 20.0f, 80.0f };
	player1.recColor = GREEN;

	player botA;
	botA.isPlayer = false;
	botA.rec = { (float)screenWidth - 40.0f, (float)screenHeight / 2.0f, 20.0f, 80.0f};
	botA.recColor = RED;

	player botB;
	botB.isPlayer = false;
	botB.rec = { (float)screenWidth / 2.0f, (float)screenHeight - 40.0f, 80.0f, 20.0f };
	botB.recColor = BLUE;

	player botC;
	botC.isPlayer = false;
	botC.rec = { (float)screenWidth / 2.0f, 25, 80.0f, 20.0f };
	botC.recColor = YELLOW;

	// Initialize Game ball
	ball ball {	{ (float)screenWidth / 2, (float)screenHeight / 2 }, 15.f, 300.0f, 30.0f	};

	// Initialize Pickups
	pickup pickups[5] =
	{
		{ { rand() % screenWidth, rand() % screenHeight }, 8.0f, 1 },
	{ { rand() % screenWidth, rand() % screenHeight }, 8.0f, 1 },
	{ { rand() % screenWidth, rand() % screenHeight }, 8.0f, 1 },
	{ { rand() % screenWidth, rand() % screenHeight }, 8.0f, 1 },
	{ { rand() % screenWidth, rand() % screenHeight }, 8.0f, 1 }
	};

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		player1.update(GetFrameTime());
		ball.paddleUpdate(GetFrameTime(), player1.rec, botA.rec, botB.rec, botC.rec);
		ball.pickupUpdate(pickups, screenHeight, screenWidth, player1, botA, botB, botC);
		ball.wallUpdate(topWall, bottomWall, leftWall, rightWall, screenHeight, screenWidth, player1, botA, botB, botC);
		

		// Draw
		BeginDrawing();

		ClearBackground(BLACK);

		// Draw Walls
		DrawRectangleRec(topWall, PINK);
		DrawRectangleRec(bottomWall, PINK);
		DrawRectangleRec(leftWall, PINK);
		DrawRectangleRec(rightWall, PINK);

		// Draw Objects
		for (size_t i = 0; i < 5; i++)
		{
			pickups[i].draw();
		}
		player1.draw();
		botA.draw();
		botB.draw();
		botC.draw();

		ball.draw();

		DrawText(std::to_string(player1.score).c_str(), 5, 5, 25, GREEN);
		DrawText(std::to_string(botA.score).c_str(), 35, 5, 25, RED);
		DrawText(std::to_string(botB.score).c_str(), 60, 5, 25, BLUE);
		DrawText(std::to_string(botC.score).c_str(), 85, 5, 25, YELLOW);

		// End Drawing
		EndDrawing();
	}

	// De-Initialization
	CloseWindow();        // Close window

	return 0;
}