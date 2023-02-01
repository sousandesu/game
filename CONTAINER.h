#pragma once
#include"TITLE.h"
class CONTAINER
{
	struct DATA {
		TITLE::DATA title;
	};
	DATA Data;
public:
	void load();
	void setData();
	const DATA& data() { return Data; }
};

