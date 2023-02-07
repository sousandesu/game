#pragma once
class GAME
{
//コンテナ
private:
	class CONTAINER* Container = nullptr;
public:
	class CONTAINER* container() { return Container; }
//シーン
public:
	enum SCENE_ID {
		TITLE_ID,
		STAGE_ID,
		GAME_CLEAR_ID,
		GAME_OVER_ID,
		NUM_SCENES
	};
private:
	class SCENE* Scenes[NUM_SCENES];
	SCENE_ID CurSceneId;
public:
	void changeScene(SCENE_ID sceneId);
//キャラクタ
private:
	class MAP* Map = nullptr;
	class CHARACTER_MANAGER* CharacterManager = nullptr;
	class HIT_POINT* HitPoint = nullptr;
public:
	class MAP* map() { return Map; }
	class CHARACTER_MANAGER* characterManager() { return CharacterManager; }
	class HIT_POINT* hitPoint() { return HitPoint; }
public:
	GAME();
	~GAME();
	void run();
};

