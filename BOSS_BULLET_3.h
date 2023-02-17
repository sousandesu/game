#pragma once
#include "CHARACTER.h"
class BOSS_BULLET_3 :
    public CHARACTER
{
public:
    struct DATA {
        float theta = 0;
        float numAddtheta = 0;
        float RolingCoef = 0;
    };
private:
    DATA Boss_bullet_3;
public:
    BOSS_BULLET_3(class GAME* game) :CHARACTER(game) {}
    void create();
    void appear(float wx, float wy, float vx, float vy);
    void update();
};

