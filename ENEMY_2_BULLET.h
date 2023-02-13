#pragma once
#include "CHARACTER.h"
class ENEMY_2_BULLET :
    public CHARACTER
{
public:
    ENEMY_2_BULLET(class GAME* game) :CHARACTER(game) {}
    void create();
    void appear(float wx, float wy, float vx, float vy);
    void update();
    void draw();
};

