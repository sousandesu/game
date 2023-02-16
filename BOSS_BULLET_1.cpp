#include"CONTAINER.h"
#include"GAME.h"
#include"MAP.h"
#include "BOSS_BULLET_1.h"
void BOSS_BULLET_1::create()
{
    Chara = game()->container()->data().bossBullet_1Chara;
}

void BOSS_BULLET_1::appear(float wx, float wy, float vx, float vy)
{
    Chara.hp = game()->container()->data().bossBullet_1Chara.hp;
    Chara.wx = wx;
    Chara.wy = wy;
    Chara.vx = vx;
    Chara.vy = vy;
}

void BOSS_BULLET_1::update()
{
    //�ړ�--------------------------------------------------------------------------
    Chara.wx += Chara.vx * (Chara.speed * delta);
    Chara.wy += Chara.vy * (Chara.speed * delta);

    //�}�b�v------------------------------------------------------------------------
    // �e���E�B���h�E�̊O�ɏo��
    if (Chara.wx < game()->map()->wDispLeft() ||
        Chara.wx > game()->map()->wDispRight() ||
        Chara.wy <game()->map()->wDispTop() ||
        Chara.wy >game()->map()->wDispbottom()) {
        Chara.hp = 0;
    }
}

void BOSS_BULLET_1::draw()
{
    float px = Chara.wx - game()->map()->wx();
    float py = Chara.wy - game()->map()->wy();
    rect(px, py, 384, 128);
}