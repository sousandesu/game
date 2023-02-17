#include"CONTAINER.h"
#include"GAME.h"
#include"PLAYER.h"
#include"HEALINGPORTION.h"
#include"MAP.h"
#include "ENEMY_1.h"

void ENEMY_1::create()
{
	Chara = game()->container()->data().enemy_1Chara;
	Enemy_1 = game()->container()->data().enemy_1;
}

void ENEMY_1::init()
{
	Chara.hp = 0;
	Chara.vx = 0.0f;
	Chara.vy = 0.0f;
	//Chara.wx = 0.0f;
	//Chara.wy = 0.0f;
	//Enemy_1.px = 0.0f;
	//Enemy_1.py = 0.0f;
	//Enemy_1.curWx = 0.0f;
	//Enemy_1.curWy = 0.0f;
	//Enemy_1.differenceX = 0.0f;
	//Enemy_1.differenceY = 0.0f;
	Enemy_1.dashFlag = false;
	Enemy_1.moveFlag = false;
}

void ENEMY_1::appear(float wx, float wy, float vx, float vy)
{

	Chara.hp = game()->container()->data().enemy_1Chara.hp;
	Chara.wx = wx;
	Chara.wy = wy;
	Enemy_1.differenceX = wx;
	Enemy_1.differenceY = wy;
	Chara.animId = Enemy_1.leftAnimId;
}

void ENEMY_1::update()
{
	Move();
	CollisionWithMap();
}

void ENEMY_1::damage()
{
	if (Chara.hp > 0) {
		Chara.hp--;
		if (Chara.hp == 0) {
			appearPortion();
		}
	}
}

void ENEMY_1::Move()
{
	randomMove();
	dashMove();
	
	//  �ړ��O�Ɍ��݂�Chara.wx��Enemy_1.curWx�ɂƂ��Ă���
	Enemy_1.curWx = Chara.wx;
	//  �ړ��O�Ɍ��݂�Chara.wy��Enemy_1.curWy�ɂƂ��Ă���
	Enemy_1.curWy = Chara.wy;
	//  �ړ�
	if (Chara.vx != 0.0f || Chara.vy != 0.0f) {//���E�㉺�L�[���͂���
		//�Ƃ肠�����u���Ɉړ�����\��v�̈ʒu�Ƃ���Chara.wx���X�V���Ă���
		//���ƂŁA�}�b�v�ɐH������ł�����A����Player.curWx�ɖ߂�
		Chara.wx += Chara.vx;
		Chara.wy += Chara.vy;
	}
	
}

void ENEMY_1::randomMove() {
	if (!Enemy_1.moveFlag) {
		Enemy_1.direction = random() % 4;
		Enemy_1.differenceX = Chara.wx;
		Enemy_1.differenceY = Chara.wy;

		Enemy_1.moveFlag = true;
	}
	if (!Enemy_1.dashFlag) {
		Chara.vx = 0.0f;
		Chara.vy = 0.0f;
		if (Enemy_1.direction == 0) {
			Chara.vx = Chara.speed * delta;
			Chara.animId = Enemy_1.rightAnimId;
		}
		else if (Enemy_1.direction == 1) {
			Chara.vx = -Chara.speed * delta;
			Chara.animId = Enemy_1.leftAnimId;
		}
		else if (Enemy_1.direction == 2) {
			Chara.vy = -Chara.speed * delta;
			Chara.animId = Enemy_1.upAnimId;
		}
		else if (Enemy_1.direction == 3) {
			Chara.vy = Chara.speed * delta;
			Chara.animId = Enemy_1.downAnimId;
		}
	}
	//�O�̍��W����}�b�v�`�b�v���������烀�[�u����߂邩��if��
	if (Chara.wx > Enemy_1.differenceX + game()->map()->chipSize() ||
		Chara.wx <Enemy_1.differenceX - game()->map()->chipSize() ||
		Chara.wy > Enemy_1.differenceY + game()->map()->chipSize() ||
		Chara.wy < Enemy_1.differenceY - game()->map()->chipSize()) {
		
		if ((Chara.wx > Enemy_1.differenceX + game()->map()->chipSize())) Chara.wx = Enemy_1.differenceX + game()->map()->chipSize();
		if ((Chara.wx < Enemy_1.differenceX - game()->map()->chipSize())) Chara.wx = Enemy_1.differenceX - game()->map()->chipSize();
		if ((Chara.wy > Enemy_1.differenceY + game()->map()->chipSize())) Chara.wy = Enemy_1.differenceY + game()->map()->chipSize();
		if ((Chara.wy < Enemy_1.differenceY - game()->map()->chipSize())) Chara.wy = Enemy_1.differenceY - game()->map()->chipSize();

		Enemy_1.moveFlag = false;
	}
}

