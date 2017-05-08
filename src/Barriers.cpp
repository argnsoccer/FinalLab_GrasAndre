#include "Barriers.h"


Barriers::Barriers()
{
}


Barriers::Barriers(int width, int height, ofVec2f pos):
	width(width), height(height), pos(pos){}

void Barriers::display()
{
	ofSetColor(255,0,0);
	ofRect(pos.x, pos.y, width, height);
	
}
