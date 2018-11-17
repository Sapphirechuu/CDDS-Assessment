#pragma once

#include "raylib.h"
//#include "pickups.h"
#include "player.h"
#include <iostream>

class ball
{
public:
	Vector2 pos;
	float radius;

	Vector2 speed;

	int lastTouch;

	void paddleUpdate(float deltaTime, player player);
	//void pickupUpdate(pickup pickups[], player& p1, player& p2, player& p3, player& p4);
	void wallUpdate(Rectangle topWall, Rectangle bottomWall, Rectangle leftWall, Rectangle rightWall, player players[]);
	//void paddleMovement(float deltaTime, player& p2, player& p3, player& p4);
	void draw();
};