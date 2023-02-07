#include"GAME.h"
#include"CONTAINER.h"
#include "MAP.h"
MAP::MAP(class GAME* game) :
    GAME_OBJECT(game) {
}
MAP::~MAP() {
    if (Map.data) { delete[] Map.data; Map.data = 0; }
}
void MAP::create() {
    Map = game()->container()->data().map;
}
void MAP::init() {
    //ファイルを開く
    FILE* fp;
    fopen_s(&fp, Map.fileName, "rb");
    WARNING(fp == 0, "マップデータを読み込めません", Map.fileName);
    //ファイルサイズ取得
    fseek(fp, 0, SEEK_END);
    int fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    //リトライ時、Dataは0でないので開放。
    if (Map.data) { delete[] Map.data; Map.data = 0; }
    //サイズ分のdata配列を用意する
    Map.data = new char[fileSize];
    //データを読み込む
    fread(Map.data, sizeof(char), fileSize, fp);
    fclose(fp);
    //行数、列数を数える（最後の行も必ず改行して終わっていることが条件）
    Map.rows = 0;
    Map.cols = 0;//改行２文字分を含んだ列数になる
    int cnt = 0;
    for (int i = 0; i < fileSize; i++) {
        cnt++;
        //行の最後の文字
        if (Map.data[i] == '\n') {
            if (Map.rows == 0) {
                //最初の行の列数
                Map.cols = cnt;
            }
            else if (Map.cols != cnt) {
                //行ごとの列数が違ったらエラー
                WARNING(1, "列数が不揃い", "");
            }
            //行を数えてカウンタをリセット
            Map.rows++;
            cnt = 0;
        }
    }
    if (fileSize % Map.cols != 0) {
        WARNING(1, "最後の行を改行していない", "");
    }
    Map.dispCols = (int)width / Map.chipSize + 1;//表示すべき列数
    //多分dispRows必要

    Map.worldWidth = (float)Map.chipSize * (Map.cols - 2);//ワールドの横幅
    Map.endWorldX = Map.worldWidth - width;//表示できる最後の座標
    Map.worldHeight = (float)Map.chipSize * (Map.rows);//ワールドの縦幅
    Map.endWorldY = Map.worldHeight - height;//表示できる最後の座標
    Map.wx = 0.0f;//現在表示しているワールド座標
    Map.wy = 0.0f;//現在表示しているワールド座標

}
void MAP::update() {
    //プレイヤーが画面の中央を超えた分だけスクロール
    //左右方向スクロール
    Map.wx += game()->characterManager()->player()->overCenterVx();
    //上下方向スクロール
    Map.wy += game()->characterManager()->player()->overCenterVy();

    
    if (Map.wy > Map.endWorldY) {
        Map.wy = Map.endWorldY;
    }
    if (Map.wx > Map.endWorldX) {
        Map.wx = Map.endWorldX;
    }
    if (Map.wx < Map.startWorldX) {
        Map.wx = Map.startWorldX;
    }
    if (Map.wy < Map.startWorldY) {
        Map.wy = Map.startWorldY;
    }

}
void MAP::draw() {
    int startCol = (int)Map.wx / Map.chipSize;//表示開始列
    int endCol = startCol + Map.dispCols;//表示終了列
    for (int c = startCol; c < endCol; c++) {
        float wx = (float)Map.chipSize * c;
        for (int r = 0; r < Map.rows; r++) {
            float wy = (float)Map.chipSize * r;
            char charaId = Map.data[r * Map.cols + c];
            //木の絵がきたらやる又は仮にレクトを置く
            if (charaId >= '0' && charaId <= '9') {
                float px = wx - Map.wx;
                float py = wy - Map.wy;
                if (charaId == '1') {
                    image(Map.treeImg, px, py);
                }
            }
            else if (charaId >= 'a' && charaId <= 'z') {
                game()->characterManager()->appear(charaId, wx, wy);
                Map.data[r * Map.cols + c] = '.';
            }
        }
    }
}

float MAP::wDispLeft()
{
    return Map.wx - Map.chipSize;
}

float MAP::wDispRight()
{
    return Map.wx + width;
}

float MAP::wDispTop()
{
    return Map.wy - Map.chipSize;
}

float MAP::wDispbottom()
{
    return Map.wy + height;
}


