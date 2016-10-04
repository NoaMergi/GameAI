#include "Text.h"

Text::Text(Font* font, string text, Vector2D pos, Color color, int flag)
{
	mpFont = font;
	mText = text;
	mColor = color;
	mPos = pos;
	mFlag = flag;
}

Text::Text(Font* font, string text, Vector2D pos)
{
	Color color;
	Text(font, text, pos, color, ALLEGRO_ALIGN_CENTRE);
}

Text::~Text()
{

}

void Text::draw()
{
	//al_draw_text(mpFont->getFont(), al_map_rgb(mColor.a(), mColor.g(), mColor.b()), mPos.getX(), mPos.getY(), mFlag, mText.c_str());
}

void Text::draw(Vector2D pos)
{
	mPos = pos;
	draw();
}

void Text::draw(Vector2D pos, string text)
{
	mPos = pos;
	mText = text;
	draw();
}