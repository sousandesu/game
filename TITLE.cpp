#include"libOne.h"
#include"CONTAINER.h"
#include"GAME.h"
#include "TITLE.h"
TITLE::TITLE(GAME* game):
	SCENE(game)
{
}

TITLE::~TITLE()
{
}

void TITLE::create()
{
	Title = game()->container()->data().title;
}

void TITLE::draw()
{
	clear();
	printSize(Title.printSize);
	print("Title");
	print("SPACE‚ÅØ‚è‘Ö‚¦");
}

void TITLE::nextScene()
{
	if (isTrigger(KEY_SPACE)) {
		game()->changeScene(GAME::STAGE_ID);
	}
}
