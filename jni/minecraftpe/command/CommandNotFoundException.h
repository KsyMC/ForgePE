#pragma once

#include "minecraftpe/command/CommandException.h"

class CommandNotFoundException : public CommandException {
public:
	CommandNotFoundException() throw() : CommandException("알 수 없는 명령입니다. /help에서 명령어 목록을 참조하세요", {}) {}
	CommandNotFoundException(const std::string &what, const std::vector<std::string> &errorObjects) throw() : CommandException(what, errorObjects) {}
};
