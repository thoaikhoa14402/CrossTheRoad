#pragma once
#include"CCONSOLE.h"
#include"CANIMAL.h"
#include"CVEHICLE.h"

class CPEOPLE
{
private:
	int width, height;
	int mX, mY;
	bool mState;
public:
	CPEOPLE();
	CPEOPLE(int, int);

	int getWidth();
	int getHeight();

	int getX();
	int getY();
	void setX(int mX);
	void setY(int mY);

	void goUp();
	void goLeft();
	void goRight();
	void goDown();
	// checking Impact
	bool isImpact(CANIMAL*);
	bool isImpact(CVEHICLE*);
	bool isImpact(CPEOPLE);

	void setState(bool);
	bool getState();

	bool isFinish();
	bool isDead();

};