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

void GAME_OVER::init()
{
	Game_over.changeBackFlag = false;
}

void GAME_OVER::draw()
{
	if (Game_over.changeBackTime <= 0 && !Game_over.changeBackFlag) {
		Game_over.changeBackTime = Game_over.changeBackInterval * delta;
	}
	if (Game_over.changeBackTime > 0 && !Game_over.changeBackFlag) {
		Game_over.changeBackTime -= delta;
		clear();
		game()->map()->draw();
		game()->characterManager()->draw();
		game()->hitPoint()->draw();
		if (Game_over.changeBackTime <= 0) {
			Game_over.changeBackFlag = true;
		}
	}
	else
	{
		clear();
		imageColor(Game_over.backColor);
		image(Game_over.backImg, 0, 0);
	}
}

void GAME_OVER::nextScene()
{
	if (Game_over.changeBackTime <= 0 && Game_over.changeBackFlag) {
		if (isTrigger(KEY_SPACE)) {
			game()->changeScene(GAME::TITLE_ID);
		}
	}
}
