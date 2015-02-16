#pragma once

#include <map>

#include "minecraftpe/command/BaseCommand.h"

class HelpCommand : public BaseCommand {
public:
	virtual std::string getCommandName() const;
	virtual std::string getCommandUsage() const;
	virtual const std::vector<std::string> *getCommandAliases() const;
	virtual int getRequiredPermissionLevel() const;
	virtual void processCommand(Minecraft *, Player *, const std::vector<std::string> &);
	const std::vector<ICommand *> *getSortedPossibleCommands(Minecraft *, Player *);
	std::map<std::string, ICommand *> getCommands(Minecraft *);
};
