#include "GameElementView.h"
#include "CharacterStates.h"
#include "Box2D/Box2D.h"

class CharacterView : public GameElementView
{
private:
    CharacterState      m_characterState;
    CharacterState      m_previousCharacterState;
    Sprite*             m_sprite;
    
    void playAnimation();
    Vector<SpriteFrame*> getAnimation(const char *format, int count);
    CharacterView();
    ~CharacterView();
    bool init();
    
public:
    static CharacterView* create();

    void updateState(CharacterState state, b2Vec2 position);
};