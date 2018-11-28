#include "gameState.h"

#include "splashstate.h"
#include "menustate.h"
#include "pongstate.h"
#include "endstate.h"

#include <cassert>

void setupGameState(gamestate *& ptr, GameStates newState)
{
	switch (newState)
	{
	case GameStates::NONE:  ptr = new gamestate();  break;
	case GameStates::SPLASH: ptr = new splashstate(); break;
	case GameStates::MENU:  ptr = new menustate();  break;
	case GameStates::PONG: ptr = new pongstate(); break;
	case GameStates::END:   ptr = new endstate();   break;
	default: assert(false && "Invalid state specified.");
	}
}
