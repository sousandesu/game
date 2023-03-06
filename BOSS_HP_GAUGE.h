#pragma once
#include "GAME_OBJECT.h"
class BOSS_HP_GAUGE :
    public GAME_OBJECT
{
public:
    struct DATA {
        int fullImg = 0;
        int ninetyImg = 0;
        int eightyImg = 0;
        int seventyImg = 0;
        int sixtyImg = 0;
        int fiftyImg = 0;
        int fortyImg = 0;
        int thirtyImg = 0;
        int twentyImg = 0;
        int tenImg = 0;
        int emptyImg = 0;
        COLOR color;
        int maxHp = 0;
        float px = 0;
        float py = 0;
        char bossCharaId = 0;
    };
private:
    DATA Boss_Hp_Gauge;
public:
    BOSS_HP_GAUGE(class GAME* game);
    ~BOSS_HP_GAUGE();
    void create();
    void init();
    void draw();
};

