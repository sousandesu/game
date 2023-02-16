#include"CONTAINER.h"
#include"GAME.h"
#include"MAP.h"
#include"PLAYER.h"
#include "HEALINGPORTION.h"

void HEALINGPORTION::create()
{
	Chara = game()->container()->data().healingPortionChara;
}

void HEALINGPORTION::draw()
{
	float px = Chara.wx - game()->map()->wx();
	float py = Chara.wy - game()->map()->wy();
	fill(255, 255, 0);
	rect(px, py, 128, 128);
}

void HEALINGPORTION::damage()
{
	if (Chara.hp > 0) {
		Chara.hp--;
		game()->characterManager()->player()->healingHp();
	}
}
