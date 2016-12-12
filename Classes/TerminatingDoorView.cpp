#include "TerminatingDoorView.h"

TerminatingDoorView::TerminatingDoorView()
{
    
}

TerminatingDoorView::~TerminatingDoorView()
{
    
}

/* static */ TerminatingDoorView* TerminatingDoorView::create()
{
    TerminatingDoorView* view = new TerminatingDoorView();
    if (view && view->init())
    {
        return view;
    }
    delete view;
    return nullptr;
}

bool TerminatingDoorView::init()
{
    m_sprite = Sprite::create("door_open.png");
    addChild(m_sprite);
    return true;
}