#include "Text.h"

Text::Text(Font* font, string text, Vector2D pos, Color color, int flag)
{
	init(font, text, pos, color, flag);
}

Text::Text(Font* font, string text, Vector2D pos)
{
	Color color;
	init(font, text, pos, color, ALLEGRO_ALIGN_CENTRE);
}

Text::Text(Font* font, string text)
{
	Vector2D pos(0, 0);
	Color color;
	init(font, text, pos, color, ALLEGRO_ALIGN_CENTRE);
}

Text::~Text()
{

}

void Text::init(Font* font, string text, Vector2D pos, Color color, int flag)
{
	mpFont = font;
	mText = text;
	mColor = color;
	mPos = pos;
	mFlag = flag;
}

void Text::draw()
{
	al_draw_text(mpFont->getFont(), al_map_rgb(mColor.a(), mColor.g(), mColor.b()), mPos.getX(), mPos.getY(), mFlag, mText.c_str());
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

void Text::draw(float x, float y, string text)
{
	mPos = Vector2D(x, y);
	mText = text;
	draw();
}