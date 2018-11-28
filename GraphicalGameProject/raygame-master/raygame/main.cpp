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
#include "splashstate.h"

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

	gamestate * stateInstance = new splashstate();
	GameStates currentState = SPLASH;



	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		stateInstance->tick(GetFrameTime());
		GameStates nextState = stateInstance->next();
		if (nextState != currentState)
		{
			delete stateInstance;

			setupGameState(stateInstance, nextState);
			currentState = nextState;
			continue;
		}
		//stateInstance->update();
		// Draw
		BeginDrawing();

		ClearBackground(BLACK);

		stateInstance->draw();
		// Draw Walls


		// End Drawing
		EndDrawing();
	}

	// De-Initialization
	CloseWindow();        // Close window

	return 0;
}