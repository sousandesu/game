#pragma once
#include"TITLE.h"
#include"MAP.h"
class CONTAINER
{
	struct DATA {
		TITLE::DATA title;
		MAP::DATA map;
	};
	DATA Data;
public:
	void load();
	void setData();
	const DATA& data() { return Data; }
};

