#include"CTRUCK.h"

CTRUCK::CTRUCK(int x, int y) : CVEHICLE(x, y)
{
	width = 12, height = 3;
};

void CTRUCK::Move()
{
	if (!tl_state) { CCONSOLE::drawGraphics("cgame/ctruck2.txt", POINT{ mX,mY }, 6); return; } // red time
	this->mX -= 3;
	if (mX <= 2)
	{
		CCONSOLE::removeSpace(POINT{ mX + 3, mY }, POINT{ mX + 3 + width, mY + height });
		moving_state = false;
		mX = 104;
	}
	else
	{
		CCONSOLE::removeSpace(POINT{ mX + 3, mY }, POINT{ mX + 3 + width ,mY + height });
		CCONSOLE::drawGraphics("cgame/ctruck2.txt", POINT{ mX,mY }, 6);
	}
}

void CTRUCK::Tell()
{
	CCONSOLE::playMusic("car");
}