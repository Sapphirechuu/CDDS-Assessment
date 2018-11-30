#include "ball.h"

#include "raylib.h"


//Player Ball (Walkthrough)
/*void ball::update(float deltaTime)
{
	if (IsKeyDown(KEY_W))
	{
		pos.y -= speed * deltaTime;
	}

	if (IsKeyDown(KEY_S))
	{
		pos.y += speed * deltaTime;
	}
	
	if (IsKeyDown(KEY_A))
	{
		pos.x -= speed * deltaTime;
	}

	if (IsKeyDown(KEY_D))
	{
		pos.x += speed * deltaTime;
	}
}

void ball::draw()
{
	DrawCircle(pos.x, pos.y, radius, PINK);
}*/

void ball::update(float deltaTime)
{
	pos.x += speed.x * deltaTime;
	pos.y += speed.y * deltaTime;
}

void ball::draw()
{
	DrawCircle(pos.x, pos.y, radius, SKYBLUE);
}
