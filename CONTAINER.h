#pragma once
#include"TITLE.h"
#include"MAP.h"
#include"PLAYER.h"
#include"CHARACTER_MANAGER.h"
#include"HIT_POINT.h"
class CONTAINER
{
	struct DATA {
		TITLE::DATA title;
		MAP::DATA map;
		CHARACTER::DATA playerChara;
		PLAYER::DATA player;
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

