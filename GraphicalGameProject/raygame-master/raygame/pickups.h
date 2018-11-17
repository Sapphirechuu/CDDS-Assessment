#pragma once

#include "raylib.h"
#include "player.h"
#include "ball.h"
#include <iostream>

class pickup
{
public:
	Vector2 pos;
	float radius;

	int value;

	void draw();
	void checkSpace(pickup pickups[]);
	void pickupUpdate(pickup pickups[], player player[], ball ball);
};