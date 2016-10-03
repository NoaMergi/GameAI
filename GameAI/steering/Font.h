#pragma once

#include <allegro5/allegro_font.h>
#include "Color.h"
#include <string>
#include "Trackable.h"

/*

Data

·         Allegro font

·         Font size

Functions

·         Constructor/destructor

·         Accessors (size)

Color??? – Many ways to do this
*/

class Font : Trackable
{

	friend class GraphicsSystem;

public:
	Font(std::string aMessage, int aFontSize);
	~Font(){}

	int getSize(){ return mFontSize; }

private:

	ALLEGRO_FONT* mpFont;
	int mFontSize;
	Color mColor;
	std::string mString;
};

