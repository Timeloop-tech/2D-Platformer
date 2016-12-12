#include "PushButtonView.h"

PushButtonView::PushButtonView()
{
    m_state = PushButtonStates::OFF;
}

PushButtonView::~PushButtonView()
{
    
}

/* static */ PushButtonView* PushButtonView::create()
{
    PushButtonView* view = new PushButtonView();
    if (view && view->init())
    {
        return view;
    }
    delete view;
    return nullptr;
}

bool PushButtonView::init()
{
    m_spriteON = Sprite::create("push_button_on.png");
    m_spriteOFF = Sprite::create("push_button_off.png");
    addChild(m_spriteON);
    addChild(m_spriteOFF);
    //m_spriteOFF->setPositionX(m_spriteOFF->getBoundingBox().size.width/2);
    //m_spriteOFF->setPositionY(m_spriteOFF->getBoundingBox().size.height/2);
    //m_spriteON->setPositionX(m_spriteON->getBoundingBox().size.width/2);
    //m_spriteON->setPositionY(m_spriteON->getBoundingBox().size.height/2);
    updateState(PushButtonStates::OFF);
    return true;
}

void PushButtonView::updateState(PushButtonStates state)
{
    switch (state) {
        case PushButtonStates::ON:
            m_spriteON->setVisible(true);
            m_spriteOFF->setVisible(false);
            break;
        case PushButtonStates::OFF:
            m_spriteON->setVisible(false);
            m_spriteOFF->setVisible(true);
            break;
    }
}
