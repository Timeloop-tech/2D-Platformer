#include "HUDLayer.h"

USING_NS_CC;
using namespace cocos2d::ui;
HUDLayer* HUDLayer::create(GameLayer* layer, RecordTime& recordTime)
{
	HUDLayer* newObject = new HUDLayer(layer, recordTime);

	if (newObject && newObject->init())
	{
		newObject->autorelease();   //I will explain you about autorelease later on. Add this in the list of
									// questions to discuss
	}
	else
	{
		delete newObject;
		newObject = nullptr;
	}
	return newObject;
}

HUDLayer::HUDLayer(GameLayer* layer, RecordTime& recordTime)
	: m_interactButton(nullptr)
	, m_rootNode(nullptr)
	, m_jumpButton(nullptr)
	, m_leftButton(nullptr)
	, m_rightButton(nullptr)
	, m_slowDownTimeButton(nullptr)
	, m_pauseTimeButton(nullptr)
	, m_travelBackButton(nullptr)
	, m_jumpCommand(nullptr)
	, m_leftCommand(nullptr)
	, m_rightCommand(nullptr)
	, m_jumpCommandInfo(nullptr)
	, m_leftCommandInfo(nullptr)
	, m_rightCommandInfo(nullptr)
	, m_delayInfo(nullptr)
	, m_jumpButtonPressed(false)
	, m_leftButtonPressed(false)
	, m_rightButtonPressed(false)
	, m_recordTime(recordTime)
	, m_gameLayer(layer)
{	
}

bool HUDLayer::init()
{
	if (Layer::init() == false)
		return false;
	this->scheduleUpdate();

    m_rootNode = static_cast<Node*>(CSLoader::createNode("HUDLayer.csb"));
    addChild(m_rootNode);
    
    Node* bottomLeft = static_cast<Node*>(m_rootNode->getChildByName("bottomLeft"));
    Node* bottomRight = static_cast<Node*>(m_rootNode->getChildByName("bottomRight"));
    
    m_leftButton = static_cast<Button*>(bottomLeft->getChildByName("moveLeftButton"));
    m_rightButton = static_cast<Button*>(bottomLeft->getChildByName("moveRightButton"));
    m_jumpButton = static_cast<Button*>(bottomRight->getChildByName("jumpButton"));
    m_interactButton = static_cast<Button*>(bottomRight->getChildByName("interactButton"));
//	m_pauseTimeButton = static_cast<Button*>(m_rootNode->getChildByName("PauseTimeButton"));
//	m_travelBackButton = static_cast<Button*>(m_rootNode->getChildByName("TravelBackButton"));
//	m_slowDownTimeButton = static_cast<Button*>(m_rootNode->getChildByName("SlowDownTimeButton"));

	m_leftButton->addTouchEventListener(CC_CALLBACK_2(HUDLayer::leftButtonListener, this));
	m_rightButton->addTouchEventListener(CC_CALLBACK_2(HUDLayer::rightButtonListener, this));
	m_interactButton->addTouchEventListener(CC_CALLBACK_2(HUDLayer::interactButtonListener, this, m_gameLayer));
	m_jumpButton->addTouchEventListener(CC_CALLBACK_2(HUDLayer::jumpButtonListener, this));
//	m_pauseTimeButton->addTouchEventListener(CC_CALLBACK_2(HUDLayer::pauseTimeButtonListener, this));
//	m_slowDownTimeButton->addTouchEventListener(CC_CALLBACK_2(HUDLayer::slowDownTimeButtonListener, this));
//	m_travelBackButton->addTouchEventListener(CC_CALLBACK_2(HUDLayer::travelBackButtonListener, this));

	m_jumpCommand = new JumpCommand();
	m_leftCommand = new LeftCommand();
	m_rightCommand = new RightCommand();
	m_interactCommmand = new InteractCommand();
	m_jumpCommandInfo = new JumpCommandInfo();
	m_leftCommandInfo = new LeftCommandInfo();
	m_rightCommandInfo = new RightCommandInfo();
	m_interactCommandInfo = new InteractCommandInfo();
	m_delayInfo = new DelayInfo();

	return true;
}

