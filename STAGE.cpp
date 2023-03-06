#include"libOne.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"MAP.h"
#include"HIT_POINT.h"
#include"POWERUP_EXPLANATION.h"
#include"CHARACTER_MANAGER.h"
#include "STAGE.h"
STAGE::STAGE(GAME* game) :
	SCENE(game)
{
}

STAGE::~STAGE()
{

}

void STAGE::create() {
	Stage = game()->container()->data().stage;
}

void STAGE::init()
{
	game()->map()->init();
	game()->characterManager()->init();
	game()->hitPoint()->init();
	game()->powerup_Explanation()->init();
}

void STAGE::update()
{
	game()->characterManager()->update();
	game()->map()->update();
}

void STAGE::draw()
{
	clear();
	game()->map()->draw();
	game()->characterManager()->draw();
	game()->hitPoint()->draw();
	game()->powerup_Explanation()->draw();
	game()->boss_Hp_Gauge()->draw();
}



void STAGE::nextScene()
{
	//if (isTrigger(KEY_SPACE)) {
	//	game()->changeScene(GAME::GAME_CLEAR_ID);
	//}
	//else 
	if (game()->characterManager()->player()->died()) {
		game()->changeScene(GAME::GAME_OVER_ID);
	}
}
