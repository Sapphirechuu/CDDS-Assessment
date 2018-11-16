#pragma once

#include "raylib.h"
#include "pickups.h"
#include "player.h"

class ball
{
public:
	Vector2 pos;
	float radius;

	Vector2 speed;

	int lastTouch;

	void paddleUpdate(float deltaTime, Rectangle playerRec, Rectangle botA, Rectangle botB, Rectangle botC);
	void pickupUpdate(pickup pickups[], int screenHeight, int screenWidth, player& p1, player& p2, player& p3, player& p4);
	void wallUpdate(Rectangle topWall, Rectangle bottomWall, Rectangle leftWall, Rectangle rightWall, int screenHeight, int screenWidth, player& p1, player& p2, player& p3, player& p4);
	void draw();
};