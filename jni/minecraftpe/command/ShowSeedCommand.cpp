#include "minecraftpe/level/Level.h"
#include "minecraftpe/command/ShowSeedCommand.h"
#include "minecraftpe/entity/player/Player.h"

using std::vector;
using std::string;

bool ShowSeedCommand::canCommandSenderUseCommand(Player *sender) {
	return BaseCommand::canCommandSenderUseCommand(sender);
}

string ShowSeedCommand::getCommandName() const {
	return "seed";
}

int ShowSeedCommand::getRequiredPermissionLevel() const {
	return 2;
}

string ShowSeedCommand::getCommandUsage() const {
	return "/seed";
}

void ShowSeedCommand::processCommand(Minecraft *minecraft, Player *sender, const vector<string> &args) {
	char buffer[50];
	sprintf(buffer, "%ld", sender->_level->getSeed());

	sender->displayClientMessage(string("시드: ") + buffer);
}
