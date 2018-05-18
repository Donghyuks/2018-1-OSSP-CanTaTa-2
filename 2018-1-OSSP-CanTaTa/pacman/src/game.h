#pragma once

#include "board.h"
#include "fruit.h"
#include "ghost.h"
#include "pacman.h"
#include "pellet.h"
#include "object.h"

typedef enum {
	GameBeginState,
	LevelBeginState,
	GamePlayState,
	WinState,
	DeathState,
	GameoverState
} GameState;

//what you do in current state

//what causes you to transition from state A -> state B

//elevator stationary
//action: do nothing
//transition
//-> moving up (someone presses a button upstairs)
//-> moving down (someone presses a button downstairs)
//-> door opening (someone presses button on current level)
//-> go down/ up (timeout on a specific level)
typedef enum{
	Single,
	Multi,
	Online
}PlayMode;
typedef struct {
	GameState gameState;
	unsigned int ticksSinceModeChange;
	Pacman pacman[2]; // #8 Kim : 1.플레이어수 늘려주기 위해서 배열로 바꿈  Pacman pacman -> pacman[2];
	Ghost ghosts[4];
	Board board;
	PelletHolder pelletHolder;
	GameFruit gameFruit1, gameFruit2, gameFruit3, gameFruit4, gameFruit5;
	GameObject gameObject, gameObject2, gameObject3, gameObject4, gameObject5;
	int highscore;
	int currentLevel;
	PlayMode playMode;
} PacmanGame;

//Updates the game 1 tick, or 1/60th of a second.
void game_tick(PacmanGame *game);

//Renders the game in its current state.
void game_render(PacmanGame *game);

//Returns true if the game is finished and is ready to hand back to the menu system.
bool is_game_over(PacmanGame *game);

//Call this at start of level 1 to initialize all entities and game objects.
void gamestart_init(PacmanGame *game);

//Call this at the start of each level to reinitialize all entities to a default state.
void level_init(PacmanGame *game);

//Call after pacman dies to reinitialize entities to continue the same level.
void pacdeath_init(PacmanGame *game);

//Returns the length of the given integer.
int int_length(int num);