void HUDLayer::leftButtonListener(Ref* pSender, Widget::TouchEventType type)
{
	if (type == Widget::TouchEventType::BEGAN)
		m_leftButtonPressed = true;
	if (type == Widget::TouchEventType::ENDED)
		m_leftButtonPressed = false;
}

void HUDLayer::rightButtonListener(Ref* pSender, Widget::TouchEventType type)
{
	if (type == Widget::TouchEventType::BEGAN)
		m_rightButtonPressed = true;
	if (type == Widget::TouchEventType::ENDED)
		m_rightButtonPressed = false;
}

void HUDLayer::interactButtonListener(Ref* pSender, Widget::TouchEventType type, GameLayer* layer)
{
	if (type == Widget::TouchEventType::BEGAN)
	{
		m_interactButtonPressed = true;
		m_interactCommmand->execute(layer);
	}
	if (type == Widget::TouchEventType::ENDED)
	{
		m_interactButtonPressed = false;
	}
}

void HUDLayer::jumpButtonListener(Ref* pSender, Widget::TouchEventType type)
{
	if (type == Widget::TouchEventType::BEGAN)
	{
		m_jumpButtonPressed = true;
	}
	if (type == Widget::TouchEventType::ENDED)
		m_jumpButtonPressed = false;
}

void HUDLayer::travelBackButtonListener(Ref* pSender, Widget::TouchEventType type)
{
	if (type == Widget::TouchEventType::BEGAN)
		m_travelBackButtonPressed = true;
	if (type == Widget::TouchEventType::ENDED)
		m_travelBackButtonPressed = false;
}

bool HUDLayer::getJumpButtonStatus()
{
	return m_jumpButtonPressed;
}

bool HUDLayer::getLeftButtonStatus()
{
	return m_leftButtonPressed;
}

bool HUDLayer::getRightButtonStatus()
{
	return m_rightButtonPressed;
}

bool HUDLayer::getInteractButtonStatus()
{
	return m_interactButtonPressed;
}

bool HUDLayer::getSlowDownTimeButtonStatus()
{
	return m_slowDownTimeButtonPressed;
}

bool HUDLayer::getPauseTimeButtonStatus()
{
	return m_pauseTimeButtonPressed;
}

bool HUDLayer::getTravelBackButtonStatus()
{
	return m_travelBackButtonPressed;
}

void HUDLayer::slowDownTimeButtonListener(Ref* pSender, Widget::TouchEventType type)
{
	if (type == Widget::TouchEventType::BEGAN)
		m_slowDownTimeButtonPressed = true;
	if (type == Widget::TouchEventType::ENDED)
		m_slowDownTimeButtonPressed = false;
}

void HUDLayer::pauseTimeButtonListener(Ref* pSender, Widget::TouchEventType type)
{
	if (type == Widget::TouchEventType::BEGAN)
		m_pauseTimeButtonPressed = true;
	if (type == Widget::TouchEventType::ENDED)
		m_pauseTimeButtonPressed = false;
}

void HUDLayer::update(float dt, GameLayer* layer)
{
	if (m_leftButtonPressed)
	{
		m_leftCommand->execute(layer);
		m_recordTime.addElement(m_leftCommandInfo);
	}
	else if (m_rightButtonPressed)
	{
		m_rightCommand->execute(layer);
		m_recordTime.addElement(m_rightCommandInfo);
	}
	else if (m_jumpButtonPressed)
	{
		m_jumpCommand->execute(layer);
		m_jumpButtonPressed = false;
		m_recordTime.addElement(m_jumpCommandInfo);
	}

	else
	{
		m_recordTime.addElement(m_delayInfo);
	}
/*
    if (!m_leftButtonPressed)
    {
        if (!m_rightButtonPressed)
        {
            if (!m_jumpButtonPressed && layer->getCharacter()->getCanJumpStatus())
            {
                layer->getCharacter()->stand();
            }
        }
    }
*/
}


