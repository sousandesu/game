#pragma once
#include "CHARACTER.h"
class POWERUP_ITEM :
    public CHARACTER
{
public:
    POWERUP_ITEM(class GAME* game) :CHARACTER(game) {}
    void create();
    void damage();
};

