#include"GAME.h"
#include"CONTAINER.h"
#include "GAME_OVER.h"


GAME_OVER::GAME_OVER(GAME* game) :
	SCENE(game)
{
}

GAME_OVER::~GAME_OVER()
{
}

void GAME_OVER::create()
{
	Game_over = game()->container()->data().game_over;
}

void GAME_OVER::draw()
{
	clear();
	imageColor(Game_over.backColor);
	image(Game_over.backImg, 0, 0);
}

void GAME_OVER::nextScene()
{
	if (isTrigger(KEY_SPACE)) {
		game()->changeScene(GAME::TITLE_ID);
	}
}
