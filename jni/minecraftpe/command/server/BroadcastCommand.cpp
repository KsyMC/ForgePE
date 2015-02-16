#include "minecraftpe/client/Minecraft.h"
#include "minecraftpe/network/ServerSideNetworkHandler.h"
#include "minecraftpe/command/WrongUsageException.h"
#include "minecraftpe/command/server/BroadcastCommand.h"
#include "minecraftpe/entity/player/Player.h"

using std::vector;
using std::string;

string BroadcastCommand::getCommandName() const {
	return "say";
}

int BroadcastCommand::getRequiredPermissionLevel() const {
	return 1;
}

string BroadcastCommand::getCommandUsage() const {
	return "/say <메시지...>";
}

void BroadcastCommand::processCommand(Minecraft *minecraft, Player *sender, const vector<string> &args) {
	if(args.size() < 1 || args[0].empty()) {
		throw WrongUsageException(getCommandUsage(), {});
	}
	vector<string> messages(args.begin(), args.end());
	((ServerSideNetworkHandler *) minecraft->_netEventCallback)->displayGameMessage(sender->_playerName, joinText(messages, " "));
}
