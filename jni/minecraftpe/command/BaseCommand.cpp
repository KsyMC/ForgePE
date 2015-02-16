#include <limits>
#include <sstream>
#include <iterator>

#include "minecraftpe/util/Util.h"
#include "minecraftpe/item/Item.h"
#include "minecraftpe/tile/Tile.h"
#include "minecraftpe/item/ItemInstance.h"
#include "minecraftpe/level/Level.h"
#include "minecraftpe/command/BaseCommand.h"
#include "minecraftpe/command/NumberInvalidException.h"
#include "minecraftpe/command/PlayerNotFoundException.h"
#include "minecraftpe/entity/player/Player.h"

using std::string;
using std::vector;
using std::exception;
using std::numeric_limits;
using std::stringstream;
using std::copy;
using std::ostringstream;
using std::ostream_iterator;

int BaseCommand::getRequiredPermissionLevel() const {
	return 4;
}

const vector<string> *BaseCommand::getCommandAliases() const {
	vector<string> *aliases = new vector<string>;

	return aliases;
}

bool BaseCommand::canCommandSenderUseCommand(Player *sender) {
	return true;

	string cmdName = getCommandName();

	if(!cmdName.compare("seed") && sender->_level->isMultiLevel) {
		return true;
	} else if(cmdName.compare("tell") && cmdName.compare("help") && cmdName.compare("me")) {
		return false;
	}

	return true;
}

int BaseCommand::parseInt(Player *sender, const string &str) {
	stringstream ss(str);

	int i;
	ss >> i;

	char c;
	if (ss.fail() || ss.get(c)) {
		throw NumberInvalidException();
	}

	return i;
}

int BaseCommand::parseIntWithMin(Player *sender, const string &str, int min) {
	parseIntBounded(sender, str, min, numeric_limits<int>::max());
}

int BaseCommand::parseIntBounded(Player *sender, const string &str, int min, int max) {
	int i = parseInt(sender, str);

	if(i < min) {
		throw NumberInvalidException("입력한 숫자(" + Util::toString(i) + ")가 너무 작습니다. 최소한 " + Util::toString(min) + " 이상이어야 합니다.", {});
	} else if(i > max) {
		throw NumberInvalidException("입력한 숫자(" + Util::toString(i) + ")가 너무 큽니다. 최대 " + Util::toString(max) + " 이하여야 합니다.", {});
	}

	return i;
}

double BaseCommand::parseDouble(Player *sender, const string &str) {
	stringstream ss(str);

	double i;
	ss >> i;

	char c;
	if (ss.fail() || ss.get(c)) {
		throw NumberInvalidException();
	}

	return i;
}

double BaseCommand::parseDoubleWithMin(Player *sender, const string &str, double min) {
	parseDoubleBounded(sender, str, min, numeric_limits<double>::max());
}

double BaseCommand::parseDoubleBounded(Player *sender, const string &str, double min, double max) {
	double i = parseDouble(sender, str);

	if(i < min) {
		throw NumberInvalidException("입력한 숫자(" + Util::toString((float) i) + ")가 너무 작습니다. 최소한 " + Util::toString((float) min) + " 이상이어야 합니다.", {});
	} else if(i > max) {
		throw NumberInvalidException("입력한 숫자(" + Util::toString((float) i) + ")가 너무 큽니다. 최대 " + Util::toString((float) max) + " 이하여야 합니다.", {});
	}

	return i;
}

bool BaseCommand::parseBool(Player *sender, const string &str) {
	if(!str.compare("true") || !str.compare("1")) {
		return true;
	} else if(!str.compare("false") || !str.compare("0")) {
		return false;
	}

	throw CommandException("'" + str + "'은(는) 참과 거짓이 아닙니다", {});
}

Player *BaseCommand::getPlayer(Player *sender, const string &name) {
	Player *player = sender->_level->getPlayer(name);
	if(!player) {
		throw PlayerNotFoundException();
	}

	return player;
}

Item *BaseCommand::getItemByText(Player *sender, const string &text) {
	Item *item;

	ItemInstance itemInstance = Item::getIDByName(text, true);
	if(itemInstance.isNull()) {
		item = Item::items[parseInt(sender, text)];
	} else {
		item = itemInstance._item;
	}

	if(!item) {
		throw NumberInvalidException("ID가 " + text + "인 아이템이 없습니다", {});
	}

	return item;
}

Tile *BaseCommand::getTileByText(Player *sender, const string &text) {
	Tile *tile;

	int tileId = Tile::getIDByName(text, true);
	if(!(tile = Tile::tiles[tileId])) {
		tile = Tile::tiles[parseInt(sender, text)];
	}

	if(!tile) {
		throw NumberInvalidException("ID가 " + text + "인 아이템이 없습니다", {});
	}

	return tile;
}

bool BaseCommand::doesStringStartWith(const string &str1, const string &str2) {

}

const vector<string> *BaseCommand::getListOfStringsMatchingLastWord(const vector<string> &, const vector<string> &) {

}

string BaseCommand::joinText(const vector<string> &texts, const char *const delim) {
	ostringstream imploded;
	copy(texts.begin(), texts.end(), ostream_iterator<string>(imploded, delim));

	return imploded.str();
}
