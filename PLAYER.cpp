#include"CONTAINER.h"
#include"GAME.h"
#include"MAP.h"
#include "PLAYER.h"
#include<math.h>
void PLAYER::create()
{
    Chara = game()->container()->data().playerChara;
    Player = game()->container()->data().player;
}

void PLAYER::init()
{
    Chara.hp = 0;
    Player.invincibleTime = 0;
    Player.powerupFlag = false;
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
    restoreState();
    Move();
    Launch();
    judgeInvincibleTime();
    //CollisionWithMap(); move�ŃR���W�������Ă�
    CheckState();
}

void PLAYER::Launch()
{
    //�e����
    if (isTrigger(KEY_G)) {
        oneShot();
    }
    if (isPress(KEY_G) && Player.powerupFlag) {
        State = STATE::CHARGE;
        Player.chargeShotTime -= delta;
    }
    if (!isPress(KEY_G) && Player.powerupFlag && Player.chargeShotTime < (-Player.chargeShotInterval) * delta) {
        State = STATE::STRUGGLING;
        chargeShot();
    }
    if (!isPress(KEY_G) && Player.powerupFlag) {
        State = STATE::STRUGGLING;
        Player.chargeShotTime = 0;
    }

}

void PLAYER::oneShot()
{
    float vx = 1.0f;
    float vy = 1.0f;
    float wx = 0.0f;
    float wy = 0.0f;
    if (Chara.animId == Player.rightAnimId) {
        vx = 1.0f;
        vy = 0.0f;
        wx = Chara.wx + Player.bulletOffsetX * vx;
        wy = Chara.wy + Player.bulletOffsetY * vy;
    }
    else if (Chara.animId == Player.leftAnimId) {
        vx = -1.0f;
        vy = 0.0f;
        wx = Chara.wx;
        wy = Chara.wy + Player.bulletOffsetY * vy;
    }
    else if (Chara.animId == Player.upAnimId) {
        vx = 0.0f;
        vy = -1.0f;
        wx = Chara.wx + Player.bulletOffsetX * vx;
        wy = Chara.wy;
    }
    else if (Chara.animId == Player.downAnimId) {
        vx = 0.0f;
        vy = 1.0f;
        wx = Chara.wx + Player.bulletOffsetX * vx;
        wy = Chara.wy + Player.bulletOffsetY * vy;
    }
    game()->characterManager()->appear(Player.bulletCharaId, wx, wy, vx, vy);
}

void PLAYER::chargeShot()
{
    float vx = 1.0f;
    float vy = 1.0f;
    float wx = 0.0f;
    float wy = 0.0f;
    if (Chara.animId == Player.rightAnimId) {
        vx = 1.0f;
        vy = 0.0f;
        wx = Chara.wx + Player.bulletOffsetX * vx;
        wy = Chara.wy + Player.bulletOffsetY * vy;
    }
    else if (Chara.animId == Player.leftAnimId) {
        vx = -1.0f;
        vy = 0.0f;
        wx = Chara.wx;
        wy = Chara.wy + Player.bulletOffsetY * vy;
    }
    else if (Chara.animId == Player.upAnimId) {
        vx = 0.0f;
        vy = -1.0f;
        wx = Chara.wx + Player.bulletOffsetX * vx;
        wy = Chara.wy;
    }
    else if (Chara.animId == Player.downAnimId) {
        vx = 0.0f;
        vy = 1.0f;
        wx = Chara.wx + Player.bulletOffsetX * vx;
        wy = Chara.wy + Player.bulletOffsetY * vy;
    }
    game()->characterManager()->appear(Player.bullet2CharaId, wx, wy, vx, vy);
}


void PLAYER::Move()
{

    //���E�㉺�ړ�
    //�ړ��x�N�g��������
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
        normalize(&Chara.vx, &Chara.vy, Chara.vx, Chara.vy);
        Chara.wx += Chara.vx * Chara.speed * delta;
        CollisionWithWidthMap();
        Chara.wy += Chara.vy * Chara.speed * delta;
        CollisionWithHeightMap();
    }
    //else {//���E�㉺�L�[���͂��Ȃ��Ƃ�
    //    Chara.animData.imgIdx = 0;
    //    Chara.animData.elapsedTime = -delta;
    //}ANIMclass���ł�������
}

