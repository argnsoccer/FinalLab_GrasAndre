#include "Bird.h"


Bird::Bird()
{
}


Bird::Bird(ofVec2f pos, ofVec2f spd):
	pos(pos), spd(spd){
		gravity = 1.2;
}


void Bird::move()
{
	pos.y += gravity;
	pos += spd;
}

