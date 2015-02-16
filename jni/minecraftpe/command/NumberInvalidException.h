#pragma once

#include "minecraftpe/command/CommandException.h"

class NumberInvalidException : public CommandException {
public:
	NumberInvalidException() throw() : CommandException("'%s'은(는) 유효한 숫자가 아닙니다", {}) {}
	NumberInvalidException(const std::string &what, const std::vector<std::string> &errorObjects) throw() : CommandException(what, errorObjects) {}
};
