#include"CONTAINER.h"
#include"GAME.h"
#include"MAP.h"
#include "BOSS_BULLET_3.h"
void BOSS_BULLET_3::create()
{
    Chara = game()->container()->data().bossBullet_3Chara;
    Boss_bullet_3 = game()->container()->data().bossBullet_3;
}

void BOSS_BULLET_3::appear(float wx, float wy, float vx, float vy)
{
    Chara.hp = game()->container()->data().bossBullet_3Chara.hp;
    Chara.wx = wx;
    Chara.wy = wy;
    Chara.vx = vx;
    Chara.vy = vy;
}

void BOSS_BULLET_3::update()
{
    Boss_bullet_3.theta += Boss_bullet_3.numAddtheta;
    //移動--------------------------------------------------------------------------
    Chara.wx += Chara.vx * (Chara.speed * delta) + Sin(Boss_bullet_3.theta) * Boss_bullet_3.RolingCoef;
    Chara.wy += Chara.vy * (Chara.speed * delta);

    //マップ------------------------------------------------------------------------
    // 弾がウィンドウの外に出た
    if (Chara.wx < game()->map()->wDispLeft() ||
        Chara.wx > game()->map()->wDispRight() ||
        Chara.wy <game()->map()->wDispTop() ||
        Chara.wy >game()->map()->wDispbottom()) {
        Chara.hp = 0;
    }
}
