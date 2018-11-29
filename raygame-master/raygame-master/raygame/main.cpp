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
#include "pickup.h"
#include "ball.h"
#include <iostream>
#include <string>

#include <ctime>

int fakemain();
void restart();
int main()
{
	fakemain();
	return 0;
}
int fakemain()
{
	srand(time(NULL));
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 800;
	int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "raylib Pong");

	SetTargetFPS(60);

	Rectangle topWall{ 0, 0, screenWidth, 5 };
	Rectangle bottomWall{ 0, screenHeight-5, screenWidth, 5 };
	Rectangle leftWall{ 0,0, 5, screenHeight };
	Rectangle rightWall{ screenWidth-5, 0, 5, screenHeight };
	/*ball player;
	player.pos = { 215, 215 };
	player.radius = 25.0f;
	player.speed = 100.0f;*/
	std::cout << screenHeight / 2 << std::endl;
	Rectangle playerRec{ 25, (screenHeight / 2), 20.0f, 80.0f, 400.0f};
	Rectangle player2Rec{ screenWidth - 40, screenHeight / 2, 20.0f, 80.0f, 400.0f };


	std::cout << playerRec.y << std::endl;
	ball ball
	{
		{ screenWidth/2, screenHeight/2 }, 15.f, 300.0f, 30.0f
	};
	pickup pickups[5] = 
	{
		{ { rand() % screenWidth, rand() % screenHeight }, 8.0f, 1},
		{ { rand() % screenWidth, rand() % screenHeight }, 8.0f, 1},
		{ { rand() % screenWidth, rand() % screenHeight }, 8.0f, 1},
		{ { rand() % screenWidth, rand() % screenHeight }, 8.0f, 1},
		{ { rand() % screenWidth, rand() % screenHeight }, 8.0f, 1}
	};
	
	//--------------------------------------------------------------------------------------
	int player1Score = 0;
	int player2Score = 0;

	float timer = 0.0f;
	//float timeLimit = 10.0f;
	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		timer += GetFrameTime();
		/*if (timer < timeLimit)
		{
			timer += GetFrameTime();

			player.update(GetFrameTime());*/

		if (timer <= 10)
		{
			if (IsKeyDown(KEY_W))
			{
				playerRec.y -= playerRec.speed * GetFrameTime();
			}
			if (IsKeyDown(KEY_S))
			{
				playerRec.y += playerRec.speed * GetFrameTime();
			}
			if (IsKeyDown(KEY_UP))
			{
				player2Rec.y -= player2Rec.speed * GetFrameTime();
			}
			if (IsKeyDown(KEY_DOWN))
			{
				player2Rec.y += player2Rec.speed * GetFrameTime();
			}
			ball.update(GetFrameTime());
			for (size_t i = 0; i < 5; i++)
			{
				if (CheckCollisionCircles(ball.pos, ball.radius, pickups[i].pos, pickups[i].radius))
				{
					if (ball.lastTouch == 1)
					{
						player1Score++;
						pickups[i].pos.x = rand() % screenWidth;
						pickups[i].pos.y = rand() % screenHeight;
					}
					else if (ball.lastTouch == 2)
					{
						player2Score++;
						pickups[i].pos.x = rand() % screenWidth;
						pickups[i].pos.y = rand() % screenHeight;
					}

				}
			}
			if (CheckCollisionCircleRec(ball.pos, ball.radius, playerRec))
			{
				//ball.pos.y += ball.speed * GetFrameTime() * (rand() % 100);
				ball.speed.x = (-ball.speed.x);
				ball.speed.y = (rand() % 400) + 300;
				if ((rand() % 2) == 1)
				{
					ball.speed.y = -ball.speed.y;
				}
				ball.lastTouch = 1;
			}
			if (CheckCollisionCircleRec(ball.pos, ball.radius, player2Rec))
			{
				ball.speed.x = (-ball.speed.x);
				ball.speed.y = (rand() % 400) + 300;
				if ((rand() % 2) == 1)
				{
					ball.speed.y = -ball.speed.y;
				}
				ball.lastTouch = 2;
			}
			if (CheckCollisionCircleRec(ball.pos, ball.radius, topWall) || CheckCollisionCircleRec(ball.pos, ball.radius, bottomWall))
			{
				ball.speed.x = (rand() % 400) + 300;
				if ((rand() % 2) == 1)
				{
					ball.speed.x = -ball.speed.x;
				}
				ball.speed.y = -ball.speed.y;
			}

			if (CheckCollisionCircleRec(ball.pos, ball.radius, leftWall))
			{
				player2Score++;
				ball.pos.x = screenWidth / 2;
			}
			if (CheckCollisionCircleRec(ball.pos, ball.radius, rightWall))
			{
				player1Score++;
				ball.pos.x = screenWidth / 2;
			}

			if (playerRec.y < 0 + 5)
			{
				playerRec.y = 0 + 5;
			}
			if (playerRec.y > screenHeight - playerRec.height - 5)
			{
				playerRec.y = screenHeight - playerRec.height - 5;
			}

			if (player2Rec.y < 0 + 5)
			{
				player2Rec.y = 0 + 5;
			}
			if (player2Rec.y > screenHeight - player2Rec.height - 5)
			{
				player2Rec.y = screenHeight - player2Rec.height - 5;
			}
		}
		if (IsKeyDown(KEY_BACKSPACE))
		{
			CloseWindow();
			restart();
		}

		std::string gameOver = "Game over!";
		std::string player1Win = "Player one wins with " + std::to_string(player1Score) + " points!";
		std::string player2Win = "Player two wins with " + std::to_string(player2Score) + " points!";

			/*if (player.pos.y < -player.radius)
			{
				player.pos.y = screenHeight + player.radius;
			}
			if (player.pos.y > screenHeight + player.radius)
			{
				player.pos.y = -player.radius;
			}
			if (player.pos.x < player.radius)
			{
				player.pos.x = screenWidth + player.radius;
			}
			if (player.pos.x > screenWidth + player.radius)
			{
				player.pos.x = player.radius;
			}
		}
		if (timer > 10.0f)
		{
			timer = 10.0f;
		}
		if (timer == timeLimit)
		{
			DrawText("Time's Up!", 400, 400, 40, MAROON);
		}*/
		//----------------------------------------------------------------------------------
		// TODO: Update your variables here
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(BLACK);

		if (timer < 10)
		{
			for (size_t i = 0; i < 5; i++)
			{
				pickups[i].draw();
			}
			DrawRectangleRec(topWall, PINK);
			DrawRectangleRec(bottomWall, PINK);
			DrawRectangleRec(leftWall, PINK);
			DrawRectangleRec(rightWall, PINK);
			DrawRectangleRec(playerRec, GREEN);
			DrawRectangleRec(player2Rec, GREEN);
			ball.draw();

			//DrawText("Congrats! You created your first window!", 190, 200, 20, BLACK);
			DrawText(std::to_string(player1Score).c_str(), 5, 5, 25, WHITE);
			DrawText(std::to_string(player2Score).c_str(), screenWidth - 50, 5, 25, WHITE);
			DrawText(std::to_string(timer).c_str(), screenWidth / 2 - 60, 10, 25, RED);
		}

		if (timer > 10)
		{
			timer = 10;
			DrawText(("Time's Up! " + gameOver).c_str(), screenWidth/2 - 200, screenHeight/2, 40, WHITE);
			DrawText("Press BACKSPACE to restart or ESC to exit", 5, screenHeight - 30, 30, RED);
			if (player1Score > player2Score)
			{
				DrawText((player1Win).c_str() , screenWidth / 2 - 200, screenHeight / 2 + 50, 30, WHITE);
			}
			else if (player1Score < player2Score)
			{
				DrawText((player2Win).c_str(), screenWidth / 2 - 200, screenHeight / 2 + 50, 30, WHITE);
			}
			else
			{
				DrawText("It's a tie!", screenWidth / 2 - 75, screenHeight / 2 + 50, 30, WHITE);
			}
		}
		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}

void restart()
{
//	CloseWindow();
	while (!WindowShouldClose())
	fakemain();
}