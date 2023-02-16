#include"CONTAINER.h"
#include"GAME.h"
#include"PLAYER.h"
#include"MAP.h"
#include "BOSS.h"
#include<math.h>


void BOSS::create()
{
	Chara = game()->container()->data().bossChara;
	Boss = game()->container()->data().boss;
}

void BOSS::init()
{
	Chara.hp = 0;
	Chara.vx = 0.0f;
	Chara.vy = 0.0f;
}

void BOSS::appear(float wx, float wy, float vx, float vy)
{
	Chara.hp = game()->container()->data().bossChara.hp;
	Chara.wx = wx;
	Chara.wy = wy;
}

void BOSS::update()
{
	Move();
	Launch();
	CollisionWithMap();
}

void BOSS::Move()
{
	//randomMove();

	//  移動前に現在のChara.wxをEnemy_1.curWxにとっておく
	Boss.curWx = Chara.wx;
	//  移動前に現在のChara.wyをEnemy_1.curWyにとっておく
	Boss.curWy = Chara.wy;
	//  移動
	if (Chara.vx != 0.0f || Chara.vy != 0.0f) {//左右上下キー入力あり
		//とりあえず「次に移動する予定」の位置としてChara.wxを更新しておき
		//あとで、マップに食い込んでいたら、元のPlayer.curWxに戻す
		Chara.wx += Chara.vx;
		Chara.wy += Chara.vy;
	}

}

void BOSS::randomMove()
{
	if (!Boss.moveFlag) {
		Boss.direction = random() % 2;
		Boss.differenceX = Chara.wx;
		Boss.differenceY = Chara.wy;

		Boss.moveFlag = true;
	}
	Chara.vx = 0.0f;
	Chara.vy = 0.0f;
	if (Boss.direction == 0) {
		Chara.vx = Chara.speed * delta;
	}
	else if (Boss.direction == 1) {
		Chara.vx = -Chara.speed * delta;
	}
	//前の座標からマップチップ分動いたらムーブをやめるかのif文
	if (Chara.wx > Boss.differenceX + game()->map()->chipSize() ||
		Chara.wx <Boss.differenceX - game()->map()->chipSize() ||
		Chara.wy > Boss.differenceY + game()->map()->chipSize() ||
		Chara.wy < Boss.differenceY - game()->map()->chipSize()) {

		if ((Chara.wx > Boss.differenceX + game()->map()->chipSize())) Chara.wx = Boss.differenceX + game()->map()->chipSize();
		if ((Chara.wx < Boss.differenceX - game()->map()->chipSize())) Chara.wx = Boss.differenceX - game()->map()->chipSize();
		if ((Chara.wy > Boss.differenceY + game()->map()->chipSize())) Chara.wy = Boss.differenceY + game()->map()->chipSize();
		if ((Chara.wy < Boss.differenceY - game()->map()->chipSize())) Chara.wy = Boss.differenceY - game()->map()->chipSize();

		Boss.moveFlag = false;
	}
}

void BOSS::Launch()
{
	switch (Boss.nextLaunchPattern) {
	case 0:
		LaunchPattern1();
		break;
	case 1:
		LaunchPattern2();
		break;
	case 2:
		LaunchPattern3();
		break;
	}
}

void BOSS::LaunchPattern1()
{
	if (!Boss.launchFlag) {
		float vx = 0.0f;
		float vy = 1.0f;
		float wx = Chara.wx + Boss.bullet1OffsetX;
		float wy = Chara.wy + Boss.bullet1OffsetY * vy;
		Boss.launchFlag = true;
		Boss.numLaunchBullet++;
		game()->characterManager()->appear(Boss.bullet1CharaId, wx, wy, vx, vy);
	}
	else {
		if (Boss.waitingTime <= 0) {
			Boss.waitingTime = Boss.waitingInterval1 * delta;
		}
		if (Boss.waitingTime > 0) {
			Boss.waitingTime -= delta;
			if (Boss.waitingTime <= 0) {
				Boss.launchFlag = false;
				if (Boss.numLaunchBullet >= Boss.numNextLaunchBullet1) {
					Boss.numLaunchBullet = 0;
					Boss.nextLaunchPattern++;
				}
				if (Boss.nextLaunchPattern >= 3) Boss.nextLaunchPattern = 0;
			}
		}
	}
}

