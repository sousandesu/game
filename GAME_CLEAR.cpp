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

void GAME_CLEAR::init()
{
	Game_clear.changeBackFlag = false;
}

void GAME_CLEAR::draw()
{
	if (Game_clear.changeBackTime <= 0 && !Game_clear.changeBackFlag) {
		Game_clear.changeBackTime = Game_clear.changeBackInterval * delta;
	}
	if (Game_clear.changeBackTime > 0 && !Game_clear.changeBackFlag) {
		Game_clear.changeBackTime -= delta;
		clear();
		game()->map()->draw();
		game()->characterManager()->draw();
		game()->hitPoint()->draw();
		if (Game_clear.changeBackTime <= 0) {
			Game_clear.changeBackFlag = true;
		}
	}
	else
	{
		clear();
		imageColor(Game_clear.backColor);
		image(Game_clear.backImg, 0, 0);
	}
}

void GAME_CLEAR::nextScene()
{
	if (Game_clear.changeBackTime <= 0 && Game_clear.changeBackFlag) {
		if (isTrigger(KEY_SPACE)) {
			game()->changeScene(GAME::TITLE_ID);
		}
	}
}
