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
    //�t�@�C�����J��
    FILE* fp;
    fopen_s(&fp, Map.fileName, "rb");
    WARNING(fp == 0, "�}�b�v�f�[�^��ǂݍ��߂܂���", Map.fileName);
    //�t�@�C���T�C�Y�擾
    fseek(fp, 0, SEEK_END);
    int fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    //���g���C���AData��0�łȂ��̂ŊJ���B
    if (Map.data) { delete[] Map.data; Map.data = 0; }
    //�T�C�Y����data�z���p�ӂ���
    Map.data = new char[fileSize];
    //�f�[�^��ǂݍ���
    fread(Map.data, sizeof(char), fileSize, fp);
    fclose(fp);
    //�s���A�񐔂𐔂���i�Ō�̍s���K�����s���ďI����Ă��邱�Ƃ������j
    Map.rows = 0;
    Map.cols = 0;//���s�Q���������܂񂾗񐔂ɂȂ�
    int cnt = 0;
    for (int i = 0; i < fileSize; i++) {
        cnt++;
        //�s�̍Ō�̕���
        if (Map.data[i] == '\n') {
            if (Map.rows == 0) {
                //�ŏ��̍s�̗�
                Map.cols = cnt;
            }
            else if (Map.cols != cnt) {
                //�s���Ƃ̗񐔂��������G���[
                WARNING(1, "�񐔂��s����", "");
            }
            //�s�𐔂��ăJ�E���^�����Z�b�g
            Map.rows++;
            cnt = 0;
        }
    }
    if (fileSize % Map.cols != 0) {
        WARNING(1, "�Ō�̍s�����s���Ă��Ȃ�", "");
    }
    Map.dispCols = (int)width / Map.chipSize + 1;//�\�����ׂ���
    Map.dispRows = (int)height / Map.chipSize +2;//�\�����ׂ��s��
    //����dispRows�K�v

    Map.worldWidth = (float)Map.chipSize * (Map.cols - 2);//���[���h�̉���
    Map.endWorldX = Map.worldWidth - width;//�\���ł���Ō�̍��W
    Map.worldHeight = (float)Map.chipSize * (Map.rows - 1);//���[���h�̏c��
    Map.endWorldY = Map.worldHeight - height;//�\���ł���Ō�̍��W
    Map.wx = 0.0f;//���ݕ\�����Ă��郏�[���h���W
    Map.wy = 0.0f;//���ݕ\�����Ă��郏�[���h���W

}
void MAP::backmapinit()
{
    FILE* fp;
    fopen_s(&fp, Map.backFileName, "rb");
    WARNING(fp == 0, "�}�b�v�f�[�^��ǂݍ��߂܂���", Map.backFileName);
    //�t�@�C���T�C�Y�擾
    fseek(fp, 0, SEEK_END);
    int fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    //���g���C���AData��0�łȂ��̂ŊJ���B
    if (Map.backdata) { delete[] Map.backdata; Map.backdata = 0; }
    //�T�C�Y����data�z���p�ӂ���
    Map.backdata = new char[fileSize];
    //�f�[�^��ǂݍ���
    fread(Map.backdata, sizeof(char), fileSize, fp);
    fclose(fp);
    //�s���A�񐔂𐔂���i�Ō�̍s���K�����s���ďI����Ă��邱�Ƃ������j
    Map.backrows = 0;
    Map.backcols = 0;//���s�Q���������܂񂾗񐔂ɂȂ�
    int cnt = 0;
    for (int i = 0; i < fileSize; i++) {
        cnt++;
        //�s�̍Ō�̕���
        if (Map.backdata[i] == '\n') {
            if (Map.backrows == 0) {
                //�ŏ��̍s�̗�
                Map.backcols = cnt;
            }
            else if (Map.backcols != cnt) {
                //�s���Ƃ̗񐔂��������G���[
                WARNING(1, "�񐔂��s����", "");
            }
            //�s�𐔂��ăJ�E���^�����Z�b�g
            Map.backrows++;
            cnt = 0;
        }
    }
    if (fileSize % Map.backcols != 0) {
        WARNING(1, "�Ō�̍s�����s���Ă��Ȃ�", "");
    }
    Map.backDispCols =(int)width / Map.backwidth  + 1;//�\�����ׂ���
    //����dispRows�K�v
}
void MAP::update() {
    //�v���C���[����ʂ̒����𒴂����������X�N���[��
    if (Map.wx > 7030&&Map.wy<550) {
        Map.wx += 3;
        Map.wy += -3;
    }
    else {
        //���E�����X�N���[��
        Map.wx += game()->characterManager()->player()->overCenterVx();
        //�㉺�����X�N���[��
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
    int startCol = (int)Map.wx / Map.chipSize;//�\���J�n��
    int endCol = startCol + Map.dispCols;//�\���I����

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

    int startCol = (int)Map.wx / Map.backwidth ;//�\���J�n��
    int endCol = startCol + Map.backDispCols;//�\���I����
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
    //���[���h���W����}�b�vData�̗�col�ƍsrow�����߂�
    int col = (int)wx / Map.chipSize;
    int row = (int)wy / Map.chipSize;
    //Data�͈̔͊O�͔���ł��Ȃ��̂ŏ��O
    if ((col < 0) || (col >= Map.cols) || (row < 0) || (row >= Map.rows)) {
        return false;
    }
    //���̋L�q�ō��W���}�b�v�`�b�v�̒��ɓ����Ă��邩����ł���
    if (Map.data[col + row * Map.cols] == '1') {
        return true;
    }
    if (Map.data[col + row * Map.cols] == '2' && Map.wx > 7030 && Map.wy < 550) {
        return true;
    }
    return false;
}
/*
//�@�}�b�v�`�b�v�ƃL�����̍��ӂ��d�Ȃ��Ă��邩
bool MAP::collisionCharaLeft(float wx, float wy) {
    bool leftTop = collisionCheck(wx, wy);
    bool leftBottom = collisionCheck(wx, wy + Map.chipSize - 1);
    return leftTop || leftBottom;
}
//�@�}�b�v�`�b�v�ƃL�����̉E�ӂ��d�Ȃ��Ă��邩
bool MAP::collisionCharaRight(float wx, float wy) {
    bool rightTop = collisionCheck(wx + Map.chipSize - 1, wy);
    bool rightBottom = collisionCheck(wx + Map.chipSize - 1, wy + Map.chipSize - 1);
    return rightTop || rightBottom;
}
//�@�}�b�v�`�b�v�ƃL�����̏�ӂ��d�Ȃ��Ă��邩
bool MAP::collisionCharaTop(float wx, float wy) {
    bool topLeft = collisionCheck(wx, wy);
    bool topRight = collisionCheck(wx + Map.chipSize - 1, wy);
    return topLeft || topRight;
}
//�@�}�b�v�`�b�v�ƃL�����̉��ӂ��d�Ȃ��Ă���A�܂��́A�ڂ��Ă��邩�B�����������ƈႤ�I
bool MAP::collisionCharaBottom(float wx, float wy) {
    // wy + Map.chipSize��Check�֐��ɓn�����Ƃɂ��
    // �L�������}�b�v�`�b�v�Ɛڂ��Ă��邩�`�F�b�N�ł���B
    bool bottomLeft = collisionCheck(wx, wy + Map.chipSize);//�Ō�Ɂ|�P����\��
    bool bottomRight = collisionCheck(wx + Map.chipSize - 1, wy + Map.chipSize);//�Ō�Ɂ|�P����\��
    return bottomLeft || bottomRight;
}
*/
//��L�̊e�R���W�����`�F�b�N�͉��L�ɕύX
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

//�@�}�b�v�`�b�v�ƒe�̓����蔻��Ɏg�p
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


