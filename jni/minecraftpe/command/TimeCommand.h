#pragma once

#include "minecraftpe/command/BaseCommand.h"

class TimeCommand : public BaseCommand {
public:
	virtual std::string getCommandName() const;
	virtual std::string getCommandUsage() const;
	virtual int getRequiredPermissionLevel() const;
	virtual void processCommand(Minecraft *, Player *, const std::vector<std::string> &);
	void setTime(Player *, int);
	void addTime(Player *, int);
};
