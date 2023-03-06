#include"GAME.h"
#include"CONTAINER.h"
#include "BOSS_HP_GAUGE.h"
BOSS_HP_GAUGE::BOSS_HP_GAUGE(GAME* game) :
	GAME_OBJECT(game)
{

}

BOSS_HP_GAUGE::~BOSS_HP_GAUGE()
{

}

void BOSS_HP_GAUGE::create()
{
	Boss_Hp_Gauge = game()->container()->data().boss_hp_gauge;
}

void BOSS_HP_GAUGE::init()
{

}

void BOSS_HP_GAUGE::draw()
{
	if (game()->characterManager()->hp(Boss_Hp_Gauge.bossCharaId) > Boss_Hp_Gauge.maxHp / 10 * 9) {
		image(Boss_Hp_Gauge.fullImg, Boss_Hp_Gauge.px, Boss_Hp_Gauge.py);
	}
	else if(game()->characterManager()->hp(Boss_Hp_Gauge.bossCharaId) > Boss_Hp_Gauge.maxHp / 10 * 8){
		image(Boss_Hp_Gauge.ninetyImg, Boss_Hp_Gauge.px, Boss_Hp_Gauge.py);
	}
	else if (game()->characterManager()->hp(Boss_Hp_Gauge.bossCharaId) > Boss_Hp_Gauge.maxHp / 10 * 7) {
		image(Boss_Hp_Gauge.eightyImg, Boss_Hp_Gauge.px, Boss_Hp_Gauge.py);
	}
	else if (game()->characterManager()->hp(Boss_Hp_Gauge.bossCharaId) > Boss_Hp_Gauge.maxHp / 10 * 6) {
		image(Boss_Hp_Gauge.seventyImg, Boss_Hp_Gauge.px, Boss_Hp_Gauge.py);
	}
	else if (game()->characterManager()->hp(Boss_Hp_Gauge.bossCharaId) > Boss_Hp_Gauge.maxHp / 10 * 5) {
		image(Boss_Hp_Gauge.sixtyImg, Boss_Hp_Gauge.px, Boss_Hp_Gauge.py);
	}
	else if (game()->characterManager()->hp(Boss_Hp_Gauge.bossCharaId) > Boss_Hp_Gauge.maxHp / 10 * 4) {
		image(Boss_Hp_Gauge.fiftyImg, Boss_Hp_Gauge.px, Boss_Hp_Gauge.py);
	}
	else if (game()->characterManager()->hp(Boss_Hp_Gauge.bossCharaId) > Boss_Hp_Gauge.maxHp / 10 * 3) {
		image(Boss_Hp_Gauge.fortyImg, Boss_Hp_Gauge.px, Boss_Hp_Gauge.py);
	}
	else if (game()->characterManager()->hp(Boss_Hp_Gauge.bossCharaId) > Boss_Hp_Gauge.maxHp / 10 * 2) {
		image(Boss_Hp_Gauge.thirtyImg, Boss_Hp_Gauge.px, Boss_Hp_Gauge.py);
	}
	else if (game()->characterManager()->hp(Boss_Hp_Gauge.bossCharaId) > Boss_Hp_Gauge.maxHp / 10 * 1) {
		image(Boss_Hp_Gauge.twentyImg, Boss_Hp_Gauge.px, Boss_Hp_Gauge.py);
	}
	else if (game()->characterManager()->hp(Boss_Hp_Gauge.bossCharaId) > Boss_Hp_Gauge.maxHp / 10 * 0) {
		image(Boss_Hp_Gauge.tenImg, Boss_Hp_Gauge.px, Boss_Hp_Gauge.py);
	}
	//else if (game()->characterManager()->hp(Boss_Hp_Gauge.bossCharaId) == Boss_Hp_Gauge.maxHp / 10 * 0) {
	//	image(Boss_Hp_Gauge.emptyImg, Boss_Hp_Gauge.px, Boss_Hp_Gauge.py);
	//}
}
