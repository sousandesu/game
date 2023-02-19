#include "CONTAINER.h"

void CONTAINER::load()
{
	setData();
	LoadGraphics();
}

void CONTAINER::setData()
{
	Data.title.backpx = 0;
	Data.title.backpy = 0;
	Data.title.backColor = COLOR(255, 255, 255, 255);

	Data.game_over.backpx = 0;
	Data.game_over.backpy = 0;
	Data.game_over.backColor = COLOR(255, 255, 255, 255);

	Data.game_clear.backpx = 0;
	Data.game_clear.backpy = 0;
	Data.game_clear.backColor = COLOR(255, 255, 255, 255);

	Data.map.fileName = "assets\\map1.txt";
	Data.map.chipSize = 128;
	Data.map.centerX = width / 2 - Data.map.chipSize / 2;
	Data.map.centerY = height / 2 - Data.map.chipSize / 2;
	Data.map.backFileName = "assets\\mapback1.txt";
	Data.map.backwidth = 9600;
	Data.map.backheight = 4320;
	Data.map.color = COLOR(255, 255, 255, 255);

	Data.playerChara.charaId = MAP::PLAYER_ID;
	Data.playerChara.hp = 6;
	Data.playerChara.groupId = 0;//味方グループは0
	Data.playerChara.speed = 7.2f * 60;
	Data.playerChara.offsetLeft = 4.0f;//仮
	Data.playerChara.offsetTop = 4.0f;//仮
	Data.playerChara.offsetRight = 124.0f;//仮
	Data.playerChara.offsetBottom = 124.0f;//仮
	Data.playerChara.color = COLOR(255, 255, 255, 255);
	Data.player.rightAnimId = 0;
	Data.player.leftAnimId = 1;
	Data.player.upAnimId = 2;
	Data.player.downAnimId = 3;
	Data.player.Maxhp = 6;
	Data.player.bulletOffsetX = 128.0f;//仮
	Data.player.bulletOffsetY = 128.0f;//仮
	Data.player.chargeShotTime = 0;
	Data.player.chargeShotInterval = 75.0f;
	Data.player.invincibleTime = 0;
	Data.player.invincibleInterval = 60.0f;
	Data.player.invincibleColor = COLOR(255, 255, 255, 148);
	Data.player.chargeColor = COLOR(255, 255, 0, 255);
	Data.player.bulletCharaId = MAP::PLAYER_BULLET_ID;
	Data.player.bullet2CharaId = MAP::PLAYER_BULLET2_ID;

	Data.playerBulletChara.charaId = MAP::PLAYER_BULLET_ID;
	Data.playerBulletChara.groupId = 2;//味方バレットグループは2
	Data.playerBulletChara.hp = 1;
	Data.playerBulletChara.speed = 10.7f * 60;//仮
	Data.playerBulletChara.offsetLeft = 0.0f;//仮
	Data.playerBulletChara.offsetTop = 0.0f;//仮
	Data.playerBulletChara.offsetRight = 64.0f;//仮
	Data.playerBulletChara.offsetBottom = 64.0f;//仮
	Data.playerBulletChara.color = COLOR(255, 255, 255, 255);

	Data.playerBullet2Chara.charaId = MAP::PLAYER_BULLET2_ID;
	Data.playerBullet2Chara.groupId = 2;//味方バレットグループは2
	Data.playerBullet2Chara.hp = 6;
	Data.playerBullet2Chara.speed = 12.7f * 60;//仮
	Data.playerBullet2Chara.offsetLeft = 0.0f;//仮
	Data.playerBullet2Chara.offsetTop = 0.0f;//仮
	Data.playerBullet2Chara.offsetRight = 64.0f;//仮
	Data.playerBullet2Chara.offsetBottom = 64.0f;//仮
	Data.playerBullet2Chara.color = COLOR(255, 255, 255, 255);


	Data.enemy_1Chara.charaId = MAP::ENEMY_1_ID;
	Data.enemy_1Chara.groupId = 1;//敵グループは1
	Data.enemy_1Chara.hp = 6;
	Data.enemy_1Chara.speed = 3.0f * 60;
	Data.enemy_1Chara.offsetLeft = 4.0f;//仮
	Data.enemy_1Chara.offsetRight = 124.0f;//仮
	Data.enemy_1Chara.offsetTop = 4.0f;//仮
	Data.enemy_1Chara.offsetBottom = 124.0f;//仮
	Data.enemy_1Chara.color = COLOR(255, 255, 255, 255);
	Data.enemy_1.rightAnimId = 0;
	Data.enemy_1.leftAnimId = 1;
	Data.enemy_1.upAnimId = 2;
	Data.enemy_1.downAnimId = 3;
	Data.enemy_1.dashspeed = 6.0f * 60;
	Data.enemy_1.sensingOffset = 15.0f;

	Data.enemy_2Chara.charaId = MAP::ENEMY_2_ID;
	Data.enemy_2Chara.groupId = 1;//敵グループは1
	Data.enemy_2Chara.hp = 6;
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
	Data.enemy_2BulletChara.speed = 5.7f * 60;//仮
	Data.enemy_2BulletChara.offsetLeft = 0.0f;//仮
	Data.enemy_2BulletChara.offsetTop = 0.0f;//仮
	Data.enemy_2BulletChara.offsetRight = 54.0f;//仮
	Data.enemy_2BulletChara.offsetBottom = 54.0f;//仮

	Data.bossChara.charaId = MAP::BOSS_ID;
	Data.bossChara.hp = 90;
	Data.bossChara.groupId = 1;//敵グループは1
	Data.bossChara.speed = 3.4f * 60;
	Data.bossChara.offsetLeft = 0.0f;//仮
	Data.bossChara.offsetTop = 0.0f;//仮
	Data.bossChara.offsetRight = 384.0f;//仮
	Data.bossChara.offsetBottom = 384.0f;//仮
	Data.bossChara.color = COLOR(255, 255, 255, 255);
	Data.boss.bullet1OffsetX = 0.0f;
	Data.boss.bullet1OffsetY = 374.0f;
	Data.boss.bullet2OffsetX = 192.0f;
	Data.boss.bullet2OffsetY = 192.0f;
	Data.boss.bullet3OffsetX = 192.0f;
	Data.boss.bullet3OffsetY = 192.0f;
	Data.boss.bulletToCenterPlayerOffsetX = 64.0f;
	Data.boss.bulletToCenterPlayerOffsetY = 64.0f;
	Data.boss.bulletCenterOffsetX = 32.0f;
	Data.boss.bulletCenterOffsetY = 162.0f;
	Data.boss.threeWayangle = 0.558505f;
	Data.boss.waitingTime = 0;
	Data.boss.waitingInterval1 = 60.0f;
	Data.boss.waitingInterval2 = 45.0f;
	Data.boss.waitingInterval3 = 75.0f;
	Data.boss.dontLaunchTime = 0;
	Data.boss.dontLaunchInterval = 40.0f;
	Data.boss.numNextLaunchBullet1 = 4;
	Data.boss.numNextLaunchBullet2 = 10;
	Data.boss.numNextLaunchBullet3 = 9;
	Data.boss.nextLaunchPatternWaitingTime = 0.0f;
	Data.boss.nextLaunchPatternWaitingInterval = 40.0f;
	Data.boss.bullet1CharaId = MAP::BOSS_BULLET_1_ID;
	Data.boss.bullet2CharaId = MAP::BOSS_BULLET_2_ID;
	Data.boss.bullet3CharaId = MAP::BOSS_BULLET_3_ID;

	Data.bossBullet_1Chara.charaId = MAP::BOSS_BULLET_1_ID;
	Data.bossBullet_1Chara.groupId = 3;//敵バレットグループは3
	Data.bossBullet_1Chara.hp = 1;
	Data.bossBullet_1Chara.speed = 7.0f * 60;//仮
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
	Data.healingPortionChara.color = COLOR(255, 255, 255, 255);

	Data.powerupItemChara.charaId = MAP::POWERUP_ITEM_ID;
	Data.powerupItemChara.groupId = 4;//アイテムグループは4
	Data.powerupItemChara.hp = 1;
	Data.powerupItemChara.speed = 0.0f * 60;
	Data.powerupItemChara.offsetLeft = 0.0f;
	Data.powerupItemChara.offsetTop = 0.0f;
	Data.powerupItemChara.offsetRight = 128.0f;
	Data.powerupItemChara.offsetBottom = 128.0f;
	Data.powerupItemChara.color = COLOR(255, 255, 255, 255);

	Data.charaMng.numPlayers = 1;
	Data.charaMng.numPlayerBullets = 3;
	Data.charaMng.numPlayerBullets2 = 2;
	Data.charaMng.numEnemies_1 = 13;
	Data.charaMng.numEnemies_2 = 12;
	Data.charaMng.numEnemies_2Bullets = 20;
	Data.charaMng.numBosses = 1;
	Data.charaMng.numBossesBullets_1 = 8;
	Data.charaMng.numBossesBullets_2 = 24;
	Data.charaMng.numBossesBullets_3 = 16;
	Data.charaMng.numHealingPortions = 1;
	Data.charaMng.numPowerupItems = 1;

	Data.hitpoint.px = 0;
	Data.hitpoint.py = 0;
	Data.hitpoint.offSetPx = 128;
	Data.hitpoint.numHitPointContainer = 3;

}

