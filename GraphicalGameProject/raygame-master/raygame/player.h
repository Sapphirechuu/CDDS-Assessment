#pragma once

#include "raylib.h"
//#include "ball.h"
#include <iostream>

class player
{
public:
	Rectangle rec;

	bool isPlayer;
	bool isHorizon = false;
	int playerNum = -1;
	Color recColor;
	int score = 0;
	float speed = 200.0f;

	void update(float deltaTime);
	void draw();

};