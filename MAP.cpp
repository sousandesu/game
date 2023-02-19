#include"GAME.h"
#include"CONTAINER.h"
#include "MAP.h"
MAP::MAP(class GAME* game) :
    GAME_OBJECT(game) {
}
MAP::~MAP() {
    if (Map.data) { delete[] Map.data; Map.data = 0; }
    if (Map.backdata) { delete[] Map.backdata; Map.backdata = 0; }
}
void MAP::create() {
    Map = game()->container()->data().map;
}
void MAP::init() {
    backmapinit();
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
    Map.dispRows = (int)height / Map.chipSize +2;//表示すべき行数
    //多分dispRows必要

    Map.worldWidth = (float)Map.chipSize * (Map.cols - 2);//ワールドの横幅
    Map.endWorldX = Map.worldWidth - width;//表示できる最後の座標
    Map.worldHeight = (float)Map.chipSize * (Map.rows - 1);//ワールドの縦幅
    Map.endWorldY = Map.worldHeight - height;//表示できる最後の座標
    Map.wx = 0.0f;//現在表示しているワールド座標
    Map.wy = 0.0f;//現在表示しているワールド座標

}
void MAP::backmapinit()
{
    FILE* fp;
    fopen_s(&fp, Map.backFileName, "rb");
    WARNING(fp == 0, "マップデータを読み込めません", Map.backFileName);
    //ファイルサイズ取得
    fseek(fp, 0, SEEK_END);
    int fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    //リトライ時、Dataは0でないので開放。
    if (Map.backdata) { delete[] Map.backdata; Map.backdata = 0; }
    //サイズ分のdata配列を用意する
    Map.backdata = new char[fileSize];
    //データを読み込む
    fread(Map.backdata, sizeof(char), fileSize, fp);
    fclose(fp);
    //行数、列数を数える（最後の行も必ず改行して終わっていることが条件）
    Map.backrows = 0;
    Map.backcols = 0;//改行２文字分を含んだ列数になる
    int cnt = 0;
    for (int i = 0; i < fileSize; i++) {
        cnt++;
        //行の最後の文字
        if (Map.backdata[i] == '\n') {
            if (Map.backrows == 0) {
                //最初の行の列数
                Map.backcols = cnt;
            }
            else if (Map.backcols != cnt) {
                //行ごとの列数が違ったらエラー
                WARNING(1, "列数が不揃い", "");
            }
            //行を数えてカウンタをリセット
            Map.backrows++;
            cnt = 0;
        }
    }
    if (fileSize % Map.backcols != 0) {
        WARNING(1, "最後の行を改行していない", "");
    }
    Map.backDispCols =(int)width / Map.backwidth  + 1;//表示すべき列数
    //多分dispRows必要
}
void MAP::update() {
    //プレイヤーが画面の中央を超えた分だけスクロール
    if (Map.wx > 7030&&Map.wy<550) {
        Map.wx += 3;
        Map.wy += -3;
    }
    else {
        //左右方向スクロール
        Map.wx += game()->characterManager()->player()->overCenterVx();
        //上下方向スクロール
        Map.wy += game()->characterManager()->player()->overCenterVy();
    }
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

void MAP::draw()
{
    backmapdraw();
    int startCol = (int)Map.wx / Map.chipSize;//表示開始列
    int endCol = startCol + Map.dispCols;//表示終了列

    int startRow = (int)Map.wy / Map.chipSize;
    int endRow = startRow + Map.dispRows;

    for (int c = startCol; c < endCol; c++) {
        float wx = (float)Map.chipSize * c;
        for (int r = startRow; r < endRow; r++) {
            float wy = (float)Map.chipSize * r;
            char charaId = Map.data[r * Map.cols + c];
            if (charaId >= '0' && charaId <= '9') {
                float px = wx - Map.wx;
                float py = wy - Map.wy;
                if (charaId == '1') {
                    image(Map.treeImg, px, py);
                }
                else if (charaId == '2'&& Map.wx > 7030 && Map.wy < 560) {
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

void MAP::backmapdraw() {

    int startCol = (int)Map.wx / Map.backwidth ;//表示開始列
    int endCol = startCol + Map.backDispCols;//表示終了列
    for (int c = startCol; c < endCol; c++) {
        float wx = (float)Map.backwidth * c;
        for (int r = 0; r < Map.backrows; r++) {
            float wy = (float)Map.backheight * r;
            char charaId = Map.backdata[r * Map.backcols + c];
            if (charaId >= '0' && charaId <= '9') {
                float px = wx - Map.wx;
                float py = wy - Map.wy;
                if (charaId == '1') {
                    imageColor(Map.color);
                    image(Map.backImg, px, py);
                }
            }
        }
    }
}

bool MAP::collisionCheck(float wx, float wy) {
    //ワールド座標からマップDataの列colと行rowを求める
    int col = (int)wx / Map.chipSize;
    int row = (int)wy / Map.chipSize;
    //Dataの範囲外は判定できないので除外
    if ((col < 0) || (col >= Map.cols) || (row < 0) || (row >= Map.rows)) {
        return false;
    }
    //次の記述で座標がマップチップの中に入っているか判定できる
    if (Map.data[col + row * Map.cols] == '1') {
        return true;
    }
    if (Map.data[col + row * Map.cols] == '2' && Map.wx > 7030 && Map.wy < 550) {
        return true;
    }
    return false;
}
/*
//　マップチップとキャラの左辺が重なっているか
bool MAP::collisionCharaLeft(float wx, float wy) {
    bool leftTop = collisionCheck(wx, wy);
    bool leftBottom = collisionCheck(wx, wy + Map.chipSize - 1);
    return leftTop || leftBottom;
}
//　マップチップとキャラの右辺が重なっているか
bool MAP::collisionCharaRight(float wx, float wy) {
    bool rightTop = collisionCheck(wx + Map.chipSize - 1, wy);
    bool rightBottom = collisionCheck(wx + Map.chipSize - 1, wy + Map.chipSize - 1);
    return rightTop || rightBottom;
}
//　マップチップとキャラの上辺が重なっているか
bool MAP::collisionCharaTop(float wx, float wy) {
    bool topLeft = collisionCheck(wx, wy);
    bool topRight = collisionCheck(wx + Map.chipSize - 1, wy);
    return topLeft || topRight;
}
//　マップチップとキャラの下辺が重なっている、または、接しているか。ここだけ他と違う！
bool MAP::collisionCharaBottom(float wx, float wy) {
    // wy + Map.chipSizeをCheck関数に渡すことにより
    // キャラがマップチップと接しているかチェックできる。
    bool bottomLeft = collisionCheck(wx, wy + Map.chipSize);//最後に－１する可能性
    bool bottomRight = collisionCheck(wx + Map.chipSize - 1, wy + Map.chipSize);//最後に－１する可能性
    return bottomLeft || bottomRight;
}
*/
//上記の各コリジョンチェックは下記に変更
bool MAP::collisionCharaLeft(float wLeft, float wTop, float wRight, float wBottom) {
    bool leftTop = collisionCheck(wLeft, wTop);
    bool leftBottom = collisionCheck(wLeft, wBottom);
    return leftTop || leftBottom;
}

bool MAP::collisionCharaRight(float wLeft, float wTop, float wRight, float wBottom) {
    bool rightTop = collisionCheck(wRight, wTop);
    bool rightBottom = collisionCheck(wRight, wBottom);
    return rightTop || rightBottom;
}

bool MAP::collisionCharaTop(float wLeft, float wTop, float wRight, float wBottom) {
    bool rightTop = collisionCheck(wRight, wTop);
    bool leftTop = collisionCheck(wLeft, wTop);
    return rightTop || leftTop;
}

bool MAP::collisionCharaBottom(float wLeft, float wTop, float wRight, float wBottom) {
    bool rightBottom = collisionCheck(wRight, wBottom);
    bool leftBottom = collisionCheck(wLeft, wBottom);
    return rightBottom || leftBottom;
}

//　マップチップと弾の当たり判定に使用
//bool MAP::collisionCharaRect(float wLeft, float wTop, float wRight, float wBottom) {
//    bool rightTop = collisionCheck(wRight, wTop);
//    bool rightBottom = collisionCheck(wRight, wBottom);
//    bool leftTop = collisionCheck(wLeft, wTop);
//    bool leftBottom = collisionCheck(wLeft, wBottom);
//    return rightTop || rightBottom || leftTop || leftBottom;
//}

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