void CONTAINER::LoadGraphics()
{

	Data.title.backImg = loadImage("assets\\title.png");

	Data.game_over.backImg = loadImage("assets\\game_orver.png");

	Data.game_clear.backImg = loadImage("assets\\game_clear.png");

	Data.map.backImg = loadImage("assets\\zentaimap.png");
	Data.map.treeImg = loadImage("assets\\tree.png");

	Data.player.rightImg = loadImage("assets\\player_right.png");
	Data.player.leftImg = loadImage("assets\\player_left.png");
	Data.player.upImg = loadImage("assets\\player_back.png");
	Data.player.downImg = loadImage("assets\\player_front.png");

	Data.playerBullet.rightImg = loadImage("assets\\player_magic_right.png");
	Data.playerBullet.leftImg = loadImage("assets\\player_magic_left.png");
	Data.playerBullet.upImg = loadImage("assets\\player_magic_up.png");
	Data.playerBullet.downImg = loadImage("assets\\player_magic_down.png");

	Data.playerBullet2.rightImg = loadImage("assets\\player_magic_power up_right.png");
	Data.playerBullet2.leftImg = loadImage("assets\\player_magic_power up_left.png");
	Data.playerBullet2.upImg = loadImage("assets\\player_magic_power up_up.png");
	Data.playerBullet2.downImg = loadImage("assets\\player_magic_power up_down.png");

	Data.enemy_1.rightImg = loadImage("assets\\konbo_right.png");
	Data.enemy_1.leftImg = loadImage("assets\\konbo_left.png");
	Data.enemy_1.upImg = loadImage("assets\\konbo_up.png");
	Data.enemy_1.downImg = loadImage("assets\\konbo_down.png");

	Data.enemy_2.rightImg = loadImage("assets\\yumi_right.png");
	Data.enemy_2.leftImg = loadImage("assets\\yumi_left.png");
	Data.enemy_2.upImg = loadImage("assets\\yumi_up.png");
	Data.enemy_2.downImg = loadImage("assets\\yumi_down.png");

	Data.enemy_2Bullet.rightImg = loadImage("assets\\ya_right.png");
	Data.enemy_2Bullet.leftImg = loadImage("assets\\ya_left.png");
	Data.enemy_2Bullet.upImg = loadImage("assets\\ya_up.png");
	Data.enemy_2Bullet.downImg = loadImage("assets\\ya_down.png");

	Data.bossChara.img = loadImage("assets\\boss.png");

	Data.bossBullet_1Chara.img = loadImage("assets\\boss_bullet1.png");

	Data.bossBullet_2Chara.img = loadImage("assets\\boss_bullet2.png");

	Data.bossBullet_3Chara.img = loadImage("assets\\boss_bullet2.png");

	Data.healingPortionChara.img = loadImage("assets\\portion.png");

	Data.powerupItemChara.img = loadImage("assets\\grimoire.png");

	Data.hitpoint.fullImg = loadImage("assets\\fullheart.png");
	Data.hitpoint.halfImg = loadImage("assets\\halfheart.png");
	Data.hitpoint.emptyImg = loadImage("assets\\emptyheart.png");
}
//Data.charaMng.numHealingPortionsが１である理由と後から出てきたポーションが優先されることについて聞く 敵キャラの座標のinit
