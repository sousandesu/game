#include"libOne.h"
#include"GAME.h"
#include "GAME_OVER.h"
GAME_OVER::GAME_OVER(GAME* game) :
	SCENE(game)
{
}

GAME_OVER::~GAME_OVER()
{
}

void GAME_OVER::draw()
{
	clear();
	printSize(300);
	print("Game over");
}

void GAME_OVER::nextScene()
{
	if (isTrigger(KEY_SPACE)) {
		game()->changeScene(GAME::TITLE_ID);
	}
}
