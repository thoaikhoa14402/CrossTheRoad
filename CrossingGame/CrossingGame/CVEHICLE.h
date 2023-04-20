#pragma once
#include"CCONSOLE.h"
class CVEHICLE
{
protected:
	int mX, mY;
	int width, height;
	bool moving_state;
	bool tl_state;
public:
	virtual void Move() = 0;
	virtual void Tell() = 0;
	CVEHICLE(int x, int y);
	// pos
	int getX();
	int getY();
	void setX(int);
	void setY(int);
	// width + height
	int getWidth();
	int getHeight();
	//moving state
	bool getState();
	void setState(bool);
	// traffic light state
	bool getTLState();
	void setTLState(bool);
};