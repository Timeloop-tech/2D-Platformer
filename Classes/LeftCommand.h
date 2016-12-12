#ifndef _LEFT_COMMAND_H_
#define _LEFT_COMMAND_H_

#include "Command.h"
#include "GameLayer.h"

class LeftCommand : public Command
{
public :
	virtual void execute(GameLayer* layer);
};

#endif // !_LEFT_COMMAND_H_
