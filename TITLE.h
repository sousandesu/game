#pragma once
#include"libOne.h"
#include "SCENE.h"
class TITLE :
    public SCENE
{
public:
    struct DATA {
        VECTOR2 backPos;
        float printSize;
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

