#include "CONTAINER.h"

void CONTAINER::load()
{
	setData();
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
}
