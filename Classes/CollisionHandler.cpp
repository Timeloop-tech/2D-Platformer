#include "CollisionHandler.h"

void CollisionHandler::BeginContact(b2Contact *c)
{
	b2Fixture* bcFixtureA = c->GetFixtureA();
	b2Fixture* bcFixtureB = c->GetFixtureB();

	b2Body* bcBodyA = bcFixtureA->GetBody();
	b2Body* bcBodyB = bcFixtureB->GetBody();
    
    GameElement* bcBodyAElement = static_cast<GameElement*>(bcBodyA->GetUserData());
	GameElementType bcBodyAType = bcBodyAElement->getGameElementType();

	GameElement* bcBodyBElement = static_cast<GameElement*>(bcBodyB->GetUserData());
	GameElementType bcBodyBType = bcBodyBElement->getGameElementType();

    Character* characterObj = nullptr;
    GameElement* bcOtherGameElement = nullptr;
    if (bcBodyAType == GameElementType::Character)
    {
        characterObj = static_cast<Character*>(bcBodyAElement);
        bcOtherGameElement = bcBodyBElement;
    }
    else if(bcBodyBType == GameElementType::Character)
    {
        characterObj = static_cast<Character*>(bcBodyBElement);
        bcOtherGameElement = bcBodyAElement;
    }
    
    if (characterObj)
    {
        GameElementType otherGameElementType = bcOtherGameElement->getGameElementType();
        if (otherGameElementType == GameElementType::Floor
            || otherGameElementType == GameElementType::PushableBlock
            || otherGameElementType == GameElementType::Lift
            || otherGameElementType == GameElementType::MovingPlatform)
        {
            characterObj->incrementTouchCount();
        }
    }
	
	StepButton* stepButton = nullptr;
    if (bcBodyAType == GameElementType::StepButton && bcBodyBType != GameElementType::Floor)
    {
        stepButton = static_cast<StepButton*>(bcBodyA->GetUserData());
    }
    
    if (bcBodyBType == GameElementType::StepButton && bcBodyAType != GameElementType::Floor)
    {
        stepButton = static_cast<StepButton*>(bcBodyB->GetUserData());
    }
    
    if (stepButton != nullptr)
    {
        stepButton->steppedOn();
        stepButton->dispatchEvent();
    }
    
	PushButton* bcPushButtonCheck = nullptr;
	if (bcBodyAType == GameElementType::PushButton || bcBodyBType == GameElementType::PushButton)
	{
		if (bcFixtureA->IsSensor())
		{
			bcPushButtonCheck = static_cast<PushButton*>(bcBodyA->GetUserData());
			bcPushButtonCheck->setInteractionStatus(true);
            if (bcPushButtonCheck->getPushButtonState() == PushButtonStates::ON)
			{
                bcPushButtonCheck->setPushButtonState(PushButtonStates::OFF);
			}
			else
			{
                bcPushButtonCheck->setPushButtonState(PushButtonStates::ON);
			}
			bcPushButtonCheck->dispatchEvent();
		}
		else
		{
			bcPushButtonCheck = static_cast<PushButton*>(bcBodyB->GetUserData());
			bcPushButtonCheck->setInteractionStatus(true);	
            if (bcPushButtonCheck->getPushButtonState() == PushButtonStates::ON)
            {
                bcPushButtonCheck->setPushButtonState(PushButtonStates::OFF);
            }
            else
            {
                bcPushButtonCheck->setPushButtonState(PushButtonStates::ON);
            }
			bcPushButtonCheck->dispatchEvent();
		}
	}
	
	SlidingDoor* bcSlidingDoorCheck = nullptr;
	if (bcBodyAType == GameElementType::SlidingDoor || bcBodyBType == GameElementType::SlidingDoor)
	{
		if (bcFixtureA->IsSensor() == true)
		{
			bcSlidingDoorCheck = static_cast<SlidingDoor*>(bcBodyA->GetUserData());
		}
		else
		{
			bcSlidingDoorCheck = static_cast<SlidingDoor*>(bcBodyB->GetUserData());
		}
		bcSlidingDoorCheck->setLinearVelocity(b2Vec2(0.0f, 0.0f));
	}

	InSpacePortalModel* bcInSpacePortalModel = nullptr;
	OutSpacePortalModel* bcOutSpacePortalModel = nullptr;
	CharacterModel* bcCharacterModel = nullptr;
	if (bcBodyAType == GameElementType::InSpacePortal && bcBodyBType == GameElementType::Character)
	{
		bcInSpacePortalModel = static_cast<InSpacePortalModel*>(bcBodyA->GetUserData());
		bcCharacterModel = static_cast<CharacterModel*>(bcBodyB->GetUserData());
	}
	if (bcBodyBType == GameElementType::InSpacePortal && bcBodyAType == GameElementType::Character)
	{
		bcInSpacePortalModel = static_cast<InSpacePortalModel*>(bcBodyB->GetUserData());
		bcCharacterModel = static_cast<CharacterModel*>(bcBodyA->GetUserData());
	}
	if (bcInSpacePortalModel != nullptr && bcCharacterModel != nullptr)
	{
		bcCharacterModel->changePositionDueToSpacePortal(bcInSpacePortalModel);
	}
}

