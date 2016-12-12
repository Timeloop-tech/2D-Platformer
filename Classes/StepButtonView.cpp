#include "StepButtonView.h"

StepButtonView::StepButtonView()
{
    m_state = StepButtonStates::OFF;
}

StepButtonView::~StepButtonView()
{
    
}

/* static */ StepButtonView* StepButtonView::create()
{
    StepButtonView* view = new StepButtonView();
    if (view && view->init())
    {
        return view;
    }
    delete view;
    return nullptr;
}

bool StepButtonView::init()
{
    m_spriteON = Sprite::create("step_button_on.png");
    m_spriteOFF = Sprite::create("step_button_off.png");
    
    m_spriteOFF->setAnchorPoint(Vec2(0, 0));
    m_spriteOFF->cocos2d::Node::setPosition(0, 0);
    addChild(m_spriteOFF);
    
    m_spriteON->setAnchorPoint(Vec2(0, 0));
    m_spriteON->cocos2d::Node::setPosition(0, 0);
    addChild(m_spriteON);
    
    updateState(StepButtonStates::OFF);
    return true;
}

void StepButtonView::updateState(StepButtonStates state)
{
    switch (state) {
        case StepButtonStates::ON:
            m_spriteON->setVisible(true);
            m_spriteOFF->setVisible(false);
            break;
        case StepButtonStates::OFF:
            m_spriteON->setVisible(false);
            m_spriteOFF->setVisible(true);
            break;
    }
}