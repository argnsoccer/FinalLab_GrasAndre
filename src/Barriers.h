#pragma once
#include "ofMain.h"

class Barriers
{
public:
	Barriers();
	Barriers(int width, int height, ofVec2f pos);
	void display();

	ofVec2f getPos();
	void setPos(ofVec2f pos);
		
	void setHeight(int height);
	int getHeight();

	void setWidth(int width);
	int getWidth();

private:
	int height;
	int width;
	ofVec2f pos;
};


inline void Barriers::setHeight(int height)
{
	this->height = height;
}

inline int Barriers::getHeight()
{
	return height;
}

inline void Barriers::setPos(ofVec2f pos)
{
	this->pos = pos;
}

inline ofVec2f Barriers::getPos()
{
	return pos;
}

inline void Barriers::setWidth(int width)
{
	this->width = width;
}

inline int Barriers::getWidth()
{
	return width;
}




