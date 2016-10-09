#include "Ui.h"
#include "Event.h"
#include "EventListener.h"
#include "GlobalStates.h"
#include <sstream>

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
	gpEventSystem->addListener(REACTION_RAD_CHANGED, this);
	gpEventSystem->addListener(ENEMY_VELOCITY_CHANGED, this);
	gpEventSystem->addListener(ANGULAR_VELOCITY_CHANGED, this);


	mpFont = new Font("cour.ttf", 20);
	

	Vector2D uiPos(mpFont->getSize(), mpFont->getSize());
	Vector2D offsetPos(0, mpFont->getSize());
	Color col;
	stringstream stream; 
	stream << "Enemy velocity control   " << gpGlobalStates->getGlobalEnemyVelocity();
	addText("evc", mpFont, stream.str(), uiPos, col, LEFT);
	stream.str(std::string());

	stream << "Reaction radius          " << gpGlobalStates->getGlobalReactionRadius();
	addText("rr", mpFont, stream.str(), uiPos + offsetPos, col, LEFT);
	stream.str(std::string());

	stream << "Angular velocity         " << gpGlobalStates->getGlobalAngularVelocity();
	addText("av", mpFont, stream.str(), uiPos + offsetPos + offsetPos, col, LEFT);

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

void Ui::resetPos()
{
	map<string, Text*>::iterator iter;
	for (iter = mTextContainer.begin(); iter != mTextContainer.end(); ++iter)
	{
		if (iter->first != "mouse")
		{
			Vector2D newPos = iter->second->getPos();
			newPos.setX(mpFont->getSize());
			iter->second->setPos(newPos);
		}
	}
}

void Ui::showSelection(string selection)
{
	resetPos();
	Vector2D newPos = getText(selection)->getPos();
	newPos.setX(2 * mpFont->getSize());
	getText(selection)->setPos(newPos);
}

void Ui::handleEvent(const Event& theEvent)
{
	if (theEvent.getType() == SELECT_ENEMY_VELOCITY)
	{
		showSelection("evc");
	}
	else if (theEvent.getType() == SELECT_REACTION_RAD)
	{
		showSelection("rr");
		cout << gpGlobalStates->getGlobalReactionRadius();
	}
	else if (theEvent.getType() == SELECT_ANGULAR_VELOCITY)
	{
		showSelection("av");
	}
	else if (theEvent.getType() == DEBUG)
	{
		showUI = !showUI;
	}
	else if (theEvent.getType() == REACTION_RAD_CHANGED)
	{
		const StatChangeEvent& stateChangeEvent = static_cast<const StatChangeEvent&>(theEvent);
		stringstream stream;
		stream << "Reaction radius         " << stateChangeEvent.getVal();
		getText("rr")->setText(stream.str());
	}
	else if (theEvent.getType() == ENEMY_VELOCITY_CHANGED)
	{
		const StatChangeEvent& stateChangeEvent = static_cast<const StatChangeEvent&>(theEvent);
		stringstream stream;
		stream << "Enemy velocity control   " << stateChangeEvent.getVal();
		getText("evc")->setText(stream.str());
	}
	else if (theEvent.getType() == ANGULAR_VELOCITY_CHANGED)
	{
		const StatChangeEvent& stateChangeEvent = static_cast<const StatChangeEvent&>(theEvent);
		stringstream stream;
		stream << "Angular velocity         " << stateChangeEvent.getVal();
		getText("av")->setText(stream.str());
	}
}

/*
gpEventSystem->addListener(INCREASE_SELECTED_VALUE, this);
gpEventSystem->addListener(REDUCE_SELECTED_VAULUE, this);
gpEventSystem->addListener(SELECT_ENEMY_VELOCITY, this);
gpEventSystem->addListener(SELECT_REACTION_RAD, this);
gpEventSystem->addListener(SELECT_ANGULAR_VELOCITY, this);
gpEventSystem->addListener(DEBUG, this);
*/