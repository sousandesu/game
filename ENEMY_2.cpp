#include"CONTAINER.h"
#include"GAME.h"
#include"PLAYER.h"
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
}
void ENEMY_2::appear(float wx, float wy, float vx, float vy)
{
	Chara.hp = game()->container()->data().enemy_2Chara.hp;
	Chara.wx = wx;
	Chara.wy = wy;
	Chara.animId = Enemy_2.leftAnimId;
}
void ENEMY_2::update()
{
	Move();
	Launch();
	CollisionWithMap();
}
void ENEMY_2::Move()
{
	if (!Enemy_2.launchFlag) {
		randomMove();

		//  移動前に現在のChara.wxをPlayer.curWxにとっておく
		Enemy_2.curWx = Chara.wx;
		//  移動前に現在のChara.wyをPlayer.curWyにとっておく
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
		}
		else if (Enemy_2.direction == 1) {
			Chara.vx = -Chara.speed * delta;
		}
		else if (Enemy_2.direction == 2) {
			Chara.vy = -Chara.speed * delta;
		}
		else if (Enemy_2.direction == 3) {
			Chara.vy = Chara.speed * delta;
		}
	//前の座標からマップチップ分動いたらムーブをやめるかのif文
	if (Chara.wx > Enemy_2.differenceX + game()->map()->chipSize() ||
		Chara.wx <Enemy_2.differenceX - game()->map()->chipSize() ||
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
			}
			else
			{
				Chara.vx = Chara.speed * delta;
				vx = 1.0f;
				vy = 0.0f;
				wx = Chara.wx + Enemy_2.bulletOffsetX * vx;
				wy = Chara.wy + Enemy_2.bulletOffsetY * vy;
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
			}
			else
			{
				Chara.vy = Chara.speed * delta;
				vx = 0.0f;
				vy = 1.0f;
				wx = Chara.wx + Enemy_2.bulletOffsetX * vx;
				wy = Chara.wy + Enemy_2.bulletOffsetY * vy;
			}
			game()->characterManager()->appear(Enemy_2.bulletCharaId, wx, wy, vx, vy);
		}
	}
	else {
		if (Enemy_2.waitingTime <= 0 && Enemy_2.dontLaunchTime <= 0) {
			Enemy_2.waitingTime = Enemy_2.waitingInterval;
		}
		if (Enemy_2.waitingTime > 0 && Enemy_2.dontLaunchTime <= 0) {
			Enemy_2.waitingTime -= delta;
			if (Enemy_2.waitingTime <= 0) {
				Enemy_2.launchFlag = false;
				Enemy_2.dontLaunchTime = Enemy_2.dontLaunchInterval;
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
	fill(0, 0, 255);
	rect(Enemy_2.px, Enemy_2.py, 128, 128);
}

//敵の弾と無敵時間や待機時間をどうデルタにするか