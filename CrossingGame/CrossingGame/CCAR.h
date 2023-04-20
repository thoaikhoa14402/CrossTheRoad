#pragma once
#include"CVEHICLE.h"

class CCAR : public CVEHICLE
{
public:
	CCAR(int x, int y); // Constructor
	virtual void Move(); // Move object CCAR
	virtual void Tell(); // Beep when impacting
};