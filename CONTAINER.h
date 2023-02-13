#pragma once
#include"TITLE.h"
#include"STAGE.h"
#include"MAP.h"
#include"PLAYER.h"
#include"ENEMY_1.h"
#include"ENEMY_2.h"
#include"CHARACTER_MANAGER.h"
#include"HIT_POINT.h"
class CONTAINER
{
	struct DATA {
		TITLE::DATA title;
		STAGE::DATA stage;
		MAP::DATA map;
		CHARACTER::DATA playerChara;
		PLAYER::DATA player;
		CHARACTER::DATA playerBulletChara;
		CHARACTER::DATA enemy_1Chara;
		ENEMY_1::DATA enemy_1;
		CHARACTER::DATA enemy_2Chara;
		ENEMY_2::DATA enemy_2;
		CHARACTER::DATA enemy_2BulletChara;
		CHARACTER_MANAGER::DATA charaMng;
		HIT_POINT::DATA hitpoint;
	};
	DATA Data;
public:
	void load();
	void setData();//privateにしても大丈夫か？
	void LoadGraphics();//privateにしても大丈夫か？
	const DATA& data() { return Data; }
};

