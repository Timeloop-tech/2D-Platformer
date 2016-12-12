#include "SlidingDoor.h"

SlidingDoor::SlidingDoor(b2World& world, Vec2 position, int ID, int reactID, Node* parent)
: GameElement(new SlidingDoorModel(world, Utils::pixelPositionToMeter(position), ID), SlidingDoorView::create())
	, m_reactID(reactID)
{
    m_slidingDoorModel = static_cast<SlidingDoorModel*>(m_model);
    m_slidingDoorView = static_cast<SlidingDoorView*>(m_view);
    parent->addChild(m_slidingDoorView);
    m_slidingDoorModel->setUserData(this);
    
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

	auto stepButtonActivationListener = EventListenerCustom::create(STEP_BUTTON_PRESSED_EVENT, 
		[this](EventCustom* event)
	{
		int* i = static_cast<int*>(event->getUserData());
		onStepButtonActivation(*i);
	});
	Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(stepButtonActivationListener, 1);

	auto stepButtonDeactivationListener = EventListenerCustom::create(STEP_BUTTON_RELEASED_EVENT,
		[this](EventCustom* event)
	{
		int* i = static_cast<int*>(event->getUserData());
		onStepButtonDeactivation(*i);
	});
	Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(stepButtonDeactivationListener, 1);
}

void SlidingDoor::beginOpeningDoor()
{
	SlidingDoorModel* model = static_cast<SlidingDoorModel*>(m_model);
	model->beginOpeningDoor();
	float time = ((model->getHighestPosition().y * PTM_RATIO) - (model->getCurrentPosition().y * PTM_RATIO))/((model->getLinearVelocity().y)*PTM_RATIO);
	Director* directorObj = Director::getInstance();
	Scheduler* schedulerObj = directorObj->getScheduler();
	schedulerObj->schedule(schedule_selector(SlidingDoor::endOpeningDoor), this, time, false);
}

void SlidingDoor::endOpeningDoor(float dt)
{
	Director* directorObj = Director::getInstance();
	Scheduler* schedulerObj = directorObj->getScheduler();
	static_cast<SlidingDoorModel*>(m_model)->endOpeningDoor();
	schedulerObj->unschedule(schedule_selector(SlidingDoor::endOpeningDoor), this);
}

void SlidingDoor::onPushButtonActivation(int ID)
{
	if (ID == m_reactID)
	{
		beginOpeningDoor();
	}
}

void SlidingDoor::onPushButtonDeactivation(int ID)
{
	if (ID == m_reactID)
	{
		beginClosingDoor();
	}
}

void SlidingDoor::onStepButtonActivation(int ID)
{
	if (ID == m_reactID)
	{
		beginOpeningDoor();
	}
}

void SlidingDoor::onStepButtonDeactivation(int ID)
{
	if (ID == m_reactID)
	{
		beginClosingDoor();
	}
}

void SlidingDoor::beginClosingDoor()
{
	SlidingDoorModel* model = static_cast<SlidingDoorModel*>(m_model);
	model->beginClosingDoor();
	float time = ((model->getCurrentPosition().y * PTM_RATIO) - (model->getStartingPosition().y * PTM_RATIO)) / ((model->getLinearVelocity().y)*PTM_RATIO);
	Director* directorObj = Director::getInstance();
	Scheduler* schedulerObj = directorObj->getScheduler();
	schedulerObj->schedule(schedule_selector(SlidingDoor::endClosingDoor), this, time, false);
}

void SlidingDoor::endClosingDoor(float dt)
{
	Director* directorObj = Director::getInstance();
	Scheduler* schedulerObj = directorObj->getScheduler();
	static_cast<SlidingDoorModel*>(m_model)->endClosingDoor();
	schedulerObj->unschedule(schedule_selector(SlidingDoor::endClosingDoor), this);
}

void SlidingDoor::setLinearVelocity(b2Vec2 velocity)
{
    m_slidingDoorModel->setLinearVelocity(velocity);
}