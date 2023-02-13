#include"GAME.h"
#include"CONTAINER.h"
#include"CHARACTER.h"
#include"PLAYER.h"
#include"PLAYER_BULLET.h"
#include"ENEMY_1.h"
#include"ENEMY_2.h"
#include"ENEMY_2_BULLET.h"
#include "CHARACTER_MANAGER.h"

CHARACTER_MANAGER::CHARACTER_MANAGER(GAME* game):
	GAME_OBJECT(game)
{
}

CHARACTER_MANAGER::~CHARACTER_MANAGER()
{
    for (int i = 0; i < Total; i++) {
        delete Characters[i];
    }
    delete[] Characters;
}

void CHARACTER_MANAGER::create()
{
    CharaMng = game()->container()->data().charaMng;

    Total = 0;
    Total += CharaMng.numPlayers;
    Total += CharaMng.numPlayerBullets;
    Total += CharaMng.numEnemies_1;
    Total += CharaMng.numEnemies_2;
    Total += CharaMng.numEnemies_2Bullets;
   
    Characters = new CHARACTER * [Total];

    Player = new PLAYER(game());
    int i, j = 0;
    for (i = 0; i < CharaMng.numPlayers; i++)         Characters[j++] = Player;
    for (i = 0; i < CharaMng.numPlayerBullets; i++)   Characters[j++] = new PLAYER_BULLET(game());
    for (i = 0; i < CharaMng.numEnemies_1; i++)       Characters[j++] = new ENEMY_1(game());
    for (i = 0; i < CharaMng.numEnemies_2; i++)       Characters[j++] = new ENEMY_2(game());
    for (i = 0; i < CharaMng.numEnemies_2Bullets; i++)Characters[j++] = new ENEMY_2_BULLET(game());

    for (int i = 0; i < Total; i++) {
        Characters[i]->create();
    }
}

void CHARACTER_MANAGER::init()
{
    for (int i = 0; i < Total; i++) {
        Characters[i]->init();
    }
}

void CHARACTER_MANAGER::appear(char charaId, float wx, float wy, float vx, float vy)
{
    // charaId�Ŏw�肳�ꂽ�L�������o��������
    for (int i = 0; i < Total; i++) {
        if (Characters[i]->charaId() == charaId) {
            if (Characters[i]->hp() <= 0) {
                Characters[i]->appear(wx, wy, vx, vy);
                break;
            }
        }
    }
}

void CHARACTER_MANAGER::update()
{
    for (int i = 0; i < Total; i++) {
        if (Characters[i]->hp() > 0) {
            Characters[i]->update();
        }
    }
    //�L�����ƃL�����̓����蔻��---------------------------------------------------
    for (int i = 0; i < Total - 1; i++) {
        if (Characters[i]->hp() == 0) {
            continue;// ��������i++�ɖ߂�
        }
        for (int j = i + 1; j < Total; j++) {
            if (Characters[j]->hp() == 0) {
                continue;// ��������j++�ɖ߂�
            }
            //���Ԃǂ����͓����蔻�肵�Ȃ�
            if (Characters[i]->groupId() == Characters[j]->groupId()) {
                continue;// ��������j++�ɖ߂�
            }
            //�����蔻��
            if (Characters[i]->wLeft() < Characters[j]->wRight() &&
                Characters[j]->wLeft() < Characters[i]->wRight() &&
                Characters[i]->wTop() < Characters[j]->wBottom() &&
                Characters[j]->wTop() < Characters[i]->wBottom()) {
                //��������
                if (Characters[i]->groupId() == 0 && Characters[j]->groupId() == 1) {
                    //�G�L�����Ǝ�����������ꍇ���������_���[�W��������悤�ȕ���
                    Characters[i]->damage();
                }
                else if (Characters[i]->groupId() == 0 && Characters[j]->groupId() == 2) {
                    //�v���C���[�ƃv���C���[�̒e�͓�����Ȃ�����
                }
                else if (Characters[i]->groupId() == 1 && Characters[j]->groupId() == 4) {

                }
                else if (Characters[i]->groupId() == 2 && Characters[j]->groupId() == 4) {

                }
                else {
                    Characters[i]->damage();
                    Characters[j]->damage();
                }
            }
        }
    }
}

void CHARACTER_MANAGER::draw()
{
    for (int i = 0; i < Total; i++) {
        if (Characters[i]->hp() > 0) {
            Characters[i]->draw();
        }
    }
}
