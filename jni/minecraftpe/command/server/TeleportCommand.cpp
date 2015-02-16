#include "minecraftpe/util/Util.h"
#include "minecraftpe/client/Minecraft.h"
#include "minecraftpe/network/ServerSideNetworkHandler.h"
#include "minecraftpe/command/WrongUsageException.h"
#include "minecraftpe/command/PlayerNotFoundException.h"
#include "minecraftpe/command/server/TeleportCommand.h"
#include "minecraftpe/entity/player/Player.h"

using std::vector;
using std::string;

string TeleportCommand::getCommandName() const {
	return "tp";
}

int TeleportCommand::getRequiredPermissionLevel() const {
	return 2;
}

string TeleportCommand::getCommandUsage() const {
	return "/tp [이동시킬 플레이어] <목표할 플레이어> 또는 /tp [이동시킬 플레이어] <x> <y> <z>";
}

void TeleportCommand::processCommand(Minecraft *minecraft, Player *sender, const vector<string> &args) {
	if(args.size() < 1) {
		throw WrongUsageException(getCommandUsage(), {});
	}

	Player *target;

	if(args.size() != 2 && args.size() != 4) {
		target = sender;
	} else {
		target = getPlayer(sender, args[0]);
		if(!target) {
			throw PlayerNotFoundException();
		}
	}

	if(args.size() != 3 && args.size() != 4) {
		if(args.size() == 1 || args.size() == 2) {
			Player *destPlayer = getPlayer(sender, args[args.size() - 1]);
			if(!target) {
				throw PlayerNotFoundException();
			}

			target->ride(NULL);
			target->teleportTo(destPlayer->_x, destPlayer->_y, destPlayer->_z);
			((ServerSideNetworkHandler *) minecraft->_netEventCallback)->displayGameMessage("server", target->_playerName + "이(가) " + destPlayer->_playerName + "에게로 순간이동 했습니다");
		}
	} else {
		int i = args.size() - 3;
		double d0 = parseDouble(sender, args[i++]);
		double d1 = parseDouble(sender, args[i++]);
		double d2 = parseDouble(sender, args[i++]);

		target->ride(NULL);
		target->teleportTo(d0, d1, d2);
		((ServerSideNetworkHandler *) minecraft->_netEventCallback)->displayGameMessage("server", target->_playerName + "이(가) " + Util::toString((float) d0) + ", " + Util::toString((float) d1) + ", " + Util::toString((float) d2) + " 좌표로 순간이동 했습니다");
	}
}
