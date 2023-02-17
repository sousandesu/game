#pragma once
#include "CHARACTER.h"
class PLAYER_BULLET :
    public CHARACTER
{
public:
    struct DATA {
        int rightImg = 0;
        int leftImg = 0;
        int upImg = 0;
        int downImg = 0;
        int rightId = 0;
        int leftId = 1;
        int upId = 2;
        int downId = 3;
    };
private:
    DATA PlayerBullet;
public:
    PLAYER_BULLET(class GAME* game) :CHARACTER(game) {}
    void create();
    void appear(float wx, float wy, float vx, float vy);
    void update();
    void draw();
};

