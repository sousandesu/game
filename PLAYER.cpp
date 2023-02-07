#include"CONTAINER.h"
#include"GAME.h"
#include"MAP.h"
#include "PLAYER.h"
void PLAYER::create()
{
    Chara = game()->container()->data().playerChara;
    Player = game()->container()->data().player;
}

void PLAYER::appear(float wx, float wy, float vx, float vy)
{
    Chara.hp = game()->container()->data().playerChara.hp;
    Chara.wx = wx;
    Chara.wy = wy;
    Chara.animId = Player.rightAnimId;
    State = STATE::STRUGGLING;
}

void PLAYER::update() 
{
    Launch();
    Move();
    CollisionWithMap();
    CheckState();
}

void PLAYER::Launch()
{
    //未記述
}

void PLAYER::Move()
{
    //左右上下移動
    //　移動ベクトルを決定
    Chara.vx = 0.0f;
    Chara.vy = 0.0f;
    if (isPress(KEY_A)) {
        Chara.vx = -Chara.speed * delta;
        Chara.animId = Player.leftAnimId;
    }
    if (isPress(KEY_D)) {
        Chara.vx = Chara.speed * delta;
        Chara.animId = Player.rightAnimId;
    }
    if (isPress(KEY_W)) {
        Chara.vy = -Chara.speed * delta;
        Chara.animId = Player.upAnimId;
    }
    if (isPress(KEY_S)) {
        Chara.vy = Chara.speed * delta;
        Chara.animId = Player.downAnimId;
    }
    //  移動前に現在のChara.wxをPlayer.curWxにとっておく
    Player.curWx = Chara.wx;
    //  移動前に現在のChara.wyをPlayer.curWyにとっておく
    Player.curWy = Chara.wy;
    //  移動
    if (Chara.vx != 0.0f || Chara.vy != 0.0f) {//左右上下キー入力あり
        //とりあえず「次に移動する予定」の位置としてChara.wxを更新しておき
        //あとで、マップに食い込んでいたら、元のPlayer.curWxに戻す
        Chara.wx += Chara.vx;
        Chara.wy += Chara.vy;
    }
    //else {//左右上下キー入力がないとき
    //    Chara.animData.imgIdx = 0;
    //    Chara.animData.elapsedTime = -delta;
    //}ANIMclassができたらやる
}

void PLAYER::CollisionWithMap()
{
    //未記述
}

void PLAYER::CheckState()
{
    //未記述
}

void PLAYER::draw()
{
    float px = Chara.wx - game()->map()->wx();
    float py = Chara.wy - game()->map()->wy();
    fill(255, 0, 0);
    rect(px, py,128,128);
}

void PLAYER::damage()
{
    if (Chara.hp > 0) {
        Chara.hp--;
        if (Chara.hp == 0) {
            State = STATE::DIED;
        }
    }
}

bool PLAYER::died()
{
    if (State == STATE::DIED) {
        return true;
    }
    return false;
}

bool PLAYER::survived()
{
    return State == STATE::SURVIVED;
}

float PLAYER::overCenterVx()
{
    //マップをスクロールさせるためのベクトルを求める
    float centerWx = (game()->map()->wx() + width / 2 - game()->map()->chipSize() / 2);
    float overCenterVx = Chara.wx - centerWx;
    if (Chara.hp == 0)overCenterVx = 0;
    return overCenterVx;
}

float PLAYER::overCenterVy()
{
    //マップをスクロールさせるためのベクトルを求める
    float centerWy = (game()->map()->wy() + height / 2 - game()->map()->chipSize() / 2);
    float overCenterVy = Chara.wy - centerWy;
    if (Chara.hp == 0)overCenterVy = 0;
    return overCenterVy;
}

