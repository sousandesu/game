#include"CONTAINER.h"
#include"GAME.h"
#include"MAP.h"
#include "PLAYER_BULLET.h"

void PLAYER_BULLET::create()
{
	Chara = game()->container()->data().playerBulletChara;
    PlayerBullet = game()->container()->data().playerBullet;
}

void PLAYER_BULLET::appear(float wx, float wy, float vx, float vy)
{
    Chara.hp = game()->container()->data().playerBulletChara.hp;
    Chara.wx = wx;
    Chara.wy = wy;
    Chara.vx = vx;
    Chara.vy = vy;
}

void PLAYER_BULLET::update()
{
    //移動--------------------------------------------------------------------------
    Chara.wx += Chara.vx * (Chara.speed * delta);
    Chara.wy += Chara.vy * (Chara.speed * delta);

    if (Chara.vx == 1.0f && Chara.vy == 0.0f) {
        Chara.animId = PlayerBullet.rightId;
    }
    else if (Chara.vx == -1.0f && Chara.vy == 0.0f) {
        Chara.animId = PlayerBullet.leftId;
    }
    else if (Chara.vx == 0.0f && Chara.vy == -1.0f) {
        Chara.animId = PlayerBullet.upId;
    }
    else if (Chara.vx == 0.0f && Chara.vy == 1.0f) {
        Chara.animId = PlayerBullet.downId;
    }
    //マップ------------------------------------------------------------------------
    // 弾がウィンドウの外に出た
    if (Chara.wx < game()->map()->wDispLeft() ||
        Chara.wx > game()->map()->wDispRight()||
        Chara.wy <game()->map()->wDispTop()   ||   
        Chara.wy >game()->map()->wDispbottom()) {
        Chara.hp = 0;
    }
}

void PLAYER_BULLET::draw()
{
    float px = Chara.wx - game()->map()->wx();
    float py = Chara.wy - game()->map()->wy();
    imageColor(Chara.color);
    if (Chara.animId == PlayerBullet.rightId) {
        image(PlayerBullet.rightImg, px, py);
    }
    else if (Chara.animId == PlayerBullet.leftId) {
        image(PlayerBullet.leftImg, px, py);
    }
    else if (Chara.animId == PlayerBullet.upId) {
        image(PlayerBullet.upImg, px, py);
    }
    else if (Chara.animId == PlayerBullet.downId) {
        image(PlayerBullet.downImg, px, py);
    }

}
