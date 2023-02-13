#include"CONTAINER.h"
#include"GAME.h"
#include"MAP.h"
#include "ENEMY_2_BULLET.h"

void ENEMY_2_BULLET::create()
{
	Chara = game()->container()->data().enemy_2BulletChara;
}

void ENEMY_2_BULLET::appear(float wx, float wy, float vx, float vy)
{
    Chara.hp = game()->container()->data().enemy_2BulletChara.hp;
    Chara.wx = wx;
    Chara.wy = wy;
    Chara.vx = vx;
    Chara.vy = vy;
}

void ENEMY_2_BULLET::update()
{
    //移動--------------------------------------------------------------------------
    Chara.wx += Chara.vx * (Chara.speed * delta);
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

void ENEMY_2_BULLET::draw()
{
    float px = Chara.wx - game()->map()->wx();
    float py = Chara.wy - game()->map()->wy();
    rect(px, py, 64, 64);
}