#include"GAME.h"
#include"CONTAINER.h"
#include"CHARACTER.h"
#include"PLAYER.h"
#include"PLAYER_BULLET.h"
#include"PLAYER_BULLET2.h"
#include"ENEMY_1.h"
#include"ENEMY_2.h"
#include"ENEMY_2_BULLET.h"
#include"BOSS.h"
#include"BOSS_BULLET_1.h"
#include"BOSS_BULLET_2.h"
#include"BOSS_BULLET_3.h"
#include"HEALINGPORTION.h"
#include"POWERUP_ITEM.h"
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
    Total += CharaMng.numPlayerBullets2;
    Total += CharaMng.numEnemies_1;
    Total += CharaMng.numEnemies_2;
    Total += CharaMng.numEnemies_2Bullets;
    Total += CharaMng.numBosses;
    Total += CharaMng.numBossesBullets_1;
    Total += CharaMng.numBossesBullets_2;
    Total += CharaMng.numBossesBullets_3;
    Total += CharaMng.numHealingPortions;
    Total += CharaMng.numPowerupItems;
   
    Characters = new CHARACTER * [Total];

    Player = new PLAYER(game());
    int i, j = 0;
    for (i = 0; i < CharaMng.numPlayers; i++)         Characters[j++] = Player;
    for (i = 0; i < CharaMng.numPlayerBullets; i++)   Characters[j++] = new PLAYER_BULLET(game());
    for (i = 0; i < CharaMng.numPlayerBullets2; i++)  Characters[j++] = new PLAYER_BULLET2(game());
    for (i = 0; i < CharaMng.numEnemies_1; i++)       Characters[j++] = new ENEMY_1(game());
    for (i = 0; i < CharaMng.numEnemies_2; i++)       Characters[j++] = new ENEMY_2(game());
    for (i = 0; i < CharaMng.numEnemies_2Bullets; i++)Characters[j++] = new ENEMY_2_BULLET(game());
    for (i = 0; i < CharaMng.numBosses; i++)          Characters[j++] = new BOSS(game());
    for (i = 0; i < CharaMng.numBossesBullets_1; i++) Characters[j++] = new BOSS_BULLET_1(game());
    for (i = 0; i < CharaMng.numBossesBullets_2; i++) Characters[j++] = new BOSS_BULLET_2(game());
    for (i = 0; i < CharaMng.numBossesBullets_3; i++) Characters[j++] = new BOSS_BULLET_3(game());
    for (i = 0; i < CharaMng.numHealingPortions; i++) Characters[j++] = new HEALINGPORTION(game());
    for (i = 0; i < CharaMng.numPowerupItems; i++)    Characters[j++] = new POWERUP_ITEM(game());
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
    // charaId???w?????????L???????o????????
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
    //?L???????L????????????????---------------------------------------------------
    for (int i = 0; i < Total - 1; i++) {
        if (Characters[i]->hp() == 0) {
            continue;// ????????i++??????
        }
        for (int j = i + 1; j < Total; j++) {
            if (Characters[j]->hp() == 0) {
                continue;// ????????j++??????
            }
            //????????????????????????????
            if (Characters[i]->groupId() == Characters[j]->groupId()) {
                continue;// ????????j++??????
            }
            //??????????
            if (Characters[i]->wLeft() < Characters[j]->wRight() &&
                Characters[j]->wLeft() < Characters[i]->wRight() &&
                Characters[i]->wTop() < Characters[j]->wBottom() &&
                Characters[j]->wTop() < Characters[i]->wBottom()) {
                //????????
                if (Characters[i]->groupId() == 0 && Characters[j]->groupId() == 1) {
                    //?v???C???[???G?????????????v???C???[?????_???[?W??????????????????
                    Characters[i]->damage();
                }
                else if (Characters[i]->groupId() == 0 && Characters[j]->groupId() == 4) {
                    //?v???C???[???A?C?e???????????????A?C?e???????_???[?W??????????????????
                    Characters[j]->damage();
                }
                else if (Characters[i]->groupId() == 0 && Characters[j]->groupId() == 2) {
                    //?v???C???[???v???C???[???e????????????????
                }
                else if (Characters[i]->groupId() == 1 && Characters[j]->groupId() == 3) {
                    //?G???G???e????????????????
                }
                else if (Characters[i]->groupId() == 1 && Characters[j]->groupId() == 4) {
                    //?G???A?C?e??????????????????
                }
                else if (Characters[i]->groupId() == 2 && Characters[j]->groupId() == 3) {
                    //?v???C???[???e???G???e????????????????
                }
                else if (Characters[i]->groupId() == 2 && Characters[j]->groupId() == 4) {
                    //?v???C???[???e???A?C?e??????????????????
                }
                else if (Characters[i]->groupId() == 3 && Characters[j]->groupId() == 4) {
                    //?G???e???A?C?e??????????????????
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

//???????????????L?????N?^?[???????g??????
int CHARACTER_MANAGER::hp(char charaId)
{
    for (int i = 0; i < Total; i++) {
        if (Characters[i]->charaId() == charaId) {
            return Characters[i]->hp();
        }
    }
}
