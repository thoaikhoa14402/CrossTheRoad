#include "CANIMAL.h"
// ANIMAL

// Constructor
CANIMAL::CANIMAL(int x, int y)
{
	mX = x;
	mY = y;
	moving_state = false;
	width = height = 0;
}


// Get width + height
int CANIMAL::getWidth()
{
	return this->width;
}

int CANIMAL::getHeight()
{
	return this->height;
}



// Get postition of CANIMAL
int CANIMAL::getX()
{
	return this->mX;
}

int CANIMAL::getY()
{
	return this->mY;
}

// Set position of CANIMAL
void CANIMAL::setX(int mX)
{
	this->mX = mX;
}


void CANIMAL::setY(int mY)
{
	this->mY = mY;
}

// Get state
bool CANIMAL::getState()
{
	return this->moving_state;
}

// Set state
void CANIMAL::setState(bool moving_state)
{
	this->moving_state = moving_state;
}
