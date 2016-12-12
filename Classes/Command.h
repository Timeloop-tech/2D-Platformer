#ifndef _COMMAND_H_
#define _COMMAND_H_

#include "GameLayer.h"

class Command
{
public :
	virtual void execute(GameLayer* layer) = 0;
};

#endif // ! _COMMAND_H_

