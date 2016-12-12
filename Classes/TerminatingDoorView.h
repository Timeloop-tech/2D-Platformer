#ifndef _TERMINATING_DOOR_VIEW_H_
#define _TERMINATING_DOOR_VIEW_H_

#include "GameElementView.h"
#include "cocos2d.h"

class TerminatingDoorView : public GameElementView
{
private:
    Sprite*               m_sprite;
    
    TerminatingDoorView();
    ~TerminatingDoorView();
    bool init();
    
public:
    static TerminatingDoorView* create();
};
#endif // !_TERMINATING_DOOR_VIEW_H_

