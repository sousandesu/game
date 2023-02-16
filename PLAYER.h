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
        int Maxhp = 0;
        float curWx = 0;
        float curWy = 0;
        float px = 0;
        float py = 0;
        char bulletCharaId = 0;
        float bulletOffsetX = 0;
        float bulletOffsetY = 0;
        float invincibleTime = 0;
        float invincibleInterval = 0;
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
    //void CollisionWithMap();

    //ï™ÇØÇΩóùóRÇÕï«Ç∏ÇËÇ≈Ç´ÇÈÇÊÇ§Ç…
    void CollisionWithWidthMap();
    void CollisionWithHeightMap();

    void CheckState();

    void normalize(float* ovx, float* ovy, float ivx, float ivy);
    
public:
    void draw();
    void damage();
    void judgeInvincibleTime();
    bool died();
    bool survived();
    float overCenterVx();
    float overCenterVy();
    int hp() { return Chara.hp; }
    void healingHp();
    float px() { return Player.px; }
    float py() { return Player.py; }
};

