#include"CPEOPLE.h"

CPEOPLE::CPEOPLE()
{

}

CPEOPLE::CPEOPLE(int x, int y)
{
	this->mX = x;
	this->mY = y;
	width = 3, height = 3;
	mState = true;
}



void CPEOPLE::goUp()
{
	if (mY > 10)
	{
		CCONSOLE::removeSpace(POINT{ mX, mY }, POINT{ mX + width, mY + height });
		mY -= 5;
		CCONSOLE::drawGraphics("cgame/cpeople.txt", POINT{ mX,mY }, 12);
	}

}

void CPEOPLE::goLeft()
{
	if (mX > 5)
	{
		CCONSOLE::removeSpace(POINT{ mX, mY }, POINT{ mX + width, mY + height });
		mX -= 3;
		CCONSOLE::drawGraphics("cgame/cpeople.txt", POINT{ mX,mY }, 12);
	}
}

void CPEOPLE::goDown()
{
	if (mY < 30)
	{
		CCONSOLE::removeSpace(POINT{ mX, mY }, POINT{ mX + width, mY + height });
		mY += 5;
		CCONSOLE::drawGraphics("cgame/cpeople.txt", POINT{ mX,mY }, 12);
	}
}

void CPEOPLE::goRight()
{
	if (mX < 109)
	{
		CCONSOLE::removeSpace(POINT{ mX, mY }, POINT{ mX + width, mY + height });
		mX += 3;
		CCONSOLE::drawGraphics("cgame/cpeople.txt", POINT{ mX,mY }, 12);
	}
}


// Get position
int CPEOPLE::getX()
{
	return this->mX;
}

int CPEOPLE::getY()
{
	return this->mY;
}

// Set position

void CPEOPLE::setX(int mX)
{
	this->mX = mX;
}


void CPEOPLE::setY(int mY)
{
	this->mY = mY;
}

// Impact animal processing
bool CPEOPLE::isImpact(CANIMAL* obj)
{
	if (mX >= obj->getX() - 1 && mX <= obj->getX() - 1 + obj->getWidth()
		&& mY >= obj->getY() && mY <= obj->getY() + obj->getHeight())
	{
		return true;
	}
	return false;
}

// Impact vehicle processing
bool CPEOPLE::isImpact(CVEHICLE* obj)
{
	if (mX >= obj->getX() - 1 && mX <= obj->getX() - 1 + obj->getWidth()
		&& mY >= obj->getY() && mY <= obj->getY() + obj->getHeight())
	{
		return true;
	}
	return false;
}

// Impact other people
bool CPEOPLE::isImpact(CPEOPLE cn)
{
	if (mX == cn.getX()) return true;
	return false;
}

// Set state (live or not)
void CPEOPLE::setState(bool mState)
{
	this->mState = mState;
}
// Get state (live or not)
bool CPEOPLE::getState()
{
	return mState;
}

// Get with and height
int CPEOPLE::getWidth()
{
	return this->width;
}
int CPEOPLE::getHeight()
{
	return this->height;

}

// Check people is dead or not
bool CPEOPLE::isDead()
{
	return (mState == false);
}

// check people finish challenge or not
bool CPEOPLE::isFinish()
{
	return mY <= 10;
}

