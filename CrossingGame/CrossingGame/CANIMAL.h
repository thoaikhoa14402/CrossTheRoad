#pragma once

#include"CCONSOLE.h"
class CANIMAL
{
protected:
	int mX, mY; 
	int width, height;
	bool moving_state; // 1: moving
public:
	CANIMAL(int x, int y); // constructor
	virtual void Move() = 0;
	virtual void Tell() = 0;
	// Get position
	int getX();
	int getY();
	// Set position
	void setX(int);
	void setY(int);
	// width + height
	int getWidth();
	int getHeight();
	// Get moving state
	bool getState();
	// Set moving state
	void setState(bool);
};