#include "ball.h"


void ball::paddleUpdate(float deltaTime, player player)
{
	pos.x += speed.x * deltaTime;
	pos.y += speed.y * deltaTime;

	if (CheckCollisionCircleRec(pos, radius, player.rec))
	{
		if (lastTouch != player.playerNum)
		{
			if (player.isHorizon)
			{
				speed.y = -speed.y;
			}
			if (!player.isHorizon)
			{
				speed.x = -speed.x;
			}
			lastTouch = player.playerNum;
		}
	}
}

void ball::wallUpdate(Rectangle topWall, Rectangle bottomWall, Rectangle leftWall, Rectangle rightWall, player players[])
{
	if (CheckCollisionCircleRec(pos, radius, leftWall) || CheckCollisionCircleRec(pos, radius, rightWall) || CheckCollisionCircleRec(pos, radius, topWall) || CheckCollisionCircleRec(pos, radius, bottomWall))
	{
		//std::cout << "WALL" << std::endl;
		for (size_t i = 0; i < 4; i++)
		{
			if (lastTouch == players[i].playerNum)
			{
				players[i].score++;
				lastTouch = 0;
			}
		}
		pos.x = GetScreenWidth() / 2;
		pos.y = GetScreenHeight() / 2;
	}

	if (pos.x < 0 || pos.x > GetScreenWidth() || pos.y < 0 || pos.y > GetScreenHeight())
	{
		pos.x = GetScreenWidth() / 2;
		pos.y = GetScreenHeight() / 2;
	}
}

void ball::draw()
{
	DrawCircle(pos.x, pos.y, radius, SKYBLUE);
}