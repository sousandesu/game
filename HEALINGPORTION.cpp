#include"CONTAINER.h"
#include"GAME.h"
#include"MAP.h"
#include"PLAYER.h"
#include "HEALINGPORTION.h"

void HEALINGPORTION::create()
{
	Chara = game()->container()->data().healingPortionChara;
}

void HEALINGPORTION::damage()
{
	if (Chara.hp > 0) {
		Chara.hp--;
		game()->characterManager()->player()->healingHp();
	}
}
