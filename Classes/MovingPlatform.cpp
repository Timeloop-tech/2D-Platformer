#include "MovingPlatform.h"

MovingPlatform::MovingPlatform(b2World& world, int ID, Vec2 startPoint, Vec2 endPoint, float velocity, Type type, Node* parent)
: GameElement(new MovingPlatformModel(world, Utils::pixelPositionToMeter(startPoint), Utils::pixelPositionToMeter(endPoint), (velocity/PTM_RATIO), type), MovingPlatformView::create())
	, m_movingPlatformID(ID)
{
    m_movingPlatformModel = static_cast<MovingPlatformModel*>(m_model);
    m_movingPlatformView = static_cast<MovingPlatformView*>(m_view);
    parent->addChild(m_movingPlatformView);
    m_movingPlatformModel->setUserData(this);
	Director* director = Director::getInstance();
	Scheduler* scheduler = director->getScheduler();
	scheduler->schedule(schedule_selector(MovingPlatform::updatePlatform), this, 0, false);
}

void MovingPlatform::updatePlatform(float dt)
{
	static_cast<MovingPlatformModel*>(m_model)->updatePlatform(dt);
}