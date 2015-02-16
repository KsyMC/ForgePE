#include <vector>
#include <string>

#include "minecraftpe/command/ServerKickCommand.h"

using std::string;
using std::vector;

string ServerKickCommand::getCommandName() const {
	return "kick";
}

int ServerKickCommand::getRequiredPermissionLevel() const {
	return 2;
}

string ServerKickCommand::getCommandUsage() const {
	return "/kick <플레이어> [이유...]";
}

void ServerKickCommand::processCommand(Minecraft *, Player *sender, const vector<string> &args) {
	/*ServerSideNetworkHandler *networkHandler = (ServerSideNetworkHandler *) minecraft->_netEventCallback;
	Level *level = minecraft->_level;
	Player *senderPlayer = level->getPlayer(args[0].getText(Util::EMPTY_STRING));

	if(!playerIsOp(senderPlayer->_playerName)) {
		return sendMessage(minecraft, senderPlayer, "이 명령어의 권한이 없습니다");
	} else if(args.size() < 2) {
		return sendMessage(minecraft, senderPlayer, getCommandUsage());
	}

	string reason;

	if(args.size() == 3) {
		reason = args[2].getText(Util::EMPTY_STRING);
	}

	Player *target = level->getPlayer(args[1].getText(Util::EMPTY_STRING));
	if(!target) {
		return sendMessage(minecraft, senderPlayer, "그 플레이어를 찾을 수 없습니다");
	}

	//ServerPlayer *serverPlayer = (ServerPlayer *) player;
	//serverPlayer->disconnect();
	target->remove();
	networkHandler->displayGameMessage("server", target->_playerName + "을(를) 게임에서 쫓아냈습니다" + (reason.empty() ? "" : (": '" + reason + "'")));*/
}
