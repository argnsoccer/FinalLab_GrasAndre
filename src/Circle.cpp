#include "Circle.h"


Circle::Circle()
{
}

Circle::Circle(ofVec2f pos, ofVec2f spd, float radius, ofColor color):
	Bird(pos,spd), radius(radius), color(color){}

void Circle::display()
{
	ofSetColor(color);
	ofCircle(getPos().x,getPos().y,radius);
}

