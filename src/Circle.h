#pragma once
#include "Bird.h"
#include "ofMain.h"

class Circle : public Bird
{
public:
	Circle();
	Circle(ofVec2f pos, ofVec2f spd, float radius, ofColor color);

	void display();

	void setRadius(float radius);
	float getRadius();

	void setColor(ofColor color);
	ofColor getColor();

private:
	float radius;
	ofColor color;

};

inline void Circle::setRadius(float radius)
{
	this->radius = radius;
}

inline float Circle::getRadius()
{
	return radius;
}

inline void Circle::setColor(ofColor color)
{
	this->color = color;
}

inline ofColor Circle::getColor()
{
	return color;
}


