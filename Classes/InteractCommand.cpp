#include "InteractCommand.h"

void InteractCommand::execute(GameLayer* layer)
{
	layer->checkForInteraction();
}