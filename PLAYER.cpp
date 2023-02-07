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
    //���L�q
}

void PLAYER::Move()
{
    //���E�㉺�ړ�
    //�@�ړ��x�N�g��������
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
    //  �ړ��O�Ɍ��݂�Chara.wx��Player.curWx�ɂƂ��Ă���
    Player.curWx = Chara.wx;
    //  �ړ��O�Ɍ��݂�Chara.wy��Player.curWy�ɂƂ��Ă���
    Player.curWy = Chara.wy;
    //  �ړ�
    if (Chara.vx != 0.0f || Chara.vy != 0.0f) {//���E�㉺�L�[���͂���
        //�Ƃ肠�����u���Ɉړ�����\��v�̈ʒu�Ƃ���Chara.wx���X�V���Ă���
        //���ƂŁA�}�b�v�ɐH������ł�����A����Player.curWx�ɖ߂�
        Chara.wx += Chara.vx;
        Chara.wy += Chara.vy;
    }
    //else {//���E�㉺�L�[���͂��Ȃ��Ƃ�
    //    Chara.animData.imgIdx = 0;
    //    Chara.animData.elapsedTime = -delta;
    //}ANIMclass���ł�������
}

void PLAYER::CollisionWithMap()
{
    //���L�q
}

void PLAYER::CheckState()
{
    //���L�q
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
    //�}�b�v���X�N���[�������邽�߂̃x�N�g�������߂�
    float centerWx = (game()->map()->wx() + width / 2 - game()->map()->chipSize() / 2);
    float overCenterVx = Chara.wx - centerWx;
    if (Chara.hp == 0)overCenterVx = 0;
    return overCenterVx;
}

float PLAYER::overCenterVy()
{
    //�}�b�v���X�N���[�������邽�߂̃x�N�g�������߂�
    float centerWy = (game()->map()->wy() + height / 2 - game()->map()->chipSize() / 2);
    float overCenterVy = Chara.wy - centerWy;
    if (Chara.hp == 0)overCenterVy = 0;
    return overCenterVy;
}

