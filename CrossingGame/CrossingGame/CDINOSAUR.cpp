#include"CDINOSAUR.h"


CDINOSAUR::CDINOSAUR(int x, int y) : CANIMAL(x, y)
{
	width = 9, height = 4; 
};


void CDINOSAUR::Move()
{
	this->mX += 3;
	if (mX >= 104)
	{
		CCONSOLE::removeSpace(POINT{ mX - 3, mY }, POINT{ mX + width, mY + height });
		moving_state = false;
		mX = 2;
	}
	else
	{
		CCONSOLE::removeSpace(POINT{ mX - 3,mY }, POINT{ mX, mY + height });
		CCONSOLE::drawGraphics("cgame/cdinosaur.txt", POINT{ mX,mY }, lightaqua);
	}
}

void CDINOSAUR::Tell()
{
	CCONSOLE::playMusic("dinosaur");
}