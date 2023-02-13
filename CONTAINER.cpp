#include "CONTAINER.h"

void CONTAINER::load()
{
	setData();
	LoadGraphics();
}

void CONTAINER::setData()
{
	Data.title.backPos.x = 0;
	Data.title.backPos.y = 0;
	Data.title.printSize = 200;

	Data.map.fileName = "assets\\map1.txt";
	Data.map.chipSize = 128;
	Data.map.centerX = width / 2 - Data.map.chipSize / 2;
	Data.map.centerY = height / 2 - Data.map.chipSize / 2;

	Data.playerChara.charaId = MAP::PLAYER_ID;
	Data.playerChara.hp = 6;
	Data.playerChara.groupId = 0;//味方グループは0
	Data.playerChara.speed = 4.4f * 60;
	Data.playerChara.offsetLeft = 4.0f;//仮
	Data.playerChara.offsetTop = 4.0f;//仮
	Data.playerChara.offsetRight = 124.0f;//仮
	Data.playerChara.offsetBottom = 124.0f;//仮
	Data.player.rightAnimId = 0;
	Data.player.leftAnimId = 1;
	Data.player.upAnimId = 2;
	Data.player.downAnimId = 3;
	Data.player.bulletOffsetX = 128.0f;//仮
	Data.player.bulletOffsetY = 128.0f;//仮
	Data.player.invincibleTime = 0;
	Data.player.invincibleInterval = 60 * 0.016f;
	Data.player.bulletCharaId = MAP::PLAYER_BULLET_ID;

	Data.playerBulletChara.charaId = MAP::PLAYER_BULLET_ID;
	Data.playerBulletChara.groupId = 2;//味方バレットグループは2
	Data.playerBulletChara.hp = 1;
	Data.playerBulletChara.speed = 7.7f * 60;//仮
	Data.playerBulletChara.offsetLeft = 0.0f;//仮
	Data.playerBulletChara.offsetTop = 0.0f;//仮
	Data.playerBulletChara.offsetRight = 30.0f;//仮
	Data.playerBulletChara.offsetBottom = 30.0f;//仮

	Data.enemy_1Chara.charaId = MAP::ENEMY_1_ID;
	Data.enemy_1Chara.groupId = 1;//敵グループは1
	Data.enemy_1Chara.hp = 4;
	Data.enemy_1Chara.speed = 3.0f * 60;
	Data.enemy_1Chara.offsetLeft = 4.0f;//仮
	Data.enemy_1Chara.offsetRight = 124.0f;//仮
	Data.enemy_1Chara.offsetTop = 4.0f;//仮
	Data.enemy_1Chara.offsetBottom = 124.0f;//仮
	Data.enemy_1.rightAnimId = 0;
	Data.enemy_1.leftAnimId = 1;
	Data.enemy_1.upAnimId = 2;
	Data.enemy_1.downAnimId = 3;
	Data.enemy_1.dashspeed = 4.0f * 60;
	Data.enemy_1.sensingOffset = 15.0f;

	Data.enemy_2Chara.charaId = MAP::ENEMY_2_ID;
	Data.enemy_2Chara.groupId = 1;//敵グループは1
	Data.enemy_2Chara.hp = 4;
	Data.enemy_2Chara.speed = 3.0f * 60;
	Data.enemy_2Chara.offsetLeft = 4.0f;//仮
	Data.enemy_2Chara.offsetRight = 124.0f;//仮
	Data.enemy_2Chara.offsetTop = 4.0f;//仮
	Data.enemy_2Chara.offsetBottom = 124.0f;//仮
	Data.enemy_2.rightAnimId = 0;
	Data.enemy_2.leftAnimId = 1;
	Data.enemy_2.upAnimId = 2;
	Data.enemy_2.downAnimId = 3;
	Data.enemy_2.bulletOffsetX = 128.0f;
	Data.enemy_2.bulletOffsetY = 128.0f;
	Data.enemy_2.sensingOffset = 15.0f;
	Data.enemy_2.waitingTime = 0;
	Data.enemy_2.waitingInterval= 40 * 0.016f;
	Data.enemy_2.dontLaunchTime = 0;
	Data.enemy_2.dontLaunchInterval = 40 * 0.016f;
	Data.enemy_2.bulletCharaId = MAP::ENEMY_2_BULLET_ID;

	Data.enemy_2BulletChara.charaId = MAP::ENEMY_2_BULLET_ID;
	Data.enemy_2BulletChara.groupId = 4;//敵バレットグループは2
	Data.enemy_2BulletChara.hp = 1;
	Data.enemy_2BulletChara.speed = 6.7f * 60;//仮
	Data.enemy_2BulletChara.offsetLeft = 0.0f;//仮
	Data.enemy_2BulletChara.offsetTop = 0.0f;//仮
	Data.enemy_2BulletChara.offsetRight = 30.0f;//仮
	Data.enemy_2BulletChara.offsetBottom = 30.0f;//仮


	Data.charaMng.numPlayers = 1;
	Data.charaMng.numPlayerBullets = 3;
	Data.charaMng.numEnemies_1 = 3;
	Data.charaMng.numEnemies_2 = 3;
	Data.charaMng.numEnemies_2Bullets = 20;

	Data.hitpoint.px = 0;
	Data.hitpoint.py = 0;
	Data.hitpoint.offSetPx = 64;
	Data.hitpoint.numHitPointContainer = 3;

}

void CONTAINER::LoadGraphics()
{

	Data.map.backImg = loadImage("assets\\zentaimap.png");
	Data.map.treeImg = loadImage("assets\\tree.png");

	Data.hitpoint.fullImg = loadImage("assets\\fullheart.png");
	Data.hitpoint.halfImg = loadImage("assets\\halfheart.png");
	Data.hitpoint.emptyImg = loadImage("assets\\emptyheart.png");
}

