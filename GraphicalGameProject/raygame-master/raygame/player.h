#pragma once

#include "raylib.h"

class player
{
public:
	Rectangle rec;
	
	float speed = 600.0f;
	bool isPlayer;
	Color recColor;
	int score = 0;

	void update(float deltaTime);
	void draw();
};