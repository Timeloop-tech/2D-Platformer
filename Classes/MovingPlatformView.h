#ifndef _MOVING_PLATFORM_VIEW_H_
#define _MOVING_PLATFORM_VIEW_H_

#include "GameElementView.h"

class MovingPlatformView : public GameElementView
{
private:
    Sprite*               m_sprite;
    
    MovingPlatformView();
    ~MovingPlatformView();
    bool init();
    
public:
    static MovingPlatformView* create();
};
#endif // !_MOVING_PLATFORMS_VIEW_H_

