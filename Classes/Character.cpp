#include "Character.h"
#include "Utils.h"

Character::Character(b2World& world, b2Vec2 position, Node* parent)
: GameElement(new CharacterModel(world, b2Vec2(position.x / PTM_RATIO, position.y / PTM_RATIO)), CharacterView::create())
{
    m_characterModel = static_cast<CharacterModel*>(m_model);
    m_characterView = static_cast<CharacterView*>(m_view);
    m_characterModel->setUserData(this);
    parent->addChild(m_characterView);
    m_movement = false;
}

void Character::setCanJumpStatus()
{
    m_characterModel->setCanJumpStatus();
}

bool Character::getCanJumpStatus()
{
    return m_characterModel->getCanJumpStatus();
}

bool Character::isFlying()
{
    return false;
}

void Character::jumpAction()
{
    m_movement = true;
    m_state = CharacterState::Jump;
    m_characterModel->updateState(m_state);
    m_characterView->updateState(m_state, getPosition());
}

void Character::moveLeft()
{
    m_movement = true;
    m_state = CharacterState::MoveLeft;
    m_characterModel->updateState(m_state);
    m_characterView->updateState(m_state, getPosition());
}

void Character::moveRight()
{
    m_movement = true;
    m_state = CharacterState::MoveRight;
    m_characterModel->updateState(m_state);
    m_characterView->updateState(m_state, getPosition());
}

void Character::stand()
{
    m_state = CharacterState::Stand;
    m_characterModel->updateState(m_state);
    m_characterView->updateState(m_state, getPosition());
}

void Character::update()
{
    //Make Character view idle if no movement observed.
    if (!m_movement)
    {
        if (getCanJumpStatus())
        {
            stand();
        }
    }
    m_movement = false;
}

void Character::incrementTouchCount()
{
	m_characterModel->incrementTouchCount();
}

void Character::decrementTouchCount()
{
	m_characterModel->decrementTouchCount();
}