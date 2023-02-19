#include"GAME.h"
#include"CONTAINER.h"
#include "GAME_CLEAR.h"
GAME_CLEAR::GAME_CLEAR(GAME* game) :
	SCENE(game)
{
}

GAME_CLEAR::~GAME_CLEAR()
{
}

void GAME_CLEAR::create()
{
	Game_clear = game()->container()->data().game_clear;
}

void GAME_CLEAR::draw()
{
	clear();
	imageColor(Game_clear.backColor);
	image(Game_clear.backImg, 0, 0);
}

void GAME_CLEAR::nextScene()
{
	if (isTrigger(KEY_SPACE)) {
		game()->changeScene(GAME::TITLE_ID);
	}
}
