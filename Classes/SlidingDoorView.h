#ifndef _SLIDING_DOOR_VIEW_H_
#define _SLIDING_DOOR_VIEW_H_

#include "GameElementView.h"

class SlidingDoorView : public GameElementView
{
private:
    Sprite*               m_sprite;
    
    SlidingDoorView();
    ~SlidingDoorView();
    bool init();
    
public:
    static SlidingDoorView* create();
};
#endif // !_SLIDING_DOOR_VIEW_H_