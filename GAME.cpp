#include"libOne.h"
#include"TITLE.h"
#include"STAGE.h"
#include"GAME_CLEAR.h"
#include"GAME_OVER.h"
#include"CONTAINER.h"
#include "GAME.h"
GAME::GAME()
{
	Container = new CONTAINER;
	Scenes[TITLE_ID] = new TITLE(this);
	Scenes[STAGE_ID] = new STAGE(this);
	Scenes[GAME_CLEAR_ID] = new GAME_CLEAR(this);
	Scenes[GAME_OVER_ID] = new GAME_OVER(this);
	CurSceneId = TITLE_ID;
}

GAME::~GAME()
{
	for (int i = 0; i < NUM_SCENES; i++) {
		delete Scenes[i];
	}
}

void GAME::run()
{
	window(1920, 1080,full);

	Container->load();
	Scenes[TITLE_ID]->create();

	while (notQuit)
	{
		Scenes[CurSceneId]->proc();
	}
}

void GAME::changeScene(SCENE_ID sceneId) {
	CurSceneId = sceneId;
}
