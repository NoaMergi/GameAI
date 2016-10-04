
#include "Color.h"

Color::Color(int aR, int aG, int aB, int aA)
{
	setColor(aR, aG, aB, aA);
}


void Color::setColor(int aR, int aG, int aB, int aA)
{
	mR = aR;
	mG = aG;
	mB = aB;
	mA = aA;
}


