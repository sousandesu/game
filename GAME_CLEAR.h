#pragma once
#include "SCENE.h"
class GAME_CLEAR :
    public SCENE
{
public:
    struct DATA {
        bool changeBackFlag = false;
        float changeBackTime = 0;
        float changeBackInterval = 0;
        float backpx;
        float backpy;
        int backImg = 0;
        COLOR backColor;
    };
private:
    DATA Game_clear;
public:
    GAME_CLEAR(class GAME* game);
    ~GAME_CLEAR();
    void create();
    void init();
    void draw();
    void nextScene();
};

