//
//  LevelManager.h
//
//  Created by Hema Dubal on 22/10/15.
//
//

#ifndef LevelManager_h__
#define LevelManager_h__

#include "LevelDef.h"
#include "cocos2d.h"

class LevelManager
{
private:
    LevelDef*   m_levelDef;
    
public:
    LevelManager();
    void load(const int levelNumber);
    
    LevelDef* getLevelDef();
};

#endif //LevelManager_h__
