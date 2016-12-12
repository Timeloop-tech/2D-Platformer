#ifndef _STEP_BUTTON_VIEW_
#define _STEP_BUTTON_VIEW_

#include "cocos2d.h"
#include "GameElementView.h"
#include "StepButtonStates.h"

class StepButtonView : public GameElementView
{
private:
    StepButtonStates      m_state;
    Sprite*               m_spriteON;
    Sprite*               m_spriteOFF;
    
    StepButtonView();
    ~StepButtonView();
    bool init();
    
public:
    static StepButtonView* create();
    void updateState(StepButtonStates state);
};
#endif // !_STEP_BUTTON_VIEW_
