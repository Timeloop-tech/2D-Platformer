#ifndef _SLIDING_DOOR_MODEL_H_
#define _SLIDING_DOOR_MODEL_H_

#include "cocos2d.h"
#include "GameElementModel.h"
#include "SlidingDoor.h"

class SlidingDoor;

USING_NS_CC;

class SlidingDoorModel : public GameElementModel
{
private:
	const float				m_halfDoorWidth = 0.45f;
	const float				m_halfDoorHeight = 2.0f;
	const b2Vec2			m_linearVelocityWhileOpening;
	const b2Vec2			m_linearVelocityWhileClosing;
	b2Vec2					m_closingPosition;
	b2Vec2					m_startingPosition;
public:
	SlidingDoorModel(b2World& world, b2Vec2 position, int ID);
	void beginOpeningDoor();
	void endOpeningDoor();
	void setLinearVelocity(b2Vec2 velocity);
	b2Vec2 getStartingPosition();
	b2Vec2 getHighestPosition();
	b2Vec2 getCurrentPosition();
	b2Vec2 getLinearVelocity();
	float getDoorHeight();
	void beginClosingDoor();
	void endClosingDoor();
    void setUserData(SlidingDoor* slidingDoor);
};
#endif // !_SLIDING_DOOR_MODEL_H_

