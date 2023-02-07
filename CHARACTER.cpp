#include"GAME.h"
#include"MAP.h"
#include "CHARACTER.h"

CHARACTER::CHARACTER(GAME* game):
	GAME_OBJECT(game)
{
}

void CHARACTER::create()
{
}

void CHARACTER::init()
{
	Chara.hp = 0;
}

void CHARACTER::appear(float wx, float wy, float vx, float vy)
{
	Chara.wx = wx;
	Chara.wy = wy;
	Chara.hp = 1;
}

void CHARACTER::update()
{
	float px = Chara.wx - game()->map()->wx();
	if (px < -game()->map()->chipSize()) {
		Chara.hp = 0;
	}
}

void CHARACTER::draw()
{
	float px = Chara.wx - game()->map()->wx();
	float py = Chara.wy - game()->map()->wy();
	//‰æ‘œ•\Ž¦‚Í‚Ü‚¾
}

void CHARACTER::damage()
{
	if (Chara.hp > 0) {
		Chara.hp--;
	}
}
