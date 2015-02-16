#include <string>
#include <vector>
#include <map>
#include <algorithm>

#include "minecraftpe/util/Util.h"
#include "minecraftpe/client/Minecraft.h"
#include "minecraftpe/command/ICommandManager.h"
#include "minecraftpe/command/HelpCommand.h"
#include "minecraftpe/command/NumberInvalidException.h"
#include "minecraftpe/command/CommandNotFoundException.h"
#include "minecraftpe/command/WrongUsageException.h"
#include "minecraftpe/entity/player/Player.h"

using std::string;
using std::vector;
using std::map;
using std::sort;
using std::min;

string HelpCommand::getCommandName() const {
	return "help";
}

int HelpCommand::getRequiredPermissionLevel() const {
	return 0;
}

string HelpCommand::getCommandUsage() const {
	return "/help <page>";
}

const vector<string> *HelpCommand::getCommandAliases() const {
	vector<string> *aliases = new vector<string>;
	aliases->push_back("?");

	return aliases;
}

void HelpCommand::processCommand(Minecraft *minecraft, Player *sender, const vector<string> &args) {
	const vector<ICommand *> *commands = getSortedPossibleCommands(minecraft, sender);
	char cmdNum = 7;
	int pages = (commands->size() - 1) / cmdNum;
	int page;

	try {
		page = args.size() == 0 ? 0 : parseIntBounded(sender, args[0], 1, pages + 1) - 1;
	} catch(NumberInvalidException &e) {
		map<string, ICommand *> commandMap = getCommands(minecraft);

		map<string, ICommand *>::iterator iter = commandMap.find(args[0]);
		if(iter != commandMap.end()) {
			throw WrongUsageException(iter->second->getCommandUsage(), {});
		}

		throw CommandNotFoundException();
	}

	int j = min((page + 1) * cmdNum, (int) commands->size());

	sender->displayClientMessage("--- 도움말 " + Util::toString(page + 1) + " / " + Util::toString(pages + 1) + " 페이지 (/help <page>) ---");

	for(int i = page * cmdNum; i < j; i++) {
		sender->displayClientMessage("● " + commands->at(i)->getCommandUsage());
	}

	if(page == 0) {
		sender->displayClientMessage("팁: 명령을 입력하는 동안 <tab> 키를 사용하여 명령 또는 인수를 자동 완성 할 수 있습니다");
	}
}

const vector<ICommand *> *HelpCommand::getSortedPossibleCommands(Minecraft *minecraft, Player *sender) {
	const vector<ICommand *> *map = minecraft->getCommandManager()->getPossibleCommands(sender);

	vector<ICommand *> *commands = new vector<ICommand *>;
	commands->assign(map->begin(), map->end());

	struct {
		bool operator()(ICommand *a, ICommand *b) {
			return (a->getCommandName().compare(b->getCommandName()) < 0);
		}
	} compare;
	sort(commands->begin(), commands->end(), compare);

	return commands;
}

map<string, ICommand *> HelpCommand::getCommands(Minecraft *minecraft) {
	return minecraft->getCommandManager()->getCommands();
}
