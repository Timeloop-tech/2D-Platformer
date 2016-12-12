#ifndef _STEP_BUTTON_H_
#define _STEP_BUTTON_H_

#include "cocos2d.h"
#include "GameElement.h"
#include "StepButtonModel.h"
#include "StepButtonView.h"
#include "StepButtonStates.h"

class StepButtonModel;

USING_NS_CC;

class StepButton : public GameElement
{
private:
    StepButtonModel*    m_stepButtonModel;
    StepButtonView*     m_stepButtonView;
	int					m_stepButtonID;
	int					m_reactID;
    
public:
    static int			m_countTotal;
    
	StepButton(b2World& world, Vec2 position, int ID, int reactID, Node* parent);
    StepButtonStates getSteppedStatus();
    
    void steppedOut();
    void steppedOn();
    void dispatchEvent();
};
#endif // !_STEP_BUTTON_H_
