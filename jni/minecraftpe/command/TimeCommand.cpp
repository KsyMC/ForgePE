#include "minecraftpe/util/Util.h"
#include "minecraftpe/level/Level.h"
#include "minecraftpe/client/Minecraft.h"
#include "minecraftpe/network/ServerSideNetworkHandler.h"
#include "minecraftpe/command/TimeCommand.h"
#include "minecraftpe/command/WrongUsageException.h"
#include "minecraftpe/entity/player/Player.h"

using std::string;
using std::vector;

string TimeCommand::getCommandName() const {
	return "time";
}

int TimeCommand::getRequiredPermissionLevel() const {
	return 2;
}

string TimeCommand::getCommandUsage() const {
	return "/time <set|add> <값>";
}

void TimeCommand::processCommand(Minecraft *minecraft, Player *sender, const vector<string> &args) {
	if(args.size() < 2) {
		throw WrongUsageException(getCommandUsage(), {});
	}

	int time;

	if(!args[0].compare("set")) {
		if(!args[1].compare("day")) {
			time = 1000;
		} else if(!args[1].compare("night")) {
			time = 13000;
		} else {
			time = parseIntWithMin(sender, args[1], 0);
		}
		setTime(sender, time);
		((ServerSideNetworkHandler *) minecraft->_netEventCallback)->displayGameMessage("server", "시간을 " + Util::toString(time) + "(으)로 변경하였습니다");
	} else if(!args[0].compare("add")) {
		time = parseIntWithMin(sender, args[1], 0);
		addTime(sender, time);
		((ServerSideNetworkHandler *) minecraft->_netEventCallback)->displayGameMessage("server", "시간을 " + Util::toString(time) + "만큼 추가하였습니다");
	}
}

void TimeCommand::setTime(Player *sender, int time) {
	sender->_level->setTime(time);
}

void TimeCommand::addTime(Player *sender, int time) {
	sender->_level->setTime(sender->_level->getTime() + time);
}
