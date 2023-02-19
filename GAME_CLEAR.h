#pragma once
#include "SCENE.h"
class GAME_CLEAR :
    public SCENE
{
public:
    struct DATA {
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
    void draw();
    void nextScene();
};

