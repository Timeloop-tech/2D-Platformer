#include "InSpacePortalView.h"

InSpacePortalView::InSpacePortalView()
{
    
}

InSpacePortalView::~InSpacePortalView()
{
    
}

/* static */ InSpacePortalView* InSpacePortalView::create()
{
    InSpacePortalView* view = new InSpacePortalView();
    if (view && view->init())
    {
        return view;
    }
    delete view;
    return nullptr;
}

bool InSpacePortalView::init()
{
    m_sprite = Sprite::create("in_portal.png");
    addChild(m_sprite);
    return true;
}