#include "Ui.h"
#include "Event.h"
#include "EventListener.h"

Ui::Ui()
{
}

Ui::~Ui()
{
	clear();
}

void Ui::addText(string id, Font* font, string text, Vector2D pos, Color color, int flag)
{
	Text* txt = new Text(font, text, pos, color, flag);
	mTextContainer.insert(pair<string, Text*>(id, txt));
}

void Ui::addText(string id, Font* font, string text, Vector2D pos)
{
	Text* txt = new Text(font, text, pos);
	mTextContainer.insert(pair<string, Text*>(id, txt));
}

void Ui::addText(string id, Font* font, string text)
{
	Text* txt = new Text(font, text);
	mTextContainer.insert(pair<string, Text*>(id, txt));
}

void Ui::init()
{
	gpEventSystem->addListener(INCREASE_SELECTED_VALUE, this);
	gpEventSystem->addListener(REDUCE_SELECTED_VAULUE, this);
	gpEventSystem->addListener(SELECT_ENEMY_VELOCITY, this);
	gpEventSystem->addListener(SELECT_REACTION_RAD, this);
	gpEventSystem->addListener(SELECT_ANGULAR_VELOCITY, this);
	gpEventSystem->addListener(DEBUG, this);


	mpFont = new Font("cour.ttf", 20);
	

	Vector2D uiPos(mpFont->getSize(), mpFont->getSize());
	Vector2D offsetPos(0, mpFont->getSize());
	Color col;

	addText("evc", mpFont, "Enemy velocity control", uiPos, col, LEFT);
	addText("rr", mpFont, "Reaction radius", uiPos + offsetPos, col, LEFT);
	addText("av", mpFont, "angular velocity", uiPos + offsetPos + offsetPos, col, LEFT);

	addText("mouse", mpFont, "xxx");
	showUI = false;
}

Text* Ui::getText(string id)
{
	return mTextContainer.find(id)->second;
}

void Ui::draw()
{
	map<string, Text*>::iterator iter;

	if (showUI)
	{
		for (iter = mTextContainer.begin(); iter != mTextContainer.end(); ++iter)
		{
			iter->second->draw();
		}
	}
	else
	{
		getText("mouse")->draw();
	}
}

void Ui::update(float time)
{
	stringstream mousePos;
	float x = gpGame->getInputSystem()->getMouseX();
	float y = gpGame->getInputSystem()->getMouseY();

	mousePos << x << ":" << y;

	getText("mouse")->setText(mousePos.str());
	getText("mouse")->setPos(Vector2D(x, y));

}

void Ui::clear()
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

void Ui::handleEvent(const Event& theEvent)
{
	if (theEvent.getType() == INCREASE_SELECTED_VALUE)
	{
		//getText("evc")->setPos()
	}
	else if (theEvent.getType() == DEBUG)
	{
		showUI = !showUI;
	}
}