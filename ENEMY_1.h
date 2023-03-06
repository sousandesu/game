#pragma once
#include "CHARACTER.h"
class ENEMY_1 :
    public CHARACTER
{
public:
    struct DATA {
        int rightAnimId = 0;
        int leftAnimId = 1;
        int upAnimId = 2;
        int downAnimId = 3;

        int rightImg = 0;
        int leftImg = 0;
        int upImg = 0;
        int downImg = 0;

        COLOR damegeColor;

        float curWx = 0;
        float curWy = 0;
        float px = 0;
        float py = 0;
        char healingportionId = 0;
        float dashspeed = 0;
        float differenceX = 0;
        float differenceY = 0;
        float sensingOffset = 0;
        int direction = 0;

        float damegeTime = 0;
        float damegeInterval = 0;

        bool moveFlag = false;
        bool dashFlag = false;
        bool damegeFlag = false;
    };
private:
    DATA Enemy_1;
public:
    ENEMY_1(class GAME* game) :CHARACTER(game) {}
    void create();
    void init();
    void appear(float wx, float wy, float vx, float vy);
    void update();
    void damage();
private:
    void Move();
    void randomMove();
    void dashMove();
    void CollisionWithMap();
    void draw();
    void appearPortion();
};