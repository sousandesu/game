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
        int chipSize = 0; //正方形マップチップ画像の一辺のドット数
        char* data = 0; //データ配列のポインタ
        int cols = 0; //データの列数
        int rows = 0; //データの行数
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
    //マップチップとキャラの当たり判定に使用する関数群---------------------------------------
    bool collisionCheck(float wx, float wy);//下の当たり判定関数群から呼び出して使う関数
    bool collisionCharaLeft(float wLeft, float wTop, float wRight, float wBottom);
    bool collisionCharaRight(float wLeft, float wTop, float wRight, float wBottom);
    bool collisionCharaTop(float wLeft, float wTop, float wRight, float wBottom);
    bool collisionCharaBottom(float wLeft, float wTop, float wRight, float wBottom);
    // 今のところ弾は地形貫通するようにするbool collisionCharaRect(float wLeft, float wTop, float wRight, float wBottom);//弾用

    //ウィンドウ枠からのはみだし判定用---------------------------------------------------
    float wDispLeft();
    float wDispRight();
    float wDispTop();
    float wDispbottom();
};