/*void PLAYER::CollisionWithMap()
{
    MAP* map = game()->map();
    
    // �}�b�v�`�b�v�ƃL�����̉E
    if (map->collisionCharaRight(wLeft(), wTop(), wRight(), wBottom())) {
        //�ړ��\��ʒu���}�b�v�ɐH������ł���̂Ō��݂̈ʒu�ɖ߂�
        Chara.wx = Player.curWx;
    }
    // �}�b�v�`�b�v�ƃL�����̍�
    else if (map->collisionCharaLeft(wLeft(), wTop(), wRight(), wBottom())) {
        Chara.wx = Player.curWx;
    }
    // �}�b�v�`�b�v�ƃL�����̏�
    if (map->collisionCharaTop(wLeft(), wTop(), wRight(), wBottom())) {
        Chara.wy = Player.curWy;
    }
    // �}�b�v�`�b�v�ƃL�����̉�
    else if (map->collisionCharaBottom(wLeft(), wTop(), wRight(), wBottom())) {
        Chara.wy = Player.curWy;
    }
}*/

void PLAYER::CollisionWithWidthMap()
{
    MAP* map = game()->map();

    // �}�b�v�`�b�v�ƃL�����̉E
    if (map->collisionCharaRight(wLeft(), wTop(), wRight(), wBottom())) {
        //�ړ��\��ʒu���}�b�v�ɐH������ł���̂Ō��݂̈ʒu�ɖ߂�
        Chara.wx = Player.curWx;
    }
    // �}�b�v�`�b�v�ƃL�����̍�
    else if (map->collisionCharaLeft(wLeft(), wTop(), wRight(), wBottom())) {
        Chara.wx = Player.curWx;
    }
}

void PLAYER::CollisionWithHeightMap()
{
    MAP* map = game()->map();

    // �}�b�v�`�b�v�ƃL�����̏�
    if (map->collisionCharaTop(wLeft(), wTop(), wRight(), wBottom())) {
        Chara.wy = Player.curWy;
    }
    // �}�b�v�`�b�v�ƃL�����̉�
    else if (map->collisionCharaBottom(wLeft(), wTop(), wRight(), wBottom())) {
        Chara.wy = Player.curWy;
    }
}

void PLAYER::CheckState()
{
    //���L�q
}

void PLAYER::draw()
{
    Player.px = Chara.wx - game()->map()->wx();
    Player.py = Chara.wy - game()->map()->wy();
    if (State == STATE::INVINCIBLE) {
        static int i = 0;
        i++;
        if (i / 3 % 2 == 0) {
            imageColor(Player.invincibleColor);
        }
        else {
            imageColor(Chara.color);
        }
        if (i == 6) {
            i = 0;
        }
    }
    else if (State == STATE::CHARGE) {
        static int i = 0;
        i++;
        if (i / 3 % 2 == 0) {
            imageColor(Player.chargeColor);
        }
        else {
            imageColor(Chara.color);
        }
        if (i == 6) {
            i = 0;
        }
    }
    else if (State == STATE::STRUGGLING) {
        imageColor(Chara.color);
    }
    if (Chara.animId == Player.rightAnimId) {
        image(Player.rightImg, Player.px, Player.py);
    }
    else if (Chara.animId == Player.leftAnimId) {
        image(Player.leftImg, Player.px, Player.py);
    }
    else if (Chara.animId == Player.upAnimId) {
        image(Player.upImg, Player.px, Player.py);
    }
    else if (Chara.animId == Player.downAnimId) {
        image(Player.downImg, Player.px, Player.py);
    }
}

void PLAYER::damage()
{
    if (Chara.hp > 0 && Player.invincibleTime <= 0) {
        Player.invincibleTime = Player.invincibleInterval * delta;
        Chara.hp--;
        if (Chara.hp == 0) {
            State = STATE::DIED;
        }
    }
}

void PLAYER::judgeInvincibleTime()
{
    if (Player.invincibleTime > 0) {
        State = STATE::INVINCIBLE;
        Player.invincibleTime -= delta;
    }
}

void PLAYER::restoreState()
{
    State = STATE::STRUGGLING;
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

void PLAYER::normalize(float* ovx, float* ovy, float ivx, float ivy) {
    float l = sqrtf(ivx * ivx + ivy * ivy);
    if (l != 0.0f) {
        *ovx = ivx / l;
        *ovy = ivy / l;
    }
    else {
        *ovx = ivx;
        *ovy = ivy;
    }
}

void PLAYER::healingHp() 
{
    if (Chara.hp < Player.Maxhp) Chara.hp++;
}

void PLAYER::powerup()
{
    Player.powerupFlag = true;
}
