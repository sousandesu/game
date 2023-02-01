#include"libOne.h"
#include"GAME.h"
#include "GAME_CLEAR.h"
GAME_CLEAR::GAME_CLEAR(GAME* game) :
	SCENE(game)
{
}

GAME_CLEAR::~GAME_CLEAR()
{
}

void GAME_CLEAR::draw()
{
	clear();
	printSize(300);
	print("Game Clear");
}

void GAME_CLEAR::nextScene()
{
	if (isTrigger(KEY_SPACE)) {
		game()->changeScene(GAME::TITLE_ID);
	}
}
