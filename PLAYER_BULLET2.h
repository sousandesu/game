#pragma once
#include "CHARACTER.h"
class PLAYER_BULLET2 :
    public CHARACTER
{
public:
    PLAYER_BULLET2(class GAME* game) :CHARACTER(game) {}
    void create();
    void appear(float wx, float wy, float vx, float vy);
    void update();
    void draw();
};

