#include "minecraftpe/command/ServerCommandManager.h"
#include "minecraftpe/command/HelpCommand.h"
#include "minecraftpe/command/GiveCommand.h"
#include "minecraftpe/command/ServerKickCommand.h"
#include "minecraftpe/command/TimeCommand.h"
#include "minecraftpe/command/ShowSeedCommand.h"
#include "minecraftpe/command/KillCommand.h"
#include "minecraftpe/command/server/BroadcastCommand.h"
#include "minecraftpe/command/server/MessageCommand.h"
#include "minecraftpe/command/server/TeleportCommand.h"

ServerCommandManager::ServerCommandManager(Minecraft *minecraft) : CommandHandler(minecraft) {
	registerCommand(new GiveCommand);
	registerCommand(new HelpCommand);
	registerCommand(new ServerKickCommand);
	registerCommand(new MessageCommand);
	registerCommand(new TeleportCommand);
	registerCommand(new TimeCommand);
	registerCommand(new ShowSeedCommand);
	registerCommand(new KillCommand);
	registerCommand(new BroadcastCommand);
}
