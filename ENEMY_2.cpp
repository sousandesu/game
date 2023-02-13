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

		//  �ړ��O�Ɍ��݂�Chara.wx��Player.curWx�ɂƂ��Ă���
		Enemy_2.curWx = Chara.wx;
		//  �ړ��O�Ɍ��݂�Chara.wy��Player.curWy�ɂƂ��Ă���
		Enemy_2.curWy = Chara.wy;
		//  �ړ�
		if (Chara.vx != 0.0f || Chara.vy != 0.0f) {//���E�㉺�L�[���͂���
			//�Ƃ肠�����u���Ɉړ�����\��v�̈ʒu�Ƃ���Chara.wx���X�V���Ă���
			//���ƂŁA�}�b�v�ɐH������ł�����A����Player.curWx�ɖ߂�
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
	//�O�̍��W����}�b�v�`�b�v���������烀�[�u����߂邩��if��
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
		//�c�̍��W�������Ȃ牡�Ɍ���
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
		//���̍��W�������Ȃ�c�Ɍ���
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

	// �}�b�v�`�b�v�ƃL�����̉E
	if (map->collisionCharaRight(wLeft(), wTop(), wRight(), wBottom())) {
		//�ړ��\��ʒu���}�b�v�ɐH������ł���̂Ō��݂̈ʒu�ɖ߂�
		Chara.wx = Enemy_2.curWx;
		Enemy_2.moveFlag = false;
	}
	// �}�b�v�`�b�v�ƃL�����̍�
	else if (map->collisionCharaLeft(wLeft(), wTop(), wRight(), wBottom())) {
		Chara.wx = Enemy_2.curWx;
		Enemy_2.moveFlag = false;
	}
	// �}�b�v�`�b�v�ƃL�����̏�
	if (map->collisionCharaTop(wLeft(), wTop(), wRight(), wBottom())) {
		Chara.wy = Enemy_2.curWy;
		Enemy_2.moveFlag = false;
	}
	// �}�b�v�`�b�v�ƃL�����̉�
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

//�G�̒e�Ɩ��G���Ԃ�ҋ@���Ԃ��ǂ��f���^�ɂ��邩