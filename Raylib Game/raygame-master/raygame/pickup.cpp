#include "pickup.h"

#include "raylib.h"

//Pickup (Walkthrough)
void pickup::draw()
{
	DrawCircle(pos.x, pos.y, radius, DARKBLUE);
}
