//
//  MainMenuScene.h
//  TimeTale
//
//  Created by Hema Dubal on 25/04/16.
//
//

#ifndef GameOverScene_h__
#define GameOverScene_h__

#include <stdio.h>
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

using namespace cocos2d;
using namespace cocos2d::ui;

class GameOverScene : public cocos2d::Scene
{
private:
    void addSearchPath();
    void mainMenuButtonClicked(Ref* pSender);
    
public:
    GameOverScene();
    ~GameOverScene();
	CREATE_FUNC(GameOverScene);
    virtual bool init() override;
};

#endif /* GameOverScene_h__ */
