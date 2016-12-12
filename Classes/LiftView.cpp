#include "LiftView.h"

LiftView::LiftView()
{
    
}

LiftView::~LiftView()
{
    
}

/* static */ LiftView* LiftView::create()
{
    LiftView* view = new LiftView();
    if (view && view->init())
    {
        return view;
    }
    delete view;
    return nullptr;
}

bool LiftView::init()
{
    m_sprite = Sprite::create("lift.png");
    m_sprite->setAnchorPoint(Vec2(0.0f, 1.0f));
    m_sprite->cocos2d::Node::setPosition(0, 0);
    addChild(m_sprite);
    return true;
}