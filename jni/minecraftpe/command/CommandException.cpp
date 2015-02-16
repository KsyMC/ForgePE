#include "minecraftpe/command/CommandException.h"

using std::string;
using std::vector;

const char *CommandException::what() const throw() {
	return _message.c_str();
}

string CommandException::getMessage() const throw() {
	return _message;
}

vector<string> CommandException::getErrorOjbects() const throw() {
	return _errorObjects;
}
