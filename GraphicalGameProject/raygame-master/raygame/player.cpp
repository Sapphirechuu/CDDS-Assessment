#include "player.h"

void player::update(float deltaTime)
{
	if (isPlayer)
	{
		if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))
		{
			rec.y -= speed * deltaTime;
		}

		if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))
		{
			rec.y += speed * deltaTime;
		}
	}

	if (!isHorizon)
	{
		if (rec.y < 5)
		{
			rec.y = 5;
		}
		if (rec.y > GetScreenHeight() - rec.height - 5)
		{
			rec.y = GetScreenHeight() - rec.height - 5;
		}
	}
	else
	{
		if (rec.x < 5)
		{
			rec.x = 5;
		}
		if (rec.x > GetScreenWidth() - rec.width - 15)
		{
			rec.x = GetScreenWidth() - rec.width - 15;
		}
	}
}

void player::draw()
{
	DrawRectangle(rec.x, rec.y, rec.width, rec.height, recColor);
}
