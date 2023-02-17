#pragma once
#include "CHARACTER.h"
class ENEMY_2 :
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

        float curWx = 0;
        float curWy = 0;
        float px = 0;
        float py = 0;
        char bulletCharaId = 0;
        float differenceX = 0;
        float differenceY = 0;
        float bulletOffsetX = 0;
        float bulletOffsetY = 0;
        float sensingOffset = 0;
        int direction = 0;
        float waitingTime = 0;
        float waitingInterval = 0;
        float dontLaunchTime = 0;
        float dontLaunchInterval = 0;
        bool moveFlag = false;
        bool launchFlag = false;
    };
private:
    DATA Enemy_2;
public:
    ENEMY_2(class GAME* game) :CHARACTER(game) {}
    void create();
    void init();
    void appear(float wx, float wy, float vx, float vy);
    void update();
    void damage();
private:
    void Move();
    void randomMove();
    void Launch();
    void CollisionWithMap();
    void draw();
    void appearPortion();
};

