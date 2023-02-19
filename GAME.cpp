#include"libOne.h"
#include"TITLE.h"
#include"STAGE.h"
#include"GAME_CLEAR.h"
#include"GAME_OVER.h"
#include"CONTAINER.h"
#include"MAP.h"
#include"HIT_POINT.h"
#include"CHARACTER_MANAGER.h"
#include "GAME.h"
GAME::GAME()
{
	Container = new CONTAINER;
	Scenes[TITLE_ID] = new TITLE(this);
	Scenes[STAGE_ID] = new STAGE(this);
	Scenes[GAME_CLEAR_ID] = new GAME_CLEAR(this);
	Scenes[GAME_OVER_ID] = new GAME_OVER(this);
	CurSceneId = TITLE_ID;

	Map = new MAP(this);
	CharacterManager = new CHARACTER_MANAGER(this);
	HitPoint = new HIT_POINT(this);

}

GAME::~GAME()
{
	delete HitPoint;
	delete CharacterManager;
	delete Map;
	for (int i = 0; i < NUM_SCENES; i++) {
		delete Scenes[i];
	}
}

void GAME::run()
{
	window(1920, 1080,full);

	Container->load();
	Scenes[TITLE_ID]->create();
	Scenes[GAME_OVER_ID]->create();
	Scenes[GAME_CLEAR_ID]->create();
	Map->create();
	CharacterManager->create();
	HitPoint->create();

	CurSceneId = TITLE_ID;
	Scenes[CurSceneId]->init();
	initDeltaTime();

	while (notQuit)
	{
		setDeltaTime();
		Scenes[CurSceneId]->proc();
	}
}

void GAME::changeScene(SCENE_ID sceneId) {
	CurSceneId = sceneId;
	Scenes[CurSceneId]->init();
}
