#pragma once
#include "CHARACTER.h"
class BOSS :
    public CHARACTER
{
public:
    struct DATA {
        float curWx = 0;
        float curWy = 0;
        float px = 0;
        float py = 0;
        char bullet1CharaId = 0;
        char bullet2CharaId = 0;
        char bullet3CharaId = 0;
        float differenceX = 0;
        float differenceY = 0;
        float bullet1OffsetX = 0;
        float bullet1OffsetY = 0;
        float bullet2OffsetX = 0;
        float bullet2OffsetY = 0;
        float bullet3OffsetX = 0;
        float bullet3OffsetY = 0;
        float bulletToCenterPlayerOffsetX = 0;
        float bulletToCenterPlayerOffsetY = 0;
        float bulletCenterOffsetX = 0;
        float bulletCenterOffsetY = 0;
        float threeWayangle = 0;
        int direction = 0;
        float waitingTime = 0;
        float waitingInterval1 = 0;
        float waitingInterval2 = 0;
        float waitingInterval3 = 0;
        float dontLaunchTime = 0;
        float dontLaunchInterval = 0;
        int nextLaunchPattern = 0;
        int numLaunchBullet = 0;
        float nextLaunchPatternWaitingTime = 0;
        float nextLaunchPatternWaitingInterval = 0;
        int numNextLaunchBullet1 = 0;
        int numNextLaunchBullet2 = 0;
        int numNextLaunchBullet3 = 0;


        bool moveFlag = false;
        bool launchFlag = false;
    };
private:
    DATA Boss;
public:
    BOSS(class GAME* game) :CHARACTER(game) {}
    void create();
    void init();
    void appear(float wx, float wy, float vx, float vy);
    void update();
    void damage();
    void normalize(float* ovx, float* ovy, float ivx, float ivy);


private:
    void Move();
    void randomMove();
    void Launch();
    void LaunchPattern1();
    void LaunchPattern2();
    void LaunchPattern3();
    void CollisionWithMap();
    void draw();
};

