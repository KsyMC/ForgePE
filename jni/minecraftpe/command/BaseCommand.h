#pragma once

#include "minecraftpe/command/ICommand.h"

class Item;
class Tile;

class BaseCommand : public ICommand {
public:
	virtual ~BaseCommand() {};
	virtual const std::vector<std::string> *getCommandAliases() const;
	virtual int getRequiredPermissionLevel() const;
	virtual bool canCommandSenderUseCommand(Player *);
	static int parseInt(Player *, const std::string &);
	static int parseIntWithMin(Player *, const std::string &, int);
	static int parseIntBounded(Player *, const std::string &, int, int);
	static double parseDouble(Player *, const std::string &);
	static double parseDoubleWithMin(Player *, const std::string &, double);
	static double parseDoubleBounded(Player *, const std::string &, double, double);
	static bool parseBool(Player *, const std::string &);
	static Player *getPlayer(Player *, const std::string &);
	static Item *getItemByText(Player *, const std::string &);
	static Tile *getTileByText(Player *, const std::string &);
	static bool doesStringStartWith(const std::string &, const std::string &);
	static const std::vector<std::string> *getListOfStringsMatchingLastWord(const std::vector<std::string> &, const std::vector<std::string> &);
	static std::string joinText(const std::vector<std::string> &, const char *const);
};
