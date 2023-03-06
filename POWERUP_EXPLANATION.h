#pragma once
#include "GAME_OBJECT.h"
class POWERUP_EXPLANATION :
    public GAME_OBJECT
{
public:
    struct DATA {
        int img = 0;
        COLOR color;
        float px = 0;
        float py = 0;
        float displayTime = 0;
        float displayInterval = 0;
        bool displayFlag = false;
    };
private:
    DATA Powerup_Explannation;
public:
    POWERUP_EXPLANATION(class GAME* game);
    ~POWERUP_EXPLANATION();
    void create();
    void init();
    void draw();
};

