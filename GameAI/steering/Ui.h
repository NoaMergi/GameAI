#pragma once
#include <map>
#include <sstream>
#include "Text.h"
#include "EventListener.h"
#include "Sprite.h"
#include "Game.h"
#include "InputSystem.h"

using namespace std;

class UI : public EventListener
{
public:
	UI();
	~UI();

	void addText(string id, Font* font, string text, Vector2D pos, Color color, int flag);
	void addText(string id, Font* font, string text, Vector2D pos);
	void addText(string id, Font* font, string text);

	void init();


	Text* getText(string id);


	void draw();

	void update(float time);

	void clear();

	void handleEvent(const Event& theEvent) override;

private:

	map<string, Text*> mTextContainer;
	Font* mpFont;
	bool showUI;
	const int selectedOffset = 20;
	//vector<Sprite*> spriteContainer;

};

UI::UI()
{
}

UI::~UI()
{
	clear();
}

void UI::addText(string id, Font* font, string text, Vector2D pos, Color color, int flag)
{
	Text* txt = new Text(font, text, pos, color, flag);
	mTextContainer.insert(pair<string, Text*>(id, txt));
}

void UI::addText(string id, Font* font, string text, Vector2D pos)
{
	Text* txt = new Text(font, text, pos);
	mTextContainer.insert(pair<string, Text*>(id, txt));
}

void UI::addText(string id, Font* font, string text)
{
	Text* txt = new Text(font, text);
	mTextContainer.insert(pair<string, Text*>(id, txt));
}

void UI::init()
{
	al_init_font_addon();
	if (!al_init_ttf_addon())
	{
		printf("ttf font addon not initted properly!\n");
		return;
	}

	mpFont = new Font("cour.ttf", 20);
	addText("mouse", mpFont, "xxx");

	Vector2D uiPos(mpFont->getSize(), mpFont->getSize());
	Vector2D offsetPos(0, mpFont->getSize());
	Color col;

	addText("evc", mpFont, "Enemy velocity control", uiPos, col, LEFT);
	addText("rr", mpFont, "Reaction radius", uiPos + offsetPos, col, LEFT);
	addText("av", mpFont, "angular velocity", uiPos + offsetPos + offsetPos, col, LEFT);
	showUI = false;
}

Text* UI::getText(string id)
{
	return mTextContainer.find(id)->second;
}

void UI::draw()
{
	map<string, Text*>::iterator iter;

	mTextContainer.begin()->second->draw();

	for (iter = ++mTextContainer.begin(); iter != mTextContainer.end(); ++iter)
	{
		iter->second->draw();
	}
}

void UI::update(float time)
{
	stringstream mousePos;
	float x = gpGame->getInputSystem()->getMouseX();
	float y = gpGame->getInputSystem()->getMouseY();

	mousePos << x << ":" << y;

	getText("mouse")->setText(mousePos.str());
	getText("mouse")->setPos(Vector2D(x,y));

}

void UI::clear()
{
	map<string, Text*>::iterator iter;

	for (iter = mTextContainer.begin(); iter != mTextContainer.end(); ++iter)
	{
		delete iter->second;
		iter->second = nullptr;
	}
	delete mpFont;
	mpFont = nullptr;
}

void UI::handleEvent(const Event& theEvent)
{
	
}