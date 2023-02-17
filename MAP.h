#pragma once
#include "GAME_OBJECT.h"
class MAP :
    public GAME_OBJECT
{
public:
    struct DATA {
        const char* fileName = 0;
        const char* backFileName = 0;
        int backImg = 0;
        int treeImg = 0;
        int chipSize = 0; //�����`�}�b�v�`�b�v�摜�̈�ӂ̃h�b�g��
        int backwidth = 0;//9600
        int backheight = 0;//4320
        char* data = 0; //�f�[�^�z��̃|�C���^
        char* backdata = 0;
        int cols = 0; //�f�[�^�̗�
        int rows = 0; //�f�[�^�̍s��
        int backcols = 0;
        int backrows = 0;
        int dispCols = 0;
        int dispRows = 0;
        int backDispCols = 0;
        float wx = 0;//world position x
        float wy = 0;//world position y
        float worldWidth = 0;
        float worldHeight = 0;
        float startWorldX = 0;
        float startWorldY = 0;
        float endWorldX = 0;
        float endWorldY = 0;
        float centerX = 0;
        float centerY = 0;
    };
    enum CHARA_ID {
        PLAYER_ID = 'a',
        PLAYER_BULLET_ID = 'b',
        ENEMY_1_ID = 'c',
        ENEMY_2_ID = 'd',
        ENEMY_2_BULLET_ID = 'e',
        BOSS_ID = 'f',
        BOSS_BULLET_1_ID = 'g',
        BOSS_BULLET_2_ID = 'h',
        BOSS_BULLET_3_ID = 'i',
        HEALINGPORTION_ID = 'j',
        POWERUP_ITEM_ID = 'k',
        PLAYER_BULLET2_ID = 'l',
    };
private:
    DATA Map;
public:
    MAP(class GAME* game);
    ~MAP();
    void create();
    void init();
    void backmapinit();
    void update();
    void draw();
    void backmapdraw();
    float wx() { return Map.wx; }
    float wy() { return Map.wy; }
    int chipSize() { return Map.chipSize; }
    //�}�b�v�`�b�v�ƃL�����̓����蔻��Ɏg�p����֐��Q---------------------------------------
    bool collisionCheck(float wx, float wy);//���̓����蔻��֐��Q����Ăяo���Ďg���֐�
    bool collisionCharaLeft(float wLeft, float wTop, float wRight, float wBottom);
    bool collisionCharaRight(float wLeft, float wTop, float wRight, float wBottom);
    bool collisionCharaTop(float wLeft, float wTop, float wRight, float wBottom);
    bool collisionCharaBottom(float wLeft, float wTop, float wRight, float wBottom);
    // ���̂Ƃ���e�͒n�`�ђʂ���悤�ɂ���bool collisionCharaRect(float wLeft, float wTop, float wRight, float wBottom);//�e�p

    //�E�B���h�E�g����݂̂͂�������p---------------------------------------------------
    float wDispLeft();
    float wDispRight();
    float wDispTop();
    float wDispbottom();
};

