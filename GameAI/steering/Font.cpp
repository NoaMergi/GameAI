#include "Font.h"
#include <allegro5/allegro_ttf.h>
#include <string>



Font::Font(std::string aMessage, int aFontSize)
{
	mpFont = al_load_ttf_font(aMessage.c_str(), aFontSize, 0);
	mFontSize = aFontSize;
	mColor.setColor(0, 0, 0);
}
