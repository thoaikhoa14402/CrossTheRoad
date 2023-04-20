#include"CBIRD.h"

CBIRD::CBIRD(int x, int y) : CANIMAL(x, y)
{ 
	width = 9, height = 1; 
};

void CBIRD::Move()
{
	this->mX += 2;
	if (mX >= 105)
	{
		CCONSOLE::removeSpace(POINT{ mX - 2, mY }, POINT{ mX + width, mY + height });
		moving_state = false;
		mX = 2;
	}
	else
	{
		CCONSOLE::removeSpace(POINT{ mX - 2,mY }, POINT{ mX, mY + height });
		CCONSOLE::drawGraphics("cgame/cbird.txt", POINT{ mX,mY }, lightpurple);
	}
}

// Tell
void CBIRD::Tell()
{
	CCONSOLE::playMusic("bird");
}