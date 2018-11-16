#include "ball.h"
#include <iostream>

void ball::paddleUpdate(float deltaTime, Rectangle playerRec, Rectangle botA, Rectangle botB, Rectangle botC)
{
	pos.x += speed.x * deltaTime;
	pos.y += speed.y * deltaTime;

	if (CheckCollisionCircleRec(pos, radius, playerRec))
	{
		speed.x = (-speed.x);
		speed.y = (rand() % 400) + 300;
		if ((rand() % 2) == 1)
		{
			speed.y = -speed.y;
		}
		lastTouch = 1;
	}
	if (CheckCollisionCircleRec(pos, radius, botA))
	{
		speed.x = (-speed.x);
		lastTouch = 2;
	}
	if (CheckCollisionCircleRec(pos, radius, botB))
	{
		speed.y = (-speed.y);
		lastTouch = 3;
	}
	if (CheckCollisionCircleRec(pos, radius, botC))
	{
		speed.y = (-speed.y);
		lastTouch = 4;
	}
}

void ball::pickupUpdate(pickup pickups[], int screenHeight, int screenWidth, player& p1, player& p2, player& p3, player& p4)
{
	for (size_t i = 0; i < 5; i++)
	{
		if (CheckCollisionCircles(pos, radius, pickups[i].pos, pickups[i].radius))
		{
			if (lastTouch == 1)
			{
				p1.score++;
				pickups[i].pos.x = rand() % screenWidth;
				pickups[i].pos.y = rand() % screenHeight;
			}
			else if (lastTouch == 2)
			{
				p2.score++;
				pickups[i].pos.x = rand() % screenWidth;
				pickups[i].pos.y = rand() % screenHeight;
			}
			else if (lastTouch == 3)
			{
				p3.score++;
				pickups[i].pos.x = rand() % screenWidth;
				pickups[i].pos.y = rand() % screenHeight;
			}
			else if (lastTouch == 4)
			{
				p4.score++;
				pickups[i].pos.x = rand() % screenWidth;
				pickups[i].pos.y = rand() % screenHeight;
			}
		}
	}
}

void ball::wallUpdate(Rectangle topWall, Rectangle bottomWall, Rectangle leftWall, Rectangle rightWall, int screenHeight, int screenWidth, player& p1, player& p2, player& p3, player& p4)
{
	if (CheckCollisionCircleRec(pos, radius, leftWall) || CheckCollisionCircleRec(pos, radius, rightWall))
	{
		
		if (lastTouch == 1)
		{
			p1.score++;
			lastTouch = 0;
		}
		else if (lastTouch == 2)
		{
			p2.score++;
			lastTouch = 0;
		}
		else if (lastTouch == 3)
		{
			p3.score++;
			lastTouch = 0;
		}
		else if (lastTouch == 4)
		{
			p4.score++;
			lastTouch = 0;
		}
		pos.x = screenWidth / 2;
	}
	else if (CheckCollisionCircleRec(pos, radius, topWall) || CheckCollisionCircleRec(pos, radius, bottomWall))
	{
		if (lastTouch == 1)
		{
			p1.score++;
			lastTouch = 0;
		}
		else if (lastTouch == 2)
		{
			p2.score++;
			lastTouch = 0;
		}
		else if (lastTouch == 3)
		{
			p3.score++;
			lastTouch = 0;
		}
		else if (lastTouch == 4)
		{
			p4.score++;
			lastTouch = 0;
		}
		pos.y = screenHeight / 2;
	}
}

void ball::draw()
{
	DrawCircle(pos.x, pos.y, radius, SKYBLUE);
}
