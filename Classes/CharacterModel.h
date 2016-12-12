#ifndef _CHARACTER_MODEL_H_
#define _CHARACTER_MODEL_H_

#include "GameElementModel.h"
#include "Character.h"
#include "CharacterStates.h"
#include "cocos2d.h"
#include "InSpacePortalModel.h"
#include "OutSpacePortalModel.h"

USING_NS_CC;

class Character;

class CharacterModel : public GameElementModel
{
private:
	int							m_touchCount;;
    CharacterState				m_characterState;
	bool						m_isTouchingFloor;
	const b2Vec2				m_rightForce;
	const b2Vec2				m_leftForce;
	const b2Vec2				m_jumpImpulse;
	InSpacePortalModel*			m_inSpacePortalModel;
	OutSpacePortalModel*		m_outSpacePortalModel;

public:
	CharacterModel(b2World& world, b2Vec2 position);
	void incrementTouchCount();
	void decrementTouchCount();
	void setCanJumpStatus();
    bool getCanJumpStatus();
	bool canJump();
	void jump();
	void moveLeft();
	void moveRight();
	InSpacePortalModel* getInSpacePortalModel();
	OutSpacePortalModel* getOutSpacePortalModel();
	void setInSpacePortalModelNull();
	void setOutSpacePortalModelNull();
	void changePositionDueToSpacePortal(InSpacePortalModel* inSpacePortalModel);
    void updateState(CharacterState state);
    void setUserData(Character* character);
};

#endif