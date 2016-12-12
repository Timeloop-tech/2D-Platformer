#include "PushableBlockView.h"

PushableBlockView::PushableBlockView()
{
    
}

PushableBlockView::~PushableBlockView()
{
    
}

/* static */ PushableBlockView* PushableBlockView::create()
{
    PushableBlockView* view = new PushableBlockView();
    if (view && view->init())
    {
        return view;
    }
    delete view;
    return nullptr;
}

bool PushableBlockView::init()
{
    m_sprite = Sprite::create("box.png");
    addChild(m_sprite);
    return true;
}