#include"libOne.h"
#include"GAME.h"
#include "STAGE.h"
STAGE::STAGE(GAME* game) :
	SCENE(game)
{
}

STAGE::~STAGE()
{
}

void STAGE::draw()
{
	clear();
	printSize(300);
	print("Stage");
	print("Zでゲームオーバー画面へ");
}

void STAGE::nextScene()
{
	if (isTrigger(KEY_SPACE)) {
		game()->changeScene(GAME::GAME_CLEAR_ID);
	}
	else if (isTrigger(KEY_Z)) {
		game()->changeScene(GAME::GAME_OVER_ID);
	}
}
