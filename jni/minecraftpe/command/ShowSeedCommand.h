#pragma once

#include "minecraftpe/command/BaseCommand.h"

class ShowSeedCommand : public BaseCommand {
public:
	virtual std::string getCommandName() const;
	virtual std::string getCommandUsage() const;
	virtual int getRequiredPermissionLevel() const;
	virtual void processCommand(Minecraft *, Player *, const std::vector<std::string> &);
	virtual bool canCommandSenderUseCommand(Player *);
};
