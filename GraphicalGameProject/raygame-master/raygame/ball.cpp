#include "ball.h"


void ball::paddleUpdate(float deltaTime, player player)
{
	pos.x += speed.x * deltaTime;
	pos.y += speed.y * deltaTime;

	if (CheckCollisionCircleRec(pos, radius, player.rec))
	{
		float angleInRadians = std::atan2(pos.x, pos.y);
		float angleInDegrees = (angleInRadians / PI) * 180.0f;

		pos.x += speed.x * cos(angleInDegrees * PI / 180);
		pos.y += speed.y * sin(angleInDegrees * PI / 180);
		if (pos.x < 0 || pos.x > GetScreenWidth())
		{
			angleInDegrees = 180 - angleInDegrees;
		}
		else if (pos.y < 0 || pos.y > GetScreenHeight())
		{
			angleInDegrees = 360 - angleInDegrees;
		}
		lastTouch = player.playerNum;
	}
}

/*void ball::pickupUpdate(pickup pickups[], player& p1, player& p2, player& p3, player& p4)
{
	for (size_t i = 0; i < 5; i++)
	{
		
		if (CheckCollisionCircles(pos, radius, pickups[i].pos, pickups[i].radius))
		{
            pickups[i].pos.x = rand() % GetScreenWidth();
            pickups[i].pos.y = rand() % GetScreenHeight();

			pickups->checkSpace(pickups, GetScreenHeight(), GetScreenWidth());

            if (lastTouch == 1)
            {
                p1.score++;
            }
            else if (lastTouch == 2)
            {
                p2.score++;
            }
            else if (lastTouch == 3)
            {
                p3.score++;
            }
            else if (lastTouch == 4)
            {
                p4.score++;
            }
		}
	}
}*/

void ball::wallUpdate(Rectangle topWall, Rectangle bottomWall, Rectangle leftWall, Rectangle rightWall, player players[])
{
	if (CheckCollisionCircleRec(pos, radius, leftWall) || CheckCollisionCircleRec(pos, radius, rightWall) || CheckCollisionCircleRec(pos, radius, topWall) || CheckCollisionCircleRec(pos, radius, bottomWall))
	{
		std::cout << "WALL" << std::endl;
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

/*void ball::paddleMovement(float deltaTime, player & p2, player & p3, player & p4)
{
	if (!p2.isPlayer && p2.isHorizon)
	{
		if (pos.x > p2.rec.x)
		{
			p2.rec.x += p2.speed * deltaTime;
		}
		if (pos.x < p2.rec.x)
		{
			p2.rec.x -= p2.speed * deltaTime;
		}
	}
	else if (!p2.isPlayer && !p2.isHorizon)
	{
		if (pos.y > p2.rec.y)
		{
			p2.rec.y += p2.speed * deltaTime;
		}
		if (pos.y < p2.rec.y)
		{
			p2.rec.y -= p2.speed * deltaTime;
		}
	}

	if (!p3.isPlayer && p3.isHorizon)
	{
		if (pos.x > p3.rec.x)
		{
			p3.rec.x += p3.speed * deltaTime;
		}
		if (pos.x < p3.rec.x)
		{
			p3.rec.x -= p3.speed * deltaTime;
		}
	}
	else if(!p3.isPlayer && !p3.isHorizon)
	{
		if (pos.y > p3.rec.y)
		{
			p3.rec.y += p3.speed * deltaTime;
		}
		if (pos.y < p3.rec.y)
		{
			p3.rec.y -= p3.speed * deltaTime;
		}
	}

	if (!p4.isPlayer && p4.isHorizon)
	{
		if (pos.x > p4.rec.x)
		{
			p4.rec.x += p4.speed * deltaTime;
		}
		if (pos.x < p4.rec.x)
		{
			p4.rec.x -= p4.speed * deltaTime;
		}
		
	}
	else if (!p4.isPlayer && !p4.isHorizon)
	{
		if (pos.y > p4.rec.y)
		{
			p4.rec.y += p4.speed * deltaTime;
		}
		if (pos.y < p4.rec.y)
		{
			p4.rec.y -= p4.speed * deltaTime;
		}
	}
}*/

void ball::draw()
{
	DrawCircle(pos.x, pos.y, radius, SKYBLUE);
}
