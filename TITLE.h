#pragma once
#include"libOne.h"
#include "SCENE.h"
class TITLE :
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
    DATA Title;
public:
    TITLE(class GAME* game);
    ~TITLE();
    void create();
    void draw();
    void nextScene();
};

