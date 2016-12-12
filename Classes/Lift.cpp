#include "Lift.h"

Lift::Lift(b2World& world, int ID, int reactID, Vec2 startPosition, Vec2 endPosition, float velocity, Type type, Node* parent)
: GameElement(new LiftModel(world, ID, reactID, Utils::pixelPositionToMeter(startPosition), Utils::pixelPositionToMeter(endPosition), velocity/PTM_RATIO, type), LiftView::create())
	, m_reactID(reactID)
	, m_movingUP(false)
	, m_endPoint(endPosition)
	, m_startPoint(startPosition)
	, m_veloctiyValue(velocity)
	, m_liftType(type)
{
    m_liftModel = static_cast<LiftModel*>(m_model);
    m_liftView = static_cast<LiftView*>(m_view);
    parent->addChild(m_liftView);
    m_liftModel->setUserData(this);
    
	auto pushButtonActivationListener = EventListenerCustom::create(PUSH_BUTTON_PRESSED_EVENT,
		[this](EventCustom* event)
	{
		int* i = static_cast<int*>(event->getUserData());
		onPushButtonActivation(*i);
	});
	Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(pushButtonActivationListener, 1);

	auto pushButtonDeactivationListener = EventListenerCustom::create(PUSH_BUTTON_RELEASED_EVENT,
		[this](EventCustom* event)
	{
		int* i = static_cast<int*>(event->getUserData());
		onPushButtonDeactivation(*i);
	});
	Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(pushButtonDeactivationListener, 1);
}

void Lift::onPushButtonActivation(int i)
{
	m_movingUP = true;
	if (i == m_reactID)
	{
		moveLiftUpwards();
	}
}

void Lift::onPushButtonDeactivation(int i)
{
	m_movingUP = false;
	if (i == m_reactID)
	{
		moveLiftDownwards();
	}
}

void Lift::moveLiftUpwards()
{
	m_liftModel->moveLiftUpwards();
	float time;
	if (m_liftType == Type::horizontal)
	{
		time = (m_endPoint.x - m_startPoint.x)/m_veloctiyValue;
	}
	else
	{
		time = (m_endPoint.y - m_startPoint.y) / m_veloctiyValue;
	}
	Director* directorObj = Director::getInstance();
	Scheduler* schedulerObj = directorObj->getScheduler();
	schedulerObj->schedule(schedule_selector(Lift::setVelocityToZero), this, time, false);
}

void Lift::moveLiftDownwards()
{
	m_liftModel->moveLiftDownwards();
	float time;
	if (m_liftType == Type::horizontal)
	{
		time = (m_endPoint.x - m_startPoint.x) / m_veloctiyValue;
	}
	else
	{
		time = (m_endPoint.y - m_startPoint.y) / m_veloctiyValue;
	}

	Director* directorObj = Director::getInstance();
	Scheduler* schedulerObj = directorObj->getScheduler();
	schedulerObj->schedule(schedule_selector(Lift::setVelocityToZero), this, time, false);
}

void Lift::setVelocityToZero(float dt)
{
	m_liftModel->setVelocityToZero();
	Director* directorObj = Director::getInstance();
	Scheduler* schedulerObj = directorObj->getScheduler();
	schedulerObj->unschedule(schedule_selector(Lift::setVelocityToZero), this);
}