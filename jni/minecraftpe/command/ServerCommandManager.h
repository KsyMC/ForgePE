#pragma once

#include "minecraftpe/command/CommandHandler.h"

class ServerCommandManager : public CommandHandler {
public:
	ServerCommandManager(Minecraft *);
};
