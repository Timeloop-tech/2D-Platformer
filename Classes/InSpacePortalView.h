#ifndef _IN_SPACE_PORTAL_VIEW_H_
#define _IN_SPACE_PORTAL_VIEW_H_

#include "GameElementView.h"
#include "cocos2d.h"

class InSpacePortalView : public GameElementView
{
private:
    Sprite*               m_sprite;
    
    InSpacePortalView();
    ~InSpacePortalView();
    bool init();
    
public:
    static InSpacePortalView* create();
};
#endif
