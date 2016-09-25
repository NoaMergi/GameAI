#include "UnitManager.h"



UnitManager::UnitManager()
{
	gpEventSystem->addListener(ADD_DINAMIC_ARRIVE, this);
	gpEventSystem->addListener(ADD_DINAMIC_SEEK, this);
	gpEventSystem->addListener(DELETE_UNIT, this);
	doesPlayerExist = false;
}

UnitManager::~UnitManager()
{
	gpEventSystem->removeListenerFromAllEvents(this);
	clear();
}

KinematicUnit* UnitManager::getUnit(int aKey)
{
	vector<KinematicUnit*>::iterator iter;

	for (iter = mUnitList.begin() + 1; iter != mUnitList.end(); iter++)
	{
		return * iter;
	}
	return nullptr;
}

void UnitManager::addPlayer(KinematicUnit* aUnit)
{
	if (doesPlayerExist)
		return;

	mUnitList.insert(mUnitList.begin(), aUnit);
	doesPlayerExist = true;
}

void UnitManager::addPlayer(Sprite *pSprite, const Vector2D &position, float orientation, const Vector2D &velocity, float rotationVel)
{
	if (doesPlayerExist)
		return;
	KinematicUnit* tempUnit = new KinematicUnit(pSprite, position, orientation, velocity, rotationVel);
	addPlayer(tempUnit);
}

void UnitManager::addUnit(KinematicUnit* aUnit, ai behavior, KinematicUnit* target)
{
	//set ai behavior
	KinematicUnit* theTarget = target;
	if (theTarget == nullptr)
		theTarget = getPlayerUnit();

	if (behavior == SEEK)
		aUnit->dynamicSeek(theTarget);
	else if (behavior == ARRIVE)
		aUnit->dynamicArrive(theTarget);

	mUnitList.push_back(aUnit);
}

void UnitManager::addUnit(Sprite *pSprite, const Vector2D &position, float orientation, const Vector2D &velocity, float rotationVel, ai behavior, KinematicUnit* target)
{
	KinematicUnit* tempUnit = new KinematicUnit(pSprite, position, orientation, velocity, rotationVel);
	addUnit(tempUnit, behavior);
}

KinematicUnit* UnitManager::getPlayerUnit()
{
	if (doesPlayerExist)
		return mUnitList[0];
	return nullptr;
}

void UnitManager::deleteUnit(int index)
{/*
	if (iterator != mUnitList.end())
	{
		delete *iterator;
		mUnitList.erase(iterator);
	}*/
	vector<KinematicUnit*>::iterator iterator = mUnitList.begin() + index;
	delete *iterator;
	mUnitList.erase(iterator);

}

void UnitManager::clear()
{
	vector<KinematicUnit*>::iterator iter;

	for (iter = mUnitList.begin(); iter != mUnitList.end(); iter++)
	{
		delete *iter;
	}
	//myIntVector.erase(myIntVectorIterator.begin(), myIntVectorIterator.end());
	mUnitList.clear();
}

void UnitManager::update(float time)
{
	vector<KinematicUnit*>::iterator iter;

	for (iter = mUnitList.begin(); iter != mUnitList.end(); iter++)
	{
		(*iter)->update(time);
	}
}

void UnitManager::draw(GraphicsBuffer* pBuffer)
{	
	vector<KinematicUnit*>::iterator iter;

	for (iter = mUnitList.begin(); iter != mUnitList.end(); iter++)
	{
		(*iter)->draw(pBuffer);
	}
}

void UnitManager::handleEvent(const Event& theEvent)
{
	if (theEvent.getType() == DELETE_UNIT)
	{
		if (mUnitList.size() <= 1)
		{
			gpEventSystem->fireEvent(QUIT_GAME);
			return;
		}
		int start;

		default_random_engine generator(mRandom());
		if (doesPlayerExist)
			start = 1;
		else
			start = 0;

		std::uniform_int_distribution<int> distribution(start, mUnitList.size() - 1);
		deleteUnit(distribution(generator));
	}
	
	
	//const MousePosEvent& mousePosEvent = static_cast<const MousePosEvent&>(theEvent);
	if (theEvent.getType() == ADD_DINAMIC_ARRIVE)
	{
		KinematicUnit* tempUnit = new KinematicUnit(*mpCurrentUnit);
		Vector2D tempPos(mousePosEvent.getPos().getX() - (tempUnit->getWidth() / 2.0), mousePosEvent.getPos().getY() - (tempUnit->getHight() / 2.0));
		tempUnit->setPos(tempPos);
		addUnit(tempUnit);
	}/*
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
	}*/
}