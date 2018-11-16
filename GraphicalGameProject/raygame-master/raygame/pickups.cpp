#include "pickups.h"

void pickup::draw()
{
	DrawCircle(pos.x, pos.y, radius, DARKBLUE);
}
