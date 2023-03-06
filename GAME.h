#pragma once
class GAME
{
//�R���e�i
private:
	class CONTAINER* Container = nullptr;
public:
	class CONTAINER* container() { return Container; }
//�V�[��
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
//�L�����N�^
private:
	class MAP* Map = nullptr;
	class CHARACTER_MANAGER* CharacterManager = nullptr;
	class HIT_POINT* HitPoint = nullptr;
	class POWERUP_EXPLANATION* Powerup_Explanation = nullptr;
	class BOSS_HP_GAUGE* Boss_Hp_Gauge = nullptr;
public:
	class MAP* map() { return Map; }
	class CHARACTER_MANAGER* characterManager() { return CharacterManager; }
	class HIT_POINT* hitPoint() { return HitPoint; }
	class POWERUP_EXPLANATION* powerup_Explanation() { return Powerup_Explanation; }
	class BOSS_HP_GAUGE* boss_Hp_Gauge() { return Boss_Hp_Gauge; }
public:
	GAME();
	~GAME();
	void run();
};

