#pragma once

#include "Font.h"
#include "string"
#include "Color.h"
#include "Vector2D.h"
#include "Trackable.h"

using namespace std;

enum FontFlag
{
	LEFT = ALLEGRO_ALIGN_LEFT,
	RIGHT = ALLEGRO_ALIGN_RIGHT,
	CENTER = ALLEGRO_ALIGN_CENTRE
};

class Text : public Trackable
{
public:
	Text(Font* font, string text, Vector2D pos, Color color, int flag = ALLEGRO_ALIGN_CENTRE);
	Text(Font* font, string text, Vector2D pos);
	Text(Font* font, string text);
	~Text();

	inline void setText(string text) { mText = text; }
	inline Vector2D getPos() { return mPos; }
	inline void setPos(Vector2D pos) { mPos = pos; }

	void draw();
	void draw(Vector2D pos);
	void draw(Vector2D pos, string text);
	void draw(float x, float y, string text);


private:
	void init(Font* font, string text, Vector2D pos, Color color, int flag);

	Font* mpFont;
	string mText;
	Color mColor;
	Vector2D mPos;
	int mFlag;

};

