//
//  MainMenuScene.h
//  TimeTale
//
//  Created by Hema Dubal on 25/04/16.
//
//

#ifndef InfoScene_h__
#define InfoScene_h__

#include <stdio.h>
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

using namespace cocos2d;
using namespace cocos2d::ui;

class InfoScene : public cocos2d::Scene
{
private:
    void addSearchPath();
    void backButtonClicked(Ref* pSender);
    
public:
    InfoScene();
    ~InfoScene();
    CREATE_FUNC(InfoScene);
    virtual bool init() override;
};

#endif /* InfoScene_h__ */
