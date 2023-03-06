#include"CONTAINER.h"
#include"GAME.h"
#include"PLAYER.h"
#include"HEALINGPORTION.h"
#include"MAP.h"
#include "ENEMY_2.h"

void ENEMY_2::create()
{
	Chara = game()->container()->data().enemy_2Chara;
	Enemy_2 = game()->container()->data().enemy_2;
}

void ENEMY_2::init()
{
	Chara.hp = 0;
	Chara.vx = 0.0f;
	Chara.vy = 0.0f;
	//Chara.wx = 0.0f;
	//Chara.wy = 0.0f;
	//Enemy_2.px = 0.0f;
	//Enemy_2.py = 0.0f;
	//Enemy_2.curWx = 0.0f;
	//Enemy_2.curWy = 0.0f;
	//Enemy_2.differenceX = 0.0f;
	//Enemy_2.differenceY = 0.0f;
	Enemy_2.moveFlag = false;
	Enemy_2.damegeFlag = false;
}
void ENEMY_2::appear(float wx, float wy, float vx, float vy)
{
	Chara.hp = game()->container()->data().enemy_2Chara.hp;
	Chara.wx = wx;
	Chara.wy = wy;
	Enemy_2.differenceX = wx;
	Enemy_2.differenceY = wy;
	Chara.animId = Enemy_2.leftAnimId;
	Enemy_2.moveFlag = false;
	Enemy_2.damegeFlag = false;
}
void ENEMY_2::update()
{
	Move();
	Launch();
	CollisionWithMap();
}
void ENEMY_2::damage()
{
	if (Chara.hp > 0) {
		Chara.hp--;
		Enemy_2.damegeFlag = true;
		Enemy_2.damegeTime = Enemy_2.damegeInterval * delta;
		if (Chara.hp == 0) {
			appearPortion();
		}
	}
}
void ENEMY_2::Move()
{
	if (!Enemy_2.launchFlag) {
		randomMove();

		//  移動前に現在のChara.wxをEnemy_2.curWxにとっておく
		Enemy_2.curWx = Chara.wx;
		//  移動前に現在のChara.wyをEnemy_2.curWyにとっておく
		Enemy_2.curWy = Chara.wy;
		//  移動
		if (Chara.vx != 0.0f || Chara.vy != 0.0f) {//左右上下キー入力あり
			//とりあえず「次に移動する予定」の位置としてChara.wxを更新しておき
			//あとで、マップに食い込んでいたら、元のPlayer.curWxに戻す
			Chara.wx += Chara.vx;
			Chara.wy += Chara.vy;
		}
	}

}

void ENEMY_2::randomMove() {
	if (!Enemy_2.moveFlag) {
		Enemy_2.direction = random() % 4;
		Enemy_2.differenceX = Chara.wx;
		Enemy_2.differenceY = Chara.wy;

		Enemy_2.moveFlag = true;
	}
		Chara.vx = 0.0f;
		Chara.vy = 0.0f;
		if (Enemy_2.direction == 0) {
			Chara.vx = Chara.speed * delta;
			Chara.animId = Enemy_2.rightAnimId;
		}
		else if (Enemy_2.direction == 1) {
			Chara.vx = -Chara.speed * delta;
			Chara.animId = Enemy_2.leftAnimId;
		}
		else if (Enemy_2.direction == 2) {
			Chara.vy = -Chara.speed * delta;
			Chara.animId = Enemy_2.upAnimId;
		}
		else if (Enemy_2.direction == 3) {
			Chara.vy = Chara.speed * delta;
			Chara.animId = Enemy_2.downAnimId;
		}
	//前の座標からマップチップ分動いたらムーブをやめるかのif文
		if (Chara.wx > Enemy_2.differenceX + game()->map()->chipSize() ||
			Chara.wx <Enemy_2.differenceX - game()->map()->chipSize()  ||
			Chara.wy > Enemy_2.differenceY + game()->map()->chipSize() ||
			Chara.wy < Enemy_2.differenceY - game()->map()->chipSize()) {

			if ((Chara.wx > Enemy_2.differenceX + game()->map()->chipSize())) Chara.wx = Enemy_2.differenceX + game()->map()->chipSize();
			if ((Chara.wx < Enemy_2.differenceX - game()->map()->chipSize())) Chara.wx = Enemy_2.differenceX - game()->map()->chipSize();
			if ((Chara.wy > Enemy_2.differenceY + game()->map()->chipSize())) Chara.wy = Enemy_2.differenceY + game()->map()->chipSize();
			if ((Chara.wy < Enemy_2.differenceY - game()->map()->chipSize())) Chara.wy = Enemy_2.differenceY - game()->map()->chipSize();

			Enemy_2.moveFlag = false;
		}
}

