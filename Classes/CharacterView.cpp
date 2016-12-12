#include "CharacterView.h"

CharacterView::CharacterView()
{
    
}

CharacterView::~CharacterView()
{
    
}

/* static */ CharacterView* CharacterView::create()
{
    CharacterView* view = new CharacterView();
    if (view && view->init())
    {
        return view;
    }
    delete view;
    return nullptr;
}

bool CharacterView::init()
{
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("princess_animation.plist");
    m_sprite = nullptr;
    m_characterState = CharacterState::Stand;
    playAnimation();
    return true;
}

void CharacterView::updateState(CharacterState state, b2Vec2 position)
{
    if (m_characterState != state) {
        m_sprite->removeFromParentAndCleanup(true);
        m_characterState = state;
        playAnimation();
    }
}

void CharacterView::playAnimation()
{
    const char *format;
    int frameCount;
    switch (m_characterState)
    {
        case CharacterState::Stand:
            format = "princess_idle_%03d.png";
            frameCount = 1;
            break;
        case CharacterState::MoveLeft:
            format = "princess_run_%03d.png";
            frameCount = 8;
            break;
        case CharacterState::MoveRight:
            format = "princess_run_%03d.png";
            frameCount = 8;
            break;
        case CharacterState::Jump:
            format = "princess_jump_%03d.png";
            frameCount = 4;
            break;
    }
    auto frames = getAnimation(format, frameCount);

    m_sprite = Sprite::createWithSpriteFrame(frames.front());
    if (m_characterState == CharacterState::MoveLeft || (m_characterState == CharacterState::Stand && m_previousCharacterState == CharacterState::MoveLeft))
    {
        m_sprite->setScaleX(-(m_sprite->getScaleX()));
    }
    addChild(m_sprite);
    auto animation = Animation::createWithSpriteFrames(frames, 1.0f/8);
    m_sprite->runAction(RepeatForever::create(Animate::create(animation)));
    m_previousCharacterState = m_characterState;
}

Vector<SpriteFrame*> CharacterView::getAnimation(const char *format, int count)
{
    auto spritecache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> animFrames;
    char str[100];
    for(int i = 1; i <= count; i++)
    {
        sprintf(str, format, i);
        CCLOG("Sprite File: %s",str);
        animFrames.pushBack(spritecache->getSpriteFrameByName(str));
    }
    return animFrames;
}