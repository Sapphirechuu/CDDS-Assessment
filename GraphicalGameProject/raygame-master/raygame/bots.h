#pragma once

#include "ball.h"
#include "player.h"

void paddleMovement(float deltaTime, player players[], ball ball);

bool checkBallPosition(player player, ball ball);