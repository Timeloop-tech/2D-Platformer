#ifndef _TERMINATING_DOOR_MODEL_H_
#define _TERMINATING_DOOR_MODEL_H_

#include "GameElementModel.h"
#include "cocos2d.h"
#include "TerminatingDoor.h"

class TerminatingDoor;

USING_NS_CC;

class TerminatingDoorModel : public GameElementModel
{
private:
	bool					m_interactionEnabled;
	const float				m_halfDoorWidth = 1.7f;
	const float				m_halfDoorHeight = 2.0f;
public :
	TerminatingDoorModel(b2World& world, b2Vec2 position);
    bool getInteractionStatus();
	void setInteractionStatus(bool status);
    void setUserData(TerminatingDoor* terminatingDoor);
};
#endif // !_TERMINATING_DOOR_MODEL_H_

