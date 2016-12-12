#ifndef _PUSH_BUTTON_H_
#define _PUSH_BUTTON_H_

#include "cocos2d.h"
#include "GameElement.h"
#include "PushButtonView.h"
#include "PushButtonModel.h"
#include "PushButtonStates.h"
#include "Events.h"

class PushButtonModel;

USING_NS_CC;

class PushButton : public GameElement
{
private:
    PushButtonModel*    m_pushButtonModel;
    PushButtonView*     m_pushButtonView;
	int					m_pushButtonID;
public:
	PushButton(b2World& world, Vec2 position, int ID, int reactID, Node* parent);
	PushButtonStates getPushButtonState();
	void setPushButtonState(PushButtonStates state);
	bool getInteractionStatus();
	void setInteractionStatus(bool status);
    void dispatchEvent();
};
#endif // !_PUSH_BUTTON_H_

