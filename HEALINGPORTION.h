#pragma once
#include "CHARACTER.h"
class HEALINGPORTION :
    public CHARACTER
{
public:
    HEALINGPORTION(class GAME* game) :CHARACTER(game) {}
    void create();
    void update();
    void damage();
};

