#pragma once
#include "Bird.h"
#include "ofMain.h"

class Square : public Bird
{
public:
	Square();
	Square(ofVec2f pos, ofVec2f spd, float sideLength, ofColor color);

	
	void display();

	void setSideLength(float sideLength);
	float getSideLength();

	void setColor(ofColor color);
	ofColor getColor();

private:
	float sideLength;
	ofColor color;

};

inline void Square::setSideLength(float sideLength)
{
	this->sideLength = sideLength;
}

inline float Square::getSideLength()
{
	return sideLength;
}

inline void Square::setColor(ofColor color)
{
	this->color = color;
}

inline ofColor Square::getColor()
{
	return color;
}


