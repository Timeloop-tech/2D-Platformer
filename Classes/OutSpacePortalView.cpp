#include "OutSpacePortalView.h"

OutSpacePortalView::OutSpacePortalView()
{
    
}

OutSpacePortalView::~OutSpacePortalView()
{
    
}

/* static */ OutSpacePortalView* OutSpacePortalView::create()
{
    OutSpacePortalView* view = new OutSpacePortalView();
    if (view && view->init())
    {
        return view;
    }
    delete view;
    return nullptr;
}

bool OutSpacePortalView::init()
{
    m_sprite = Sprite::create("out_portal.png");
    addChild(m_sprite);
    return true;
}