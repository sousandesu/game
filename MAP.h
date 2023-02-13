#pragma once
#include "GAME_OBJECT.h"
class MAP :
    public GAME_OBJECT
{
public:
    struct DATA {
        const char* fileName = 0;
        int backImg = 0;
        int treeImg = 0;
        int chipSize = 0; //�����`�}�b�v�`�b�v�摜�̈�ӂ̃h�b�g��
        char* data = 0; //�f�[�^�z��̃|�C���^
        int cols = 0; //�f�[�^�̗�
        int rows = 0; //�f�[�^�̍s��
        int dispCols = 0;
        int dispRows = 0;
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
    };
private:
    DATA Map;
public:
    MAP(class GAME* game);
    ~MAP();
    void create();
    void init();
    void update();
    void draw();
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

