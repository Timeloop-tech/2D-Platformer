#ifndef _STEP_BUTTON_MODEL_H_
#define _STEP_BUTTON_MODEL_H_

#include "cocos2d.h"
#include "Events.h"
#include "GameElementModel.h"
#include "StepButtonStates.h"
#include "StepButton.h"

class StepButton;

USING_NS_CC;

class StepButtonModel : public GameElementModel
{
private:
	int					m_reactID;
    int					m_stepCount;
	bool				m_isActivated;
	StepButtonStates	m_state;

public:
	StepButtonModel(b2World& world, b2Vec2 position, int ID);
    void steppedOut();
    void steppedOn();
	StepButtonStates getSteppedStatus();
	void dispatchEvent();
    void setUserData(StepButton* stepButton);
};
#endif // !_STEP_BUTTON_MODEL_H_
