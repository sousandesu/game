#pragma once
#include "SCENE.h"
class GAME_OVER :
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
    DATA Game_over;
public:
    GAME_OVER(class GAME* game);
    ~GAME_OVER();
    void create();
    void init();
    void draw();
    void nextScene();
};

