#include"CANIMAL.h"

class CBIRD : public CANIMAL
{
public:
	CBIRD(int x, int y); // Constructor
	virtual void Move(); // Move Object CBIRD
	virtual void Tell(); // Tell when impacting
};