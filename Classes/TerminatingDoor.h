#ifndef _TERMINATING_DOOR_H_
#define _TERMINATING_DOOR_H_

#include "GameElement.h"
#include "TerminatingDoorModel.h"
#include "TerminatingDoorView.h"
#include "cocos2d.h"
#include "Utils.h"

class TerminatingDoorModel;

USING_NS_CC;

class TerminatingDoor : public GameElement
{
private:
    TerminatingDoorModel*   m_terminatingDoorModel;
    TerminatingDoorView*    m_terminatingDoorView;
    
public :
	TerminatingDoor(b2World& world, Vec2 position, Node* parent);
    bool getInteractionStatus();
    void setInteractionStatus(bool status);
};

#endif // !_TERMINATING_DOOR_H_

