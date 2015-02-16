#pragma once

#include "minecraftpe/command/CommandException.h"

class SyntaxErrorException : public CommandException {
public:
	SyntaxErrorException() throw() : CommandException("잘못된 명령 구문입니다", {}) {}
};
