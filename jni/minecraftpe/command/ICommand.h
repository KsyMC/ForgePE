#pragma once

#include <string>
#include <vector>

class Minecraft;
class Player;

class ICommand {
public:
	virtual ~ICommand() {};
	virtual std::string getCommandName() const = 0;
	virtual std::string getCommandUsage() const = 0;
	virtual const std::vector<std::string> *getCommandAliases() const = 0;
	virtual void processCommand(Minecraft *, Player *, const std::vector<std::string> &) = 0;
	virtual bool canCommandSenderUseCommand(Player *) = 0;
};
