#pragma once

#include "raylib.h"
class ball
{
public:
	Vector2 pos;
	float radius;

	Vector2 speed;

	int lastTouch; //which player last touched the ball

	void update(float deltaTime);
	void draw();
};

//Player Ball (Walkthrough)
/*class playball 
{
public:
	Vector2 pos;	//Position
	float radius;	//Size

	float speed;

	void update(float deltaTime);
	void draw();
};*/