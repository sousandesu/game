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

        int rightImg = 0;
        int leftImg = 0;
        int upImg = 0;
        int downImg = 0;

        COLOR invincibleColor;
        COLOR chargeColor;

        int Maxhp = 0;
        float curWx = 0;
        float curWy = 0;
        float px = 0;
        float py = 0;
        bool powerupFlag = false;
        float chargeShotTime = 0;
        float chargeShotInterval = 0;
        char bulletCharaId = 0;
        char bullet2CharaId = 0;
        float bulletOffsetX = 0;
        float bulletOffsetY = 0;
        float invincibleTime = 0;
        float invincibleInterval = 0;
    };
private:
    DATA Player;
    enum class STATE { STRUGGLING, INVINCIBLE, CHARGE, DIED, SURVIVED };
    STATE State = STATE::STRUGGLING;
public:
    PLAYER(class GAME* game) :CHARACTER(game) {}
    void create();
    void init();
    void appear(float wx, float wy, float vx, float vy);
    void update();
private:
    void Launch();
    void oneShot();
    void chargeShot();
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
    void restoreState();
    bool died();
    bool survived();
    float overCenterVx();
    float overCenterVy();
    int hp() { return Chara.hp; }
    void healingHp();
    void powerup();
    float px() { return Player.px; }
    float py() { return Player.py; }
    bool powerupFlag() { return Player.powerupFlag; }
};

