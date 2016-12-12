#ifndef _INTERACT_COMMAND_H_
#define _INTERACT_COMMAND_H_

#include "Command.h"
#include "GameLayer.h"

class InteractCommand : public Command
{
public:
	virtual void execute(GameLayer* layer);
};
#endif // !_INTERACT_COMMAND_H_

