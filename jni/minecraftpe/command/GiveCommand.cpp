#include "minecraftpe/util/Util.h"
#include "minecraftpe/tile/Tile.h"
#include "minecraftpe/item/Item.h"
#include "minecraftpe/item/ItemInstance.h"
#include "minecraftpe/level/Level.h"
#include "minecraftpe/command/GiveCommand.h"
#include "minecraftpe/command/WrongUsageException.h"
#include "minecraftpe/entity/player/Player.h"

using std::vector;
using std::string;

string GiveCommand::getCommandName() const {
	return "give";
}

int GiveCommand::getRequiredPermissionLevel() const {
	return 2;
}

string GiveCommand::getCommandUsage() const {
	return "/give <플레이어> <아이템> [양] [데이터]";
}

void GiveCommand::processCommand(Minecraft *minecraft, Player *sender, const vector<string> &args) {
	if(args.size() < 2) {
		throw WrongUsageException(getCommandUsage(), {});
	}

	Player *target = getPlayer(sender, args[0]);

	int id;

	Item *item;
	Tile *tile;
	if((item = getItemByText(sender, args[1]))) {
		id = item->_id;
	} else if((tile = getTileByText(sender, args[1]))) {
		id = tile->_id;
	}

	int count = 1;
	int damage = 0;

	if(args.size() >= 3) {
		count = parseIntBounded(sender, args[2], 1, 64);
	}

	if(args.size() >= 4) {
		damage = parseInt(sender, args[3]);
	}

	ItemInstance *itemInstance = new ItemInstance(id, count, damage);
	if(itemInstance->_item) {
		sender->drop(itemInstance);
		sender->displayClientMessage(sender->_playerName + "에게 " + itemInstance->getName() + "이(가) " + Util::toString(count) + "개 주어졌습니다");
	}
}
