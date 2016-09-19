#include "UnitManager.h"

int UnitManager::mID = 0;

UnitManager::UnitManager()
{
	gpEventSystem->addListener(ADD_DINAMIC_ARRIVE, this);
	gpEventSystem->addListener(ADD_DINAMIC_SEEK, this);
	gpEventSystem->addListener(DELETE_UNIT, this);
}

UnitManager::~UnitManager()
{
	delete mpCurrentUnit;
	mpCurrentUnit = nullptr;
	gpEventSystem->removeListenerFromAllEvents(this);
	clear();
}

Unit* UnitManager::getUnit(int aKey)
{
	map<int, Unit*>::iterator iter;

	for (iter = mUnitList.begin(); iter != mUnitList.end(); iter++)
	{
		if (iter->first == aKey)
		{
			return iter->second;
		}
	}
	return nullptr;
}

void UnitManager::addUnit(Unit* aUnit)
{
	mUnitList.insert(pair<int, Unit*>(mID, aUnit));
	mID++;
}

void UnitManager::addUnit(GraphicsBuffer* aSpriteSheet, int aRow, int aColumn, Vector2D aPos, double aDefaultFps, IsLooping aIsLooping)
{
	Unit* tempUnit = new Unit(aSpriteSheet, aRow, aColumn, aSpriteSheet->getWidth() / aColumn, aSpriteSheet->getHeight() / aRow, aPos, aDefaultFps, aIsLooping);
	addUnit(tempUnit);
}

void UnitManager::addUnit(Sprite aSprite, Vector2D aPos)
{
	Unit* tempUnit = new Unit(aSprite, aPos);
	addUnit(tempUnit);
}

void UnitManager::deleteUnit(int akey)
{
	map<int, Unit*>::iterator iterator = mUnitList.find(akey);

	if (iterator != mUnitList.end())
	{
		delete iterator->second;
		mUnitList.erase(iterator);
	}
	

}

void UnitManager::clear()
{
	map<int, Unit*>::iterator iter;

	for (iter = mUnitList.begin(); iter != mUnitList.end(); iter++)
	{
		delete iter->second;
	}
	mUnitList.clear();
}

void UnitManager::update(Timer* aDelta, double aError)
{
	map<int, Unit*>::iterator iter;

	for (iter = mUnitList.begin(); iter != mUnitList.end(); iter++)
	{
		iter->second->update(aDelta, aError);
	}
}

void UnitManager::render(GraphicsSystem* aGraphicsSystem, float aSize)
{
	map<int, Unit*>::iterator iter;

	for (iter = mUnitList.begin(); iter != mUnitList.end(); iter++)
	{
		iter->second->render(aGraphicsSystem, aSize);
	}
}

void UnitManager::handleEvent(const Event& theEvent)
{
	const MousePosEvent& mousePosEvent = static_cast<const MousePosEvent&>(theEvent);
	if (theEvent.getType() == ADD_UNIT)
	{
		Unit* tempUnit = new Unit(*mpCurrentUnit);
		Vector2D tempPos(mousePosEvent.getPos().getX() - (tempUnit->getWidth() / 2.0), mousePosEvent.getPos().getY() - (tempUnit->getHight() / 2.0));
		tempUnit->setPos(tempPos);
		addUnit(tempUnit);
	}
	else
	{
		map<int, Unit*>::iterator iter;

		for (iter = mUnitList.begin(); iter != mUnitList.end();++iter)
		{
			if (rectangleCollition(Meshulash(mousePosEvent.getPos().getX(), mousePosEvent.getPos().getY(), 1, 1), iter->second->getCollitionRectangle()))
			{
				deleteUnit(iter->first);
				break;
			}
		}
	}
}