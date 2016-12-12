#ifndef _LIFT_VIEW_H_
#define _LIFT_VIEW_H_

#include "GameElementView.h"

class LiftView : public GameElementView
{
private:
    Sprite*               m_sprite;
    
    LiftView();
    ~LiftView();
    bool init();
    
public:
    static LiftView* create();
};

#endif // !_LIFT_VIEW_H_

