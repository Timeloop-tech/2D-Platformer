#ifndef _OUT_SPACE_PORTAL_VIEW_H_
#define _OUT_SPACE_PORTAL_VIEW_H_

#include "GameElementView.h"
#include "cocos2d.h"

class OutSpacePortalView : public GameElementView
{
private:
    Sprite*               m_sprite;
    
    OutSpacePortalView();
    ~OutSpacePortalView();
    bool init();
    
public:
    static OutSpacePortalView* create();
};
#endif

