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
	Data.playerChara.hp = 3;
	Data.playerChara.groupId = 0;//ñ°ï˚ÉOÉãÅ[ÉvÇÕ0
	Data.playerChara.speed = 3.4f * 60;
	Data.playerChara.offsetLeft = 10.0f;//âº
	Data.playerChara.offsetTop = 1.0f;//âº
	Data.playerChara.offsetRight = 40.0f;//âº
	Data.playerChara.offsetBottom = 49.0f;//âº
	Data.player.rightAnimId = 0;
	Data.player.leftAnimId = 1;
	Data.player.upAnimId = 2;
	Data.player.downAnimId = 3;
	Data.player.bulletOffsetX = 20.0f;//âº
	Data.player.bulletOffsetY = 20.0f;//âº
	Data.player.bulletCharaId = MAP::PLAYER_BULLET_ID;

	Data.charaMng.numPlayers = 1;
	Data.charaMng.numPlayerBullets = 0;

	Data.hitpoint.px = 0;
	Data.hitpoint.py = 0;
	Data.hitpoint.offSetPx = 64;
	Data.hitpoint.numHitPointContainer = 3;

}

void CONTAINER::LoadGraphics()
{
	Data.map.treeImg = loadImage("assets\\tree.png");

	Data.hitpoint.fullImg = loadImage("assets\\fullheart.png");
	Data.hitpoint.halfImg = loadImage("assets\\halfheart.png");
	Data.hitpoint.emptyImg = loadImage("assets\\emptyheart.png");
}

