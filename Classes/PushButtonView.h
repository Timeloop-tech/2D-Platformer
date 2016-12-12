#ifndef _PUSH_BUTTON_VIEW_H_
#define _PUSH_BUTTON_VIEW_H_

#include "cocos2d.h"
#include "GameElementView.h"
#include "PushButtonStates.h"

USING_NS_CC;

class PushButtonView : public GameElementView
{
private:
    PushButtonStates      m_state;
    Sprite*               m_spriteON;
    Sprite*               m_spriteOFF;
    
    PushButtonView();
    ~PushButtonView();
    bool init();
    
public:
    static PushButtonView* create();
    void updateState(PushButtonStates state);
};
#endif // !_PUSH_BUTTON_VIEW_H_
