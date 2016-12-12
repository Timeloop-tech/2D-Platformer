#ifndef _GAME_ELEMENT_H_
#define _GAME_ELEMENT_H_

#include "GameElementModel.h"
#include "GameElementView.h"

USING_NS_CC;

class GameElement : public Ref 
{
protected:
	GameElementModel*		m_model;
    GameElementView*		m_view;
    
public:
	GameElement(GameElementModel* model, GameElementView* view);
    GameElementType getGameElementType();
	GameElementModel* getModel();
    void updatePositionBasedOnPhysics();
    b2Vec2 getPosition();    
};

#endif