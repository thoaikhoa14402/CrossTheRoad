#include "CVEHICLE.h"

CVEHICLE::CVEHICLE(int x, int y)
{
	mX = x;
	mY = y;
	moving_state = false;
	tl_state = true;
}

// get width + height cvehicle
int CVEHICLE::getWidth()
{
	return this->width;
}

int CVEHICLE::getHeight()
{
	return this->height;
}

// get mX + mY  cvehicle
int CVEHICLE::getX()
{
	return this->mX;
}

int CVEHICLE::getY()
{
	return this->mY;
}

void CVEHICLE::setX(int mX)
{
	this->mX = mX;
}


void CVEHICLE::setY(int mY)
{
	this->mY = mY;
}

// state
bool CVEHICLE::getState()
{
	return this->moving_state;
}


void CVEHICLE::setState(bool moving_state)
{
	this->moving_state = moving_state;
}

// traffic light state

bool CVEHICLE::getTLState()
{
	return tl_state;
}

void CVEHICLE::setTLState(bool tl_state)
{
	this->tl_state = tl_state;
}