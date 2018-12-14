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
#include "tVector.h"
#include "tQueue.h"
#include "tStack.h"
#include "tObjectPool.h"
#include "tLinkedList.h"
#include <iostream>

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 800;
	int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);
	tVector<int> bottomlessNums;
	bottomlessNums.push_back(5);
	bottomlessNums.push_back(10);
	bottomlessNums.push_back(15);
	bottomlessNums.push_back(20);

	bottomlessNums.pop_back();

	bottomlessNums.push_back(25);

	for (size_t i = 0; i < bottomlessNums.size(); ++i)
	{
		std::cout << bottomlessNums.at(i) << std::endl;
	}

	tForwardList<int> link;
	link.push_front(8);
	link.push_front(8);
	link.push_front(9);

	link.remove(7);
	link.display();

	std::cout << "dff" << std::endl;
	for (auto it = link.begin(); it != link.end(); ++it)
	{
		std::cout << (*it) << std::endl;
	}
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(RAYWHITE);

		DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}