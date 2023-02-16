#pragma once
#include "CHARACTER.h"
class BOSS_BULLET_2 :
    public CHARACTER
{
public:
    BOSS_BULLET_2(class GAME* game) :CHARACTER(game) {}
    void create();
    void appear(float wx, float wy, float vx, float vy);
    void update();
    void draw();
};

