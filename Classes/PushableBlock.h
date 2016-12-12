#ifndef _PUSHABLE_BLOCK_H_
#define _PUSHABLE_BLOCK_H_

#include "cocos2d.h"
#include "GameElement.h"
#include "PushableBlockModel.h"
#include "PushableBlockView.h"
#include "Utils.h"

class PushableBlockModel;

USING_NS_CC;

class PushableBlock : public GameElement
{
private:
    PushableBlockModel*     m_pushableBlockModel;
    PushableBlockView*      m_pushableBlockView;    
	int					m_position;
public:
	PushableBlock(b2World& world, int ID, Vec2 position, Node* parent);
};
#endif // !_PUSHABLE_BLOCK_H_