void BOSS::LaunchPattern2()
{
	if (!Boss.launchFlag) {
		float vx = 0.0f;
		float vy = 1.0f;

		float vx1 = 0.0f;
		float vy1 = 1.0f;
		float vx2 = 0.0f;
		float vy2 = 1.0f;

		vx = (game()->characterManager()->player()->px() + Boss.bulletToCenterPlayerOffsetX) - (Boss.px + Boss.bullet2OffsetX);
		vy = (game()->characterManager()->player()->py() + Boss.bulletToCenterPlayerOffsetY) - (Boss.py + Boss.bullet2OffsetY);
		normalize(&vx, &vy, vx, vy);

		vx1 = vx * Cos(Boss.threeWayangle) - vy * Sin(Boss.threeWayangle);
		vy1 = vx * Sin(Boss.threeWayangle) + vy * Cos(Boss.threeWayangle);

		vx2 = vx * Cos(-Boss.threeWayangle) - vy * Sin(-Boss.threeWayangle);
		vy2 = vx * Sin(-Boss.threeWayangle) + vy * Cos(-Boss.threeWayangle);

		float wx = Chara.wx + Boss.bullet2OffsetX - Boss.bulletCenterOffsetX;
		float wy = Chara.wy + Boss.bullet2OffsetY - Boss.bulletCenterOffsetY;
		Boss.launchFlag = true;
		Boss.numLaunchBullet++;
		game()->characterManager()->appear(Boss.bullet2CharaId, wx, wy, vx, vy);
		game()->characterManager()->appear(Boss.bullet2CharaId, wx, wy, vx1, vy1);
		game()->characterManager()->appear(Boss.bullet2CharaId, wx, wy, vx2, vy2);
	}
	else {
		if (Boss.waitingTime <= 0) {
			Boss.waitingTime = Boss.waitingInterval2 * delta;
		}
		if (Boss.waitingTime > 0) {
			Boss.waitingTime -= delta;
			if (Boss.waitingTime <= 0) {
				Boss.launchFlag = false;
				if (Boss.numLaunchBullet >= Boss.numNextLaunchBullet2) {
					Boss.numLaunchBullet = 0;
					Boss.nextLaunchPattern++;
				}
				if (Boss.nextLaunchPattern >= 3) Boss.nextLaunchPattern = 0;
			}
		}
	}
}

void BOSS::LaunchPattern3()
{
	if (!Boss.launchFlag) {
		float vx = 0.0f;
		float vy = 1.0f;
		vx = (game()->characterManager()->player()->px() + Boss.bulletToCenterPlayerOffsetX) - (Boss.px + Boss.bullet3OffsetX);
		vy = (game()->characterManager()->player()->py() + Boss.bulletToCenterPlayerOffsetY) - (Boss.py + Boss.bullet3OffsetY);
		normalize(&vx, &vy, vx, vy);

		float wx = Chara.wx + Boss.bullet3OffsetX - Boss.bulletCenterOffsetX;
		float wy = Chara.wy + Boss.bullet3OffsetY - Boss.bulletCenterOffsetY;
		Boss.launchFlag = true;
		Boss.numLaunchBullet++;
		game()->characterManager()->appear(Boss.bullet3CharaId, wx, wy, vx, vy);
	}
	else {
		if (Boss.waitingTime <= 0) {
			Boss.waitingTime = Boss.waitingInterval3 * delta;
		}
		if (Boss.waitingTime > 0) {
			Boss.waitingTime -= delta;
			if (Boss.waitingTime <= 0) {
				Boss.launchFlag = false;
				if (Boss.numLaunchBullet >= Boss.numNextLaunchBullet3) {
					Boss.numLaunchBullet = 0;
					Boss.nextLaunchPattern++;
				}
				if (Boss.nextLaunchPattern >= 3) Boss.nextLaunchPattern = 0;
			}
		}
	}
}

void BOSS::CollisionWithMap()
{
	MAP* map = game()->map();

	// マップチップとキャラの右
	if (map->collisionCharaRight(wLeft(), wTop(), wRight(), wBottom())) {
		//移動予定位置がマップに食い込んでいるので現在の位置に戻す
		Chara.wx = Boss.curWx;
		Boss.moveFlag = false;
	}
	// マップチップとキャラの左
	else if (map->collisionCharaLeft(wLeft(), wTop(), wRight(), wBottom())) {
		Chara.wx = Boss.curWx;
		Boss.moveFlag = false;
	}
	// マップチップとキャラの上
	if (map->collisionCharaTop(wLeft(), wTop(), wRight(), wBottom())) {
		Chara.wy = Boss.curWy;
		Boss.moveFlag = false;
	}
	// マップチップとキャラの下
	else if (map->collisionCharaBottom(wLeft(), wTop(), wRight(), wBottom())) {
		Chara.wy = Boss.curWy;
		Boss.moveFlag = false;
	}
}

void BOSS::draw()
{
	Boss.px = Chara.wx - game()->map()->wx();
	Boss.py = Chara.wy - game()->map()->wy();
	fill(0, 0, 255);
	rect(Boss.px, Boss.py, 384, 384);
}

void BOSS::normalize(float* ovx,float* ovy,	float ivx,	float ivy) {
	float l = sqrtf(ivx * ivx + ivy * ivy);
	if (l != 0.0f) {
		*ovx = ivx / l;
		*ovy = ivy / l;
	}
	else {
		*ovx = ivx;
		*ovy = ivy;
	}
}