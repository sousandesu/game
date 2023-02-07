#pragma once
#include "CHARACTER.h"
class PLAYER :
    public CHARACTER
{
public:
    struct DATA {
        int rightAnimId = 0;
        int leftAnimId = 1;
        int upAnimId = 2;
        int downAnimId = 3;
        float curWx = 0;
        float curWy = 0;
        char bulletCharaId = 0;
        float bulletOffsetX = 0;
        float bulletOffsetY = 0;
    };
private:
    DATA Player;
    enum class STATE { STRUGGLING, DIED, SURVIVED };
    STATE State = STATE::STRUGGLING;
public:
    PLAYER(class GAME* game) :CHARACTER(game) {}
    void create();
    void appear(float wx, float wy, float vx, float vy);
    void update();
private:
    void Launch();
    void Move();
    void CollisionWithMap();
    void CheckState();
public:
    void draw();
    void damage();
    bool died();
    bool survived();
    float overCenterVx();
    float overCenterVy();
    int hp() { return Chara.hp; }
};

