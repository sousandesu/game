#pragma once
#include "GAME_OBJECT.h"
class CHARACTER_MANAGER :
    public GAME_OBJECT
{
public:
    struct DATA {
        int numPlayers = 0;
        int numPlayerBullets = 0;
        int numPlayerBullets2 = 0;
        int numEnemies_1 = 0;
        int numEnemies_2 = 0;
        int numEnemies_2Bullets = 0;
        int numBosses = 0;
        int numBossesBullets_1 = 0;
        int numBossesBullets_2 = 0;
        int numBossesBullets_3 = 0;
        int numHealingPortions = 0;
        int numPowerupItems = 0;
    };
private:
    int Total = 0;
    DATA CharaMng;
    class CHARACTER** Characters = nullptr;
    class PLAYER* Player = nullptr;
    class HEALINGPORTION* Healingportion = nullptr;
public:
    CHARACTER_MANAGER(class GAME* game);
    ~CHARACTER_MANAGER();
    void create();
    void init();
    void appear(char charaId, float wx, float wy, float vx = 0, float vy = 0);
    void update();
    void draw();
    class PLAYER* player() { return Player; }
    class HEALINGPORTION* healingportion() { return Healingportion; }
};

