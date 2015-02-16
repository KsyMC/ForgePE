#pragma once

#include "minecraftpe/command/CommandException.h"

class WrongUsageException : public CommandException {
public:
	WrongUsageException(const std::string &what, const std::vector<std::string> &errorObjects) throw() : CommandException(what, errorObjects) {}
};
