//
//  MovingPlatformView.cpp
//  TimeTale
//
//  Created by Hema Dubal on 25/05/16.
//
//

#include "MovingPlatformView.h"

MovingPlatformView::MovingPlatformView()
{
    
}

MovingPlatformView::~MovingPlatformView()
{
    
}

/* static */ MovingPlatformView* MovingPlatformView::create()
{
    MovingPlatformView* view = new MovingPlatformView();
    if (view && view->init())
    {
        return view;
    }
    delete view;
    return nullptr;
}

bool MovingPlatformView::init()
{
    m_sprite = Sprite::create("lift.png");
    m_sprite->setAnchorPoint(Vec2(0.0f, 1.0f));
    m_sprite->cocos2d::Node::setPosition(0, 0);
    addChild(m_sprite);
    return true;
}