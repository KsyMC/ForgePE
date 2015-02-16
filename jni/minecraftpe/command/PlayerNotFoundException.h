#pragma once

#include "minecraftpe/command/CommandException.h"

class PlayerNotFoundException : public CommandException {
public:
	PlayerNotFoundException() throw() : CommandException("그 플레이어를 찾을 수 없습니다", {}) {}
	PlayerNotFoundException(const std::string &what, const std::vector<std::string> &errorObjects) throw() : CommandException(what, errorObjects) {}
};
