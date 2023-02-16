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
	Data.map.backFileName = "assets\\mapback1.txt";
	Data.map.backwidth = 9600;
	Data.map.backheight = 4320;

	Data.playerChara.charaId = MAP::PLAYER_ID;
	Data.playerChara.hp = 6;
	Data.playerChara.groupId = 0;//味方グループは0
	Data.playerChara.speed = 10.4f * 60;
	Data.playerChara.offsetLeft = 4.0f;//仮
	Data.playerChara.offsetTop = 4.0f;//仮
	Data.playerChara.offsetRight = 124.0f;//仮
	Data.playerChara.offsetBottom = 124.0f;//仮
	Data.player.rightAnimId = 0;
	Data.player.leftAnimId = 1;
	Data.player.upAnimId = 2;
	Data.player.downAnimId = 3;
	Data.player.Maxhp = 6;
	Data.player.bulletOffsetX = 128.0f;//仮
	Data.player.bulletOffsetY = 128.0f;//仮
	Data.player.invincibleTime = 0;
	Data.player.invincibleInterval = 60.0f;
	Data.player.bulletCharaId = MAP::PLAYER_BULLET_ID;

	Data.playerBulletChara.charaId = MAP::PLAYER_BULLET_ID;
	Data.playerBulletChara.groupId = 2;//味方バレットグループは2
	Data.playerBulletChara.hp = 1;
	Data.playerBulletChara.speed = 7.7f * 60;//仮
	Data.playerBulletChara.offsetLeft = 0.0f;//仮
	Data.playerBulletChara.offsetTop = 0.0f;//仮
	Data.playerBulletChara.offsetRight = 64.0f;//仮
	Data.playerBulletChara.offsetBottom = 64.0f;//仮

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
	Data.enemy_2.waitingInterval= 40.0f;
	Data.enemy_2.dontLaunchTime = 0;
	Data.enemy_2.dontLaunchInterval = 40.0f;
	Data.enemy_2.bulletCharaId = MAP::ENEMY_2_BULLET_ID;

	Data.enemy_2BulletChara.charaId = MAP::ENEMY_2_BULLET_ID;
	Data.enemy_2BulletChara.groupId = 3;//敵バレットグループは3
	Data.enemy_2BulletChara.hp = 1;
	Data.enemy_2BulletChara.speed = 6.7f * 60;//仮
	Data.enemy_2BulletChara.offsetLeft = 0.0f;//仮
	Data.enemy_2BulletChara.offsetTop = 0.0f;//仮
	Data.enemy_2BulletChara.offsetRight = 64.0f;//仮
	Data.enemy_2BulletChara.offsetBottom = 64.0f;//仮

	Data.bossChara.charaId = MAP::BOSS_ID;
	Data.bossChara.hp = 10;
	Data.bossChara.groupId = 1;//敵グループは1
	Data.bossChara.speed = 3.4f * 60;
	Data.bossChara.offsetLeft = 0.0f;//仮
	Data.bossChara.offsetTop = 0.0f;//仮
	Data.bossChara.offsetRight = 384.0f;//仮
	Data.bossChara.offsetBottom = 384.0f;//仮
	Data.boss.bullet1OffsetX = 0.0f;
	Data.boss.bullet1OffsetY = 374.0f;
	Data.boss.bullet2OffsetX = 192.0f;
	Data.boss.bullet2OffsetY = 192.0f;
	Data.boss.bullet3OffsetX = 192.0f;
	Data.boss.bullet3OffsetY = 192.0f;
	Data.boss.bulletToCenterPlayerOffsetX = 64.0f;
	Data.boss.bulletToCenterPlayerOffsetY = 64.0f;
	Data.boss.bulletCenterOffsetX = 32.0f;
	Data.boss.bulletCenterOffsetY = 32.0f;
	Data.boss.threeWayangle = 0.610865;
	Data.boss.waitingTime = 0;
	Data.boss.waitingInterval1 = 60.0f;
	Data.boss.waitingInterval2 = 45.0f;
	Data.boss.waitingInterval3 = 75.0f;
	Data.boss.dontLaunchTime = 0;
	Data.boss.dontLaunchInterval = 40.0f;
	Data.boss.numNextLaunchBullet1 = 4;
	Data.boss.numNextLaunchBullet2 = 10;
	Data.boss.numNextLaunchBullet3 = 9;
	Data.boss.bullet1CharaId = MAP::BOSS_BULLET_1_ID;
	Data.boss.bullet2CharaId = MAP::BOSS_BULLET_2_ID;
	Data.boss.bullet3CharaId = MAP::BOSS_BULLET_3_ID;

	Data.bossBullet_1Chara.charaId = MAP::BOSS_BULLET_1_ID;
	Data.bossBullet_1Chara.groupId = 3;//敵バレットグループは3
	Data.bossBullet_1Chara.hp = 1;
	Data.bossBullet_1Chara.speed = 6.7f * 60;//仮
	Data.bossBullet_1Chara.offsetLeft = 0.0f;//仮
	Data.bossBullet_1Chara.offsetTop = 0.0f;//仮
	Data.bossBullet_1Chara.offsetRight = 384.0f;//仮
	Data.bossBullet_1Chara.offsetBottom = 128.0f;//仮

	Data.bossBullet_2Chara.charaId = MAP::BOSS_BULLET_2_ID;
	Data.bossBullet_2Chara.groupId = 3;//敵バレットグループは3
	Data.bossBullet_2Chara.hp = 1;
	Data.bossBullet_2Chara.speed = 6.7f * 60;//仮
	Data.bossBullet_2Chara.offsetLeft = 0.0f;//仮
	Data.bossBullet_2Chara.offsetTop = 0.0f;//仮
	Data.bossBullet_2Chara.offsetRight = 64.0f;//仮
	Data.bossBullet_2Chara.offsetBottom = 64.0f;//仮

	Data.bossBullet_3Chara.charaId = MAP::BOSS_BULLET_3_ID;
	Data.bossBullet_3Chara.groupId = 3;//敵バレットグループは3
	Data.bossBullet_3Chara.hp = 1;
	Data.bossBullet_3Chara.speed = 6.7f * 60;//仮
	Data.bossBullet_3Chara.offsetLeft = 0.0f;//仮
	Data.bossBullet_3Chara.offsetTop = 0.0f;//仮
	Data.bossBullet_3Chara.offsetRight = 64.0f;//仮
	Data.bossBullet_3Chara.offsetBottom = 64.0f;//仮
	Data.bossBullet_3.theta = 0.0f;
	Data.bossBullet_3.numAddtheta = 0.0872665f;
	Data.bossBullet_3.RolingCoef = 10;

	Data.healingPortionChara.charaId = MAP::HEALINGPORTION_ID;
	Data.healingPortionChara.groupId = 4;//アイテムグループは4
	Data.healingPortionChara.hp = 1;
	Data.healingPortionChara.speed = 0.0f * 60;
	Data.healingPortionChara.offsetLeft = 0.0f;
	Data.healingPortionChara.offsetTop = 0.0f;
	Data.healingPortionChara.offsetRight = 128.0f;
	Data.healingPortionChara.offsetBottom = 128.0f;

	Data.charaMng.numPlayers = 1;
	Data.charaMng.numPlayerBullets = 3;
	Data.charaMng.numEnemies_1 = 3;
	Data.charaMng.numEnemies_2 = 3;
	Data.charaMng.numEnemies_2Bullets = 20;
	Data.charaMng.numBosses = 1;
	Data.charaMng.numBossesBullets_1 = 8;
	Data.charaMng.numBossesBullets_2 = 24;
	Data.charaMng.numBossesBullets_3 = 16;
	Data.charaMng.numHealingPortions = 1;

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
//Data.charaMng.numHealingPortionsが１である理由と後から出てきたポーションが優先されることについて聞く 敵キャラの座標のinit
