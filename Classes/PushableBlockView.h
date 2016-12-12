#ifndef _PUSHABLE_BLOCK_VIEW_H_
#define _PUSHABLE_BLOCK_VIEW_H_

#include "GameElementView.h"
#include "cocos2d.h"

USING_NS_CC;

class PushableBlockView : public GameElementView
{
private:
    Sprite*               m_sprite;
    
    PushableBlockView();
    ~PushableBlockView();
    bool init();
    
public:
    static PushableBlockView* create();
};
#endif // !_PUSHABLE_BLOCK_VIEW_H_

