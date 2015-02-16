#include "minecraftpe/command/PlayerNotFoundException.h"
#include "minecraftpe/command/WrongUsageException.h"
#include "minecraftpe/command/server/MessageCommand.h"
#include "minecraftpe/entity/player/Player.h"

using std::string;
using std::vector;

string MessageCommand::getCommandName() const {
	return "tell";
}

int MessageCommand::getRequiredPermissionLevel() const {
	return 0;
}

string MessageCommand::getCommandUsage() const {
	return "/tell <플레이어> <메시지...>";
}

const vector<string> *MessageCommand::getCommandAliases() const {
	vector<string> *aliases = new vector<string>;
	aliases->push_back("w");
	aliases->push_back("msg");

	return aliases;
}

void MessageCommand::processCommand(Minecraft *minecraft, Player *sender, const vector<string> &args) {
	if(args.size() < 2) {
		throw WrongUsageException(getCommandUsage(), {});
	}

	Player *target = getPlayer(sender, args[0]);
	if(target == sender) {
		throw PlayerNotFoundException("자기 자신에게는 메시지를 보낼 수 없습니다!", {});
	}

	string message;
	vector<string> messages(args.begin() + 1, args.end());
	message = joinText(messages, " ");

	target->displayClientMessage("§o§7" + sender->_playerName + "의 메시지: " + message);
	sender->displayClientMessage("§o§7" + target->_playerName + "에게 보낸 메시지: " + message);
}
