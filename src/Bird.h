#pragma once
#include "ofMain.h"

class Bird
{
public:
	Bird();
	Bird(ofVec2f pos, ofVec2f spd);

	virtual void move();
	virtual void display() = 0;

	void setPos(ofVec2f pos);
	ofVec2f getPos();
	void setSpd(ofVec2f spd);
	ofVec2f getSpd();

private:
	ofVec2f pos;
	ofVec2f spd;
	float gravity;
	
};

inline void Bird::setPos(ofVec2f pos)
{
	this->pos = pos;
}


inline ofVec2f Bird::getPos()
{
	return pos;
}

inline void Bird::setSpd(ofVec2f spd)
{
	this->spd = spd;
}

inline ofVec2f Bird::getSpd()
{
	return spd;
}