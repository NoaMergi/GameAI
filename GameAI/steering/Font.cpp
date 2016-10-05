#include "Font.h"
#include <allegro5/allegro_ttf.h>
#include <iostream>
#include <string>



Font::Font(std::string aMessage, int aFontSize)
{
	std::cout << aMessage;
	mpFont = al_load_ttf_font(aMessage.c_str(), aFontSize, 0);
	if (mpFont == NULL)
	{
		printf("ttf font file not loaded properly!\n");
		return;
	}

	mFontSize = aFontSize;
}

Font::~Font()
{
	al_destroy_font(mpFont);

	mpFont = NULL;
}