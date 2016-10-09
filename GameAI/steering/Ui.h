#pragma once
#include <map>
#include <sstream>
#include "Text.h"
#include "EventListener.h"
#include "Sprite.h"
#include "Game.h"
#include "InputSystem.h"

using namespace std;

class Ui : public EventListener
{
public:
	Ui();
	~Ui();

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

	void resetPos();
	void showSelection(string selection);

	map<string, Text*> mTextContainer;
	Font* mpFont;
	bool showUI;
	const int selectedOffset = 20;
	//vector<Sprite*> spriteContainer;

};

