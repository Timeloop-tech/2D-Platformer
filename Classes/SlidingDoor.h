#ifndef _SLIDING_DOOR_H_
#define _SLIDING_DOOR_H_

#include "cocos2d.h"
#include "GameElement.h"
#include "Utils.h"
#include "SlidingDoorModel.h"
#include "SlidingDoorView.h"
#include "Events.h"

class SlidingDoorModel;

USING_NS_CC;

class SlidingDoor : public GameElement
{
private:
    SlidingDoorModel*   m_slidingDoorModel;
    SlidingDoorView*    m_slidingDoorView;
	int					m_slidingDoorID;
	int					m_reactID;
public:
	SlidingDoor(b2World& world, Vec2 position,int ID, int reactID, Node* parent);
	void endOpeningDoor(float dt);
	void beginOpeningDoor();
	void onPushButtonActivation(int ID);
	void onPushButtonDeactivation(int ID);
	void onStepButtonActivation(int ID);
	void onStepButtonDeactivation(int ID);
	void beginClosingDoor();
	void endClosingDoor(float dt);
    void setLinearVelocity(b2Vec2 velocity);
};
#endif // !_SLIDING_DOOR_H_

