#pragma once

#include "minecraftpe/command/ICommandManager.h"

class Minecraft;

class CommandHandler : public ICommandManager {
protected:
	Minecraft *_minecraft;
	std::map<std::string, ICommand *> _commandMap;
	std::map<std::string, ICommand *> _commandSet;

public:
	CommandHandler(Minecraft *minecraft) : _minecraft(minecraft) {}
	virtual ICommand *registerCommand(ICommand *);
	virtual void executeCommand(Player *player, const std::string &arg);
	virtual const std::vector<ICommand *> *getPossibleCommands(Player *, const std::string &);
	virtual const std::vector<ICommand *> *getPossibleCommands(Player *p_71557_1_);
	virtual const std::map<std::string, ICommand *> &getCommands() const;

	inline static std::string trim(std::string &s) {
		std::string r = s.erase(s.find_last_not_of(" \t\n\r") + 1);

		return r.erase(0, s.find_first_not_of(" \t\n\r"));
	}
};
