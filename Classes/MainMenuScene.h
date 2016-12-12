//
//  MainMenuScene.h
//  TimeTale
//
//  Created by Hema Dubal on 25/04/16.
//
//

#ifndef MainMenuScene_h__
#define MainMenuScene_h__

#include <stdio.h>
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

using namespace cocos2d;
using namespace cocos2d::ui;

class MainMenuScene : public cocos2d::Scene
{
private:
    void addSearchPath();
    void playButtonClicked(Ref* pSender);
	void infoButtonClicked(Ref* pSender);

public:
    MainMenuScene();
    ~MainMenuScene();
    CREATE_FUNC(MainMenuScene);
    virtual bool init() override;
};

#endif /* MainMenuScene_h__ */
