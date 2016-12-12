#ifndef _JUMP_COMMAND_H_
#define _JUMP_COMMAND_H_

#include "Command.h"
#include "GameLayer.h"

class JumpCommand : public Command
{
public:
	virtual void execute(GameLayer* layer);
};

#endif // !_JUMP_COMMAND_H_
