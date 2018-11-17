#include "pickups.h"

void pickup::draw()
{
	DrawCircle(pos.x, pos.y, radius, DARKBLUE);
}

void pickup::checkSpace(pickup pickups[])
{
	for (size_t i = 0; i < 5; i++)
	{

		if (pickups[i].pos.x <= 50 || pickups[i].pos.x >= GetScreenHeight() - 50)
		{
			pickups[i].pos.x = rand() % GetScreenWidth();
		}
		if (pickups[i].pos.y <= 50 || pickups[i].pos.y >= GetScreenHeight() - 50)
		{
			pickups[i].pos.y = rand() % GetScreenHeight();
		}
	}
}

void pickup::pickupUpdate(pickup pickups[], player player[], ball ball)
{
	for (size_t i = 0; i < 5; i++)
	{
		if (CheckCollisionCircles(ball.pos, ball.radius, pickups[i].pos, pickups[i].radius))
		{
			pickups[i].pos.x = rand() % GetScreenWidth();
			pickups[i].pos.y = rand() % GetScreenHeight();

			pickups->checkSpace(pickups);

			for (size_t i = 0; i < 4; i++)
			{
				if (ball.lastTouch == player[i].playerNum)
				{
					player[i].score++;
				}
			}
		}
	}
}
