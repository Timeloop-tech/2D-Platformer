#ifndef _HUD_LAYER_H_
#define _HUD_LAYER_H_

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Command.h"
#include "Character.h"
#include "JumpCommand.h"
#include "LeftCommand.h"
#include "RightCommand.h"
#include "InteractCommand.h"
#include "JumpCommandInfo.h"
#include "LeftCommandInfo.h"
#include "RightCommandInfo.h"
#include "InteractCommandInfo.h"
#include "DelayInfo.h"
#include "GameLayer.h"
#include "RecordTime.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace cocos2d;
using namespace cocos2d::ui;

class HUDLayer : public Layer 
{
private:
	Layer*			m_baseLayer;
	GameLayer*		m_gameLayer;
	Node*			m_rootNode;
	Button*			m_jumpButton;
	Button*			m_leftButton;
	Button*			m_rightButton;
	Button*			m_interactButton;
	Button*			m_slowDownTimeButton;
	Button*			m_pauseTimeButton;
	Button*			m_travelBackButton;
	Command*		m_jumpCommand;
	Command*		m_leftCommand;
	Command*		m_rightCommand;
	Command*		m_interactCommmand;
	CommandInfo*	m_jumpCommandInfo;
	CommandInfo*	m_leftCommandInfo;
	CommandInfo*	m_rightCommandInfo;
	CommandInfo*	m_interactCommandInfo;
	CommandInfo*	m_delayInfo;
	RecordTime&		m_recordTime;
	bool			m_jumpButtonPressed;
	bool			m_leftButtonPressed;
	bool			m_rightButtonPressed;
	bool			m_interactButtonPressed;
	bool			m_slowDownTimeButtonPressed;
	bool			m_pauseTimeButtonPressed;
	bool			m_travelBackButtonPressed;

	void leftButtonListener(Ref* pSender, Widget::TouchEventType type);
	void rightButtonListener(Ref* pSender, Widget::TouchEventType type);
	void interactButtonListener(Ref* pSender, Widget::TouchEventType type, GameLayer* layer);
	void jumpButtonListener(Ref* pSender, Widget::TouchEventType type);
	void slowDownTimeButtonListener(Ref* pSender, Widget::TouchEventType type);
	void pauseTimeButtonListener(Ref* pSender, Widget::TouchEventType type);
	void travelBackButtonListener(Ref* pSender, Widget::TouchEventType type);
    
public:
	bool getJumpButtonStatus();
	bool getLeftButtonStatus();
	bool getRightButtonStatus();
	bool getInteractButtonStatus();
	bool getSlowDownTimeButtonStatus();
	bool getPauseTimeButtonStatus();
	bool getTravelBackButtonStatus();
	void update(float dt, GameLayer* layer);
	HUDLayer(GameLayer* layer, RecordTime& recordTime);
	virtual bool init();
	static HUDLayer* create(GameLayer* layer, RecordTime& recordTime);
};

#endif