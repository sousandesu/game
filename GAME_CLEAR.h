#pragma once
#include "SCENE.h"
class GAME_CLEAR :
    public SCENE
{
public:
    GAME_CLEAR(class GAME* game);
    ~GAME_CLEAR();
    void draw();
    void nextScene();
};

