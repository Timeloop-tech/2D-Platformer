//
//  MainMenuScene.h
//  TimeTale
//
//  Created by Hema Dubal on 25/04/16.
//
//

#ifndef SelectLevelScene_h__
#define SelectLevelScene_h__

#include <stdio.h>
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

using namespace cocos2d;
using namespace cocos2d::ui;

class SelectLevelScene : public cocos2d::Scene
{
private:
    void addSearchPath();
    void backButtonClicked(Ref* pSender);
	void level1Clicked(Ref* pSender);
	void level2Clicked(Ref* pSender);
	void level3Clicked(Ref* pSender);

public:
    SelectLevelScene();
    ~SelectLevelScene();
    CREATE_FUNC(SelectLevelScene);
    virtual bool init() override;
};

#endif /* SelectLevelScene_h__ */
