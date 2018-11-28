#include "bots.h"

void paddleMovement(float deltaTime, player players[], ball ball)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (players[i].isPlayer)
		{
			players[i].speed = 200.0f;
		}
		if (checkBallPosition(players[i], ball))
		{
			if (!players[i].isPlayer && players[i].isHorizon)
			{
				if (ball.pos.x > players[i].rec.x)
				{
					players[i].rec.x += players[i].speed * deltaTime;
				}
				if (ball.pos.x < players[i].rec.x)
				{
					players[i].rec.x -= players[i].speed * deltaTime;
				}
			}
			else if (!players[i].isPlayer && !players[i].isHorizon)
			{
				if (ball.pos.y > players[i].rec.y)
				{
					players[i].rec.y += players[i].speed * deltaTime;
				}
				if (ball.pos.y < players[i].rec.y)
				{
					players[i].rec.y -= players[i].speed * deltaTime;
				}
			}
			else
			{
				players[i].update(GetFrameTime());
			}
		}
	}
}

bool checkBallPosition(player player, ball ball)
{
	if (player.isPlayer)
	{
		return true;
	}

	if (player.playerNum == 2)
	{
		if (ball.pos.y <= GetScreenHeight() / 2)
		{
			return true;
		}
	}

	if (player.playerNum == 3)
	{
		if (ball.pos.x >= GetScreenWidth() / 2)
		{
			return true;
		}
	}

	if (player.playerNum == 4)
	{
		if (ball.pos.y >= GetScreenHeight() / 2)
		{
			return true;
		}
	}
	return false;
}