void ENEMY_2::Launch() {
	if (!Enemy_2.launchFlag && Enemy_2.dontLaunchTime <= 0) {
		float vx = 1.0f;
		float vy = 1.0f;
		float wx = 0.0f;
		float wy = 0.0f;
		//縦の座標が同じなら横に向く
		if (Enemy_2.py <= game()->characterManager()->player()->py() + Enemy_2.sensingOffset &&
			Enemy_2.py >= game()->characterManager()->player()->py() - Enemy_2.sensingOffset) {
			Enemy_2.launchFlag = true;
			if (Enemy_2.px > game()->characterManager()->player()->px()) {
				Chara.vx = -Chara.speed * delta;
				vx = -1.0f;
				vy = 0.0f;
				wx = Chara.wx;
				wy = Chara.wy + Enemy_2.bulletOffsetY * vy;
				Chara.animId = Enemy_2.leftAnimId;
			}
			else
			{
				Chara.vx = Chara.speed * delta;
				vx = 1.0f;
				vy = 0.0f;
				wx = Chara.wx + Enemy_2.bulletOffsetX * vx;
				wy = Chara.wy + Enemy_2.bulletOffsetY * vy;
				Chara.animId = Enemy_2.rightAnimId;
			}
			game()->characterManager()->appear(Enemy_2.bulletCharaId, wx, wy, vx, vy);
		}
		//横の座標が同じなら縦に向く
		else if (Enemy_2.px <= game()->characterManager()->player()->px() + Enemy_2.sensingOffset &&
			Enemy_2.px >= game()->characterManager()->player()->px() - Enemy_2.sensingOffset) {
			Enemy_2.launchFlag = true;
			if (Enemy_2.py > game()->characterManager()->player()->py()) {
				Chara.vy = -Chara.speed * delta;
				vx = 0.0f;
				vy = -1.0f;
				wx = Chara.wx + Enemy_2.bulletOffsetX * vx;
				wy = Chara.wy;
				Chara.animId = Enemy_2.upAnimId;
			}
			else
			{
				Chara.vy = Chara.speed * delta;
				vx = 0.0f;
				vy = 1.0f;
				wx = Chara.wx + Enemy_2.bulletOffsetX * vx;
				wy = Chara.wy + Enemy_2.bulletOffsetY * vy;
				Chara.animId = Enemy_2.downAnimId;
			}
			game()->characterManager()->appear(Enemy_2.bulletCharaId, wx, wy, vx, vy);
		}
	}
	else {
		if (Enemy_2.waitingTime <= 0 && Enemy_2.dontLaunchTime <= 0) {
			Enemy_2.waitingTime = Enemy_2.waitingInterval * delta;
		}
		if (Enemy_2.waitingTime > 0 && Enemy_2.dontLaunchTime <= 0) {
			Enemy_2.waitingTime -= delta;
			if (Enemy_2.waitingTime <= 0) {
				Enemy_2.launchFlag = false;
				Enemy_2.dontLaunchTime = Enemy_2.dontLaunchInterval * delta;
			}
		}
		if (Enemy_2.dontLaunchTime > 0) {
			Enemy_2.dontLaunchTime -= delta;
		}
	}
}

void ENEMY_2::CollisionWithMap()
{
	MAP* map = game()->map();

	// マップチップとキャラの右
	if (map->collisionCharaRight(wLeft(), wTop(), wRight(), wBottom())) {
		//移動予定位置がマップに食い込んでいるので現在の位置に戻す
		Chara.wx = Enemy_2.curWx;
		Enemy_2.moveFlag = false;
	}
	// マップチップとキャラの左
	else if (map->collisionCharaLeft(wLeft(), wTop(), wRight(), wBottom())) {
		Chara.wx = Enemy_2.curWx;
		Enemy_2.moveFlag = false;
	}
	// マップチップとキャラの上
	if (map->collisionCharaTop(wLeft(), wTop(), wRight(), wBottom())) {
		Chara.wy = Enemy_2.curWy;
		Enemy_2.moveFlag = false;
	}
	// マップチップとキャラの下
	else if (map->collisionCharaBottom(wLeft(), wTop(), wRight(), wBottom())) {
		Chara.wy = Enemy_2.curWy;
		Enemy_2.moveFlag = false;
	}
}

void ENEMY_2::draw()
{
	Enemy_2.px = Chara.wx - game()->map()->wx();
	Enemy_2.py = Chara.wy - game()->map()->wy();

	imageColor(Chara.color);
	if (Enemy_2.damegeFlag) {
		imageColor(Enemy_2.damegeColor);
		Enemy_2.damegeTime -= delta;
		if (Enemy_2.damegeTime < 0) Enemy_2.damegeFlag = false;
	}

	if (Chara.animId == Enemy_2.rightAnimId) {
		image(Enemy_2.rightImg, Enemy_2.px, Enemy_2.py);
	}
	else if (Chara.animId == Enemy_2.leftAnimId) {
		image(Enemy_2.leftImg, Enemy_2.px, Enemy_2.py);
	}
	else if (Chara.animId == Enemy_2.upAnimId) {
		image(Enemy_2.upImg, Enemy_2.px, Enemy_2.py);
	}
	else if (Chara.animId == Enemy_2.downAnimId) {
		image(Enemy_2.downImg, Enemy_2.px, Enemy_2.py);
	}
}

void ENEMY_2::appearPortion()
{
	int num = random() % 100;
	if (num >= 80) {
		game()->characterManager()->appear(Enemy_2.healingportionId,Chara.wx, Chara.wy, Chara.vx, Chara.vy);
	}
}

