#include "JumpCommand.h"

void JumpCommand::execute(GameLayer* layer)
{
	layer->getCharacter()->jumpAction();
}