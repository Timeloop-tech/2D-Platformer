//
//  SlidingDoorView.cpp
//  TimeTale
//
//  Created by Hema Dubal on 25/05/16.
//
//

#include "SlidingDoorView.h"

SlidingDoorView::SlidingDoorView()
{
    
}

SlidingDoorView::~SlidingDoorView()
{
    
}

/* static */ SlidingDoorView* SlidingDoorView::create()
{
    SlidingDoorView* view = new SlidingDoorView();
    if (view && view->init())
    {
        return view;
    }
    delete view;
    return nullptr;
}

bool SlidingDoorView::init()
{
    m_sprite = Sprite::create("sliding_door.png");
    addChild(m_sprite);
    return true;
}
