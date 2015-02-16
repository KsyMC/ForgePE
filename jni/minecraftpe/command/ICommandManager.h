#pragma once

#include <vector>
#include <string>
#include <map>

class ICommand;
class Player;

class ICommandManager {
public:
	virtual ~ICommandManager() {}
	virtual void executeCommand(Player *, const std::string &) = 0;
	virtual const std::vector<ICommand *> *getPossibleCommands(Player *, const std::string &) = 0;
	virtual const std::vector<ICommand *> *getPossibleCommands(Player *) = 0;
	virtual const std::map<std::string, ICommand *> &getCommands() const = 0;
};
