#ifndef _GAME_ELEMENT_VIEW_H_
#define _GAME_ELEMENT_VIEW_H_

#include "cocos2d.h"

USING_NS_CC;

class GameElementView : public Node
{
public:
    bool initWithSprite(std::string path);
    bool initWithSpriteSequence(std::string path);
    void updateState();
};

#endif