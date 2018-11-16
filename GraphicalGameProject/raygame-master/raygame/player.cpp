#include "player.h"

void player::update(float deltaTime)
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

void player::draw()
{
	DrawRectangle(rec.x, rec.y, rec.width, rec.height, recColor);
}