void CollisionHandler::EndContact(b2Contact* c)
{
	b2Fixture* ecFixtureA = c->GetFixtureA();
	b2Fixture* ecFixtureB = c->GetFixtureB();

	b2Body* ecBodyA = ecFixtureA->GetBody();
	b2Body* ecBodyB = ecFixtureB->GetBody();

	GameElement* ecBodyAModel = static_cast<GameElement*>(ecBodyA->GetUserData());
	GameElementType ecBodyAType = ecBodyAModel->getGameElementType();

	GameElement* ecBodyBModel = static_cast<GameElement*>(ecBodyB->GetUserData());
	GameElementType ecBodyBType = ecBodyBModel->getGameElementType();

	Character* characterObj = nullptr;
    GameElement* ecOtherGameElement = nullptr;
	if (ecBodyAType == GameElementType::Character)
	{
		characterObj = static_cast<Character*>(ecBodyAModel);
        ecOtherGameElement = ecBodyBModel;
	}
	else
	{
        characterObj = static_cast<Character*>(ecBodyBModel);
        ecOtherGameElement = ecBodyAModel;
	}
    
    if (characterObj)
    {
        GameElementType otherGameElementType = ecOtherGameElement->getGameElementType();
        if (otherGameElementType == GameElementType::Floor
            || otherGameElementType == GameElementType::PushableBlock
            || otherGameElementType == GameElementType::Lift
            || otherGameElementType == GameElementType::MovingPlatform)
        {
            characterObj->decrementTouchCount();
        }
    }

    StepButton* stepButton = nullptr;
    if (ecBodyAType == GameElementType::StepButton && ecBodyBType != GameElementType::Floor)
    {
        stepButton = static_cast<StepButton*>(ecBodyA->GetUserData());
    }
    
    if (ecBodyBType == GameElementType::StepButton && ecBodyAType != GameElementType::Floor)
    {
        stepButton = static_cast<StepButton*>(ecBodyB->GetUserData());
    }
    
    if (stepButton != nullptr)
    {
        stepButton->steppedOut();
		stepButton->dispatchEvent();
    }

	PushButtonModel* ecPushButtonCheck = nullptr;
	if (ecBodyAType == GameElementType::PushButton || ecBodyBType == GameElementType::PushButton)
	{
		if (ecFixtureA->IsSensor())
		{
			ecPushButtonCheck = static_cast<PushButtonModel*>(ecBodyA->GetUserData());
			ecPushButtonCheck->setInteractionStatus(false);
		}
		else
		{
			ecPushButtonCheck = static_cast<PushButtonModel*>(ecBodyB->GetUserData());
			ecPushButtonCheck->setInteractionStatus(false);
		}
	}

}