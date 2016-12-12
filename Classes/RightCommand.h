#ifndef _RIGHT_COMMAND_H_
#define _RIGHT_CONNAND_H_

#include "Command.h"

class RightCommand :public Command
{
public:
	virtual void execute(GameLayer* layer);
};
#endif // !_RIGHT_COMMAND_H_

