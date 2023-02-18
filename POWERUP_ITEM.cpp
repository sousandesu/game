#include"CONTAINER.h"
#include"GAME.h"
#include"MAP.h"
#include"PLAYER.h"
#include "POWERUP_ITEM.h"

void POWERUP_ITEM::create()
{
	Chara = game()->container()->data().powerupItemChara;
}

void POWERUP_ITEM::update()
{

}



void POWERUP_ITEM::damage()
{
	if (Chara.hp > 0) {
		Chara.hp--;
		game()->characterManager()->player()->powerup();
	}
}
