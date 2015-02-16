#include "minecraftpe/util/Util.h"
#include "minecraftpe/command/ICommand.h"
#include "minecraftpe/command/CommandHandler.h"
#include "minecraftpe/command/CommandNotFoundException.h"
#include "minecraftpe/command/WrongUsageException.h"
#include "minecraftpe/entity/player/Player.h"
#include "shared.h"

using std::string;
using std::vector;
using std::map;
using std::exception;

ICommand *CommandHandler::registerCommand(ICommand *command) {
	_commandMap.insert(map<string, ICommand *>::value_type(command->getCommandName().c_str(), command));
	_commandSet.insert(map<string, ICommand *>::value_type(command->getCommandName().c_str(), command));

	const vector<string> *aliases = command->getCommandAliases();
	for(int i = 0; i < aliases->size(); i++) {
		string alias = aliases->at(i);
		map<string, ICommand *>::iterator iter = _commandMap.find(alias);

		if(iter == _commandMap.end()) {
			_commandMap.insert(map<string, ICommand *>::value_type(alias, command));
		}
	}
	delete aliases;

	return command;
}

void CommandHandler::executeCommand(Player *sender, const string &msg) {
	string message(msg);
	message = trim(message);

	if(Util::startsWith(message, "/")) {
		message = message.substr(1);
	}

	vector<string> args = Util::split(message, ' ');
	string commandName = args[0];
	args.erase(args.begin());

	auto iter = _commandMap.find(commandName);

	try {
		if(iter == _commandMap.end()) {
			throw CommandNotFoundException();
		}

		if(iter->second->canCommandSenderUseCommand(sender)) {
			iter->second->processCommand(_minecraft, sender, args);
		} else {
			sender->displayClientMessage("§c이 명령어를 사용할 권한이 없습니다");
		}
	} catch (WrongUsageException &e) {
		sender->displayClientMessage("§c사용법: " + e.getMessage());
	} catch (CommandException &e) {
		sender->displayClientMessage("§c" + e.getMessage());
	} catch (exception &e) {
		sender->displayClientMessage("§c명령을 수행하는 도중 알 수 없는 오류가 발생했습니다");
	}
}

const vector<ICommand *> *getPossibleCommands(Player *, const string &) {
	vector<ICommand *> *commands = new vector<ICommand *>;
	return commands;
}

const vector<ICommand *> *CommandHandler::getPossibleCommands(Player *player) {
	vector<ICommand *> *commands = new vector<ICommand *>;

	for(auto iter = _commandSet.begin(); iter != _commandSet.end(); iter++) {
		ICommand *command = iter->second;
		if(command->canCommandSenderUseCommand(player)) {
			commands->push_back(command);
		}
	}

	return commands;
}

const map<string, ICommand *> &CommandHandler::getCommands() const {
	return _commandMap;
}
