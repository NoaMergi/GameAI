#pragma once

//#include <allegro5/allegro_font.h>
#include "Color.h"
#include <allegro5/allegro_font.h>
#include <string>
#include "Trackable.h"


class Font : public Trackable
{

	friend class GraphicsSystem;

public:
	Font(std::string aMessage, int aFontSize);
	~Font();

	int getSize(){ return mFontSize; }
	inline const ALLEGRO_FONT* getFont() { return mpFont; }

private:

	ALLEGRO_FONT* mpFont;
	int mFontSize;
};

