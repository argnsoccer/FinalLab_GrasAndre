#include "Square.h"


Square::Square()
{
}

Square::Square(ofVec2f pos, ofVec2f spd, float sideLength, ofColor color):
	Bird(pos,spd), sideLength(sideLength), color(color){
		
}


void Square::display()
{
	ofSetColor(color);
	ofRect(getPos().x, getPos().y, sideLength, sideLength);
}


