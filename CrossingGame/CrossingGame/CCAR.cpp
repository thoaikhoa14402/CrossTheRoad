#include"CCAR.h"

CCAR::CCAR(int x, int y) : CVEHICLE(x, y)
{ 
	width = 13, height = 3; 
};

void CCAR::Move()
{
	if (!tl_state) {CCONSOLE::drawGraphics("cgame/ccar.txt", POINT{ mX,mY }, lightblue); return; } // red time
	this->mX += 3;
	if (mX >= 101)
	{
		CCONSOLE::removeSpace(POINT{ mX - 3,mY }, POINT{ mX + width, mY + height });
		moving_state = false;
		mX = 2;
	}
	else
	{
		CCONSOLE::removeSpace(POINT{ mX - 3,mY }, POINT{ mX,mY + height });
		CCONSOLE::drawGraphics("cgame/ccar.txt", POINT{ mX,mY }, lightblue);
	}
}

void CCAR::Tell()
{
	CCONSOLE::playMusic("car");
}