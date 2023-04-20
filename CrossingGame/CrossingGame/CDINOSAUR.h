#include"CANIMAL.h"

class CDINOSAUR : public CANIMAL
{
public:
	CDINOSAUR(int x, int y); // Constructor
	virtual void Move(); // Move object CDINOSAUR
	virtual void Tell(); // Tell when impacting
};