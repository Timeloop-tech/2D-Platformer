#ifndef _PUSH_BUTTON_MODEL_H_
#define _PUSH_BUTTON_MODEL_H_

#include "cocos2d.h"
#include "GameElementModel.h"
#include "Events.h"
#include "PushButtonStates.h"
#include "PushButton.h"

class PushButton;

USING_NS_CC;

class PushButtonModel : public GameElementModel
{
private:
	PushButtonStates    m_state;
	bool			m_interactionEnabled;
	bool			m_isActivated;
	int				m_reactID;
public:
	PushButtonModel(b2World& world, b2Vec2 position, int reactID);
	PushButtonStates getPushButtonState();
	void setPushButtonState(PushButtonStates state);
	bool getInteractionStatus();
	void setInteractionStatus(bool status);
	void dispatchEvent();
    void setUserData(PushButton* pushButton);
};
#endif // !_PUSH_BUTTON_MODEL_H_
