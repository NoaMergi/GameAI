#pragma once

#include "Font.h"
#include "string"
#include "Color.h"
#include "Vector2D.h"
#include "Trackable.h"

using namespace std;

class Text : public Trackable
{
public:
	Text(Font* font, string text, Vector2D pos, Color color, int flag = ALLEGRO_ALIGN_CENTRE);
	Text(Font* font, string text, Vector2D pos);
	~Text();

	inline void setText(string text) { mText = text; }

	void draw();
	void draw(Vector2D pos);
	void draw(Vector2D pos, string text);


private:

	Font* mpFont;
	string mText;
	Color mColor;
	Vector2D mPos;
	int mFlag;

};

