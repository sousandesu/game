#include"CONTAINER.h"
#include"GAME.h"
#include"MAP.h"
#include "ENEMY_2_BULLET.h"

void ENEMY_2_BULLET::create()
{
	Chara = game()->container()->data().enemy_2BulletChara;
    Enemy_2_Bullet = game()->container()->data().enemy_2Bullet;
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

    if (Chara.vx == 1.0f && Chara.vy == 0.0f) {
        Chara.animId = Enemy_2_Bullet.rightId;
    }
    else if (Chara.vx == -1.0f && Chara.vy == 0.0f) {
        Chara.animId = Enemy_2_Bullet.leftId;
    }
    else if (Chara.vx == 0.0f && Chara.vy == -1.0f) {
        Chara.animId = Enemy_2_Bullet.upId;
    }
    else if (Chara.vx == 0.0f && Chara.vy == 1.0f) {
        Chara.animId = Enemy_2_Bullet.downId;
    }

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
    imageColor(Chara.color);
    if (Chara.animId == Enemy_2_Bullet.rightId) {
        image(Enemy_2_Bullet.rightImg, px, py);
    }
    else if (Chara.animId == Enemy_2_Bullet.leftId) {
        image(Enemy_2_Bullet.leftImg, px, py);
    }
    else if (Chara.animId == Enemy_2_Bullet.upId) {
        image(Enemy_2_Bullet.upImg, px, py);
    }
    else if (Chara.animId == Enemy_2_Bullet.downId) {
        image(Enemy_2_Bullet.downImg, px, py);
    }
    
}