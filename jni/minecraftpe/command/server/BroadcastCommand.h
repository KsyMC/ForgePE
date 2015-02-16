#pragma once

#include "minecraftpe/command/BaseCommand.h"

class BroadcastCommand : public BaseCommand {
public:
	virtual std::string getCommandName() const;
	virtual std::string getCommandUsage() const;
	virtual int getRequiredPermissionLevel() const;
	virtual void processCommand(Minecraft *, Player *, const std::vector<std::string> &);
};
