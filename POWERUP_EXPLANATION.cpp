#include"GAME.h"
#include"PLAYER.h"
#include"CONTAINER.h"
#include "POWERUP_EXPLANATION.h"
POWERUP_EXPLANATION::POWERUP_EXPLANATION(GAME* game) :
	GAME_OBJECT(game)
{

}

POWERUP_EXPLANATION::~POWERUP_EXPLANATION()
{

}

void POWERUP_EXPLANATION::create()
{
	Powerup_Explannation = game()->container()->data().powerup_explanation;
}

void POWERUP_EXPLANATION::init()
{
	Powerup_Explannation.displayTime = 0.0f;
	Powerup_Explannation.displayFlag = false;
}

void POWERUP_EXPLANATION::draw()
{
	if (game()->characterManager()->player()->powerupFlag() && Powerup_Explannation.displayTime <= 0 &&
		!Powerup_Explannation.displayFlag) {
		Powerup_Explannation.displayTime = Powerup_Explannation.displayInterval * delta;
	}
	if (Powerup_Explannation.displayTime > 0) {
		imageColor(Powerup_Explannation.color);
		image(Powerup_Explannation.img,Powerup_Explannation.px, Powerup_Explannation.py);
		Powerup_Explannation.displayTime -= delta;
		if (Powerup_Explannation.displayTime <= 0) {
			Powerup_Explannation.displayFlag = true;
		}
	}
}
