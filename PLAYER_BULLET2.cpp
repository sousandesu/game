#include"CONTAINER.h"
#include"GAME.h"
#include"MAP.h"
#include "PLAYER_BULLET2.h"

void PLAYER_BULLET2::create()
{
	Chara = game()->container()->data().playerBullet2Chara;
    PlayerBullet2 = game()->container()->data().playerBullet2;
}

void PLAYER_BULLET2::appear(float wx, float wy, float vx, float vy)
{
    Chara.hp = game()->container()->data().playerBullet2Chara.hp;
    Chara.wx = wx;
    Chara.wy = wy;
    Chara.vx = vx;
    Chara.vy = vy;
}

void PLAYER_BULLET2::update()
{
    //移動--------------------------------------------------------------------------
    Chara.wx += Chara.vx * (Chara.speed * delta);
    Chara.wy += Chara.vy * (Chara.speed * delta);

    if (Chara.vx == 1.0f && Chara.vy == 0.0f) {
        Chara.animId = PlayerBullet2.rightId;
    }
    else if (Chara.vx == -1.0f && Chara.vy == 0.0f) {
        Chara.animId = PlayerBullet2.leftId;
    }
    else if (Chara.vx == 0.0f && Chara.vy == -1.0f) {
        Chara.animId = PlayerBullet2.upId;
    }
    else if (Chara.vx == 0.0f && Chara.vy == 1.0f) {
        Chara.animId = PlayerBullet2.downId;
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

void PLAYER_BULLET2::draw()
{
    float px = Chara.wx - game()->map()->wx();
    float py = Chara.wy - game()->map()->wy();
    imageColor(Chara.color);
    if (Chara.animId == PlayerBullet2.rightId) {
        image(PlayerBullet2.rightImg, px, py, 0, 2);
    }
    else if (Chara.animId == PlayerBullet2.leftId) {
        image(PlayerBullet2.leftImg, px, py, 0, 2);
    }
    else if (Chara.animId == PlayerBullet2.upId) {
        image(PlayerBullet2.upImg, px, py, 0, 2);
    }
    else if (Chara.animId == PlayerBullet2.downId) {
        image(PlayerBullet2.downImg, px, py, 0, 2);
    }
}
