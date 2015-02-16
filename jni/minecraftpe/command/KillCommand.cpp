#include <limits>

#include "minecraftpe/command/KillCommand.h"
#include "minecraftpe/entity/player/Player.h"

using std::vector;
using std::string;
using std::numeric_limits;

string KillCommand::getCommandName() const {
	return "kill";
}

int KillCommand::getRequiredPermissionLevel() const {
	return 0;
}

string KillCommand::getCommandUsage() const {
	return "/kill [플레이어|엔티티]";
}

void KillCommand::processCommand(Minecraft *minecraft, Player *sender, const vector<string> &args) {
	sender->hurt(NULL, numeric_limits<int>::max());
	sender->displayClientMessage(sender->_playerName + "을(를) 죽였습니다");
}
