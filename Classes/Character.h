#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include "cocos2d.h"
#include "GameElement.h"
#include "CharacterModel.h"
#include "CharacterView.h"
#include "CharacterStates.h"

class CharacterModel;

class Character : public GameElement
{
    CharacterModel*     m_characterModel;
    CharacterView*      m_characterView;
    bool                m_movement;

public:
    CharacterState m_state;
    
	Character(b2World& world, b2Vec2 position, Node* parent);
   	void setCanJumpStatus();
    bool getCanJumpStatus();
    bool isFlying();
	void jumpAction();
	void moveLeft();
	void moveRight();
    void stand();
    void update();
	void incrementTouchCount();
	void decrementTouchCount();
};
#endif