void ENEMY_1::dashMove() {
	if (!Enemy_1.dashFlag && !Enemy_1.moveFlag) {
		Chara.vx = 0.0f;
		Chara.vy = 0.0f;
		//�c�̍��W�������Ȃ牡�ɍs��
		if (Enemy_1.py <= game()->characterManager()->player()->py() + Enemy_1.sensingOffset &&
			Enemy_1.py >= game()->characterManager()->player()->py() - Enemy_1.sensingOffset) {
			Enemy_1.dashFlag = true;
			if (Enemy_1.px > game()->characterManager()->player()->px()) {
				Chara.vx = -Enemy_1.dashspeed * delta;
				Chara.animId = Enemy_1.leftAnimId;
			}
			else
			{
				Chara.vx = Enemy_1.dashspeed * delta;
				Chara.animId = Enemy_1.rightAnimId;
			}
		}
		//���̍��W�������Ȃ�c�ɍs��
		else if (Enemy_1.px <= game()->characterManager()->player()->px() + Enemy_1.sensingOffset &&
			Enemy_1.px >= game()->characterManager()->player()->px() - Enemy_1.sensingOffset) {
			Enemy_1.dashFlag = true;
			if (Enemy_1.py > game()->characterManager()->player()->py()) {
				Chara.vy = -Enemy_1.dashspeed * delta;
				Chara.animId = Enemy_1.upAnimId;
			}
			else
			{
				Chara.vy = Enemy_1.dashspeed * delta;
				Chara.animId = Enemy_1.downAnimId;
			}
		}
	}
}

void ENEMY_1::CollisionWithMap()
{
	MAP* map = game()->map();

	// �}�b�v�`�b�v�ƃL�����̉E
	if (map->collisionCharaRight(wLeft(), wTop(), wRight(), wBottom())) {
		//�ړ��\��ʒu���}�b�v�ɐH������ł���̂Ō��݂̈ʒu�ɖ߂�
		Chara.wx = Enemy_1.curWx;
		Enemy_1.dashFlag = false;
		Enemy_1.moveFlag = false;
	}
	// �}�b�v�`�b�v�ƃL�����̍�
	else if(map->collisionCharaLeft(wLeft(), wTop(), wRight(), wBottom())){
		Chara.wx = Enemy_1.curWx;
		Enemy_1.dashFlag = false;
		Enemy_1.moveFlag = false;
	}
	// �}�b�v�`�b�v�ƃL�����̏�
	if (map->collisionCharaTop(wLeft(), wTop(), wRight(), wBottom())) {
		Chara.wy = Enemy_1.curWy;
		Enemy_1.dashFlag = false;
		Enemy_1.moveFlag = false;
	}
	// �}�b�v�`�b�v�ƃL�����̉�
	else if (map->collisionCharaBottom(wLeft(), wTop(), wRight(), wBottom())) {
		Chara.wy = Enemy_1.curWy;
		Enemy_1.dashFlag = false;
		Enemy_1.moveFlag = false;
	}
}

void ENEMY_1::draw()
{
	Enemy_1.px = Chara.wx - game()->map()->wx();
	Enemy_1.py = Chara.wy - game()->map()->wy();
	imageColor(Chara.color);
	if (Chara.animId == Enemy_1.rightAnimId) {
		image(Enemy_1.rightImg,Enemy_1.px,Enemy_1.py);
	}
	else if (Chara.animId == Enemy_1.leftAnimId) {
		image(Enemy_1.leftImg, Enemy_1.px, Enemy_1.py);
	}
	else if (Chara.animId == Enemy_1.upAnimId) {
		image(Enemy_1.upImg, Enemy_1.px, Enemy_1.py);
	}
	else if (Chara.animId == Enemy_1.downAnimId) {
		image(Enemy_1.downImg, Enemy_1.px, Enemy_1.py);
	}
}

void ENEMY_1::appearPortion()
{
	int num = random() % 100;
	if (num >= 0) {
		game()->characterManager()->healingportion()->appear(Chara.wx, Chara.wy, Chara.vx, Chara.vy);
	}
}

