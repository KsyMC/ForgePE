#pragma once

#include <string>
#include <vector>
#include <exception>

class CommandException : public std::exception {
public:
	std::string _message;
	std::vector<std::string> _errorObjects;

public:
	CommandException(const std::string &what, const std::vector<std::string> &errorObjects) throw() : _message(what), _errorObjects(errorObjects) {}
	virtual const char *what() const throw();
	std::string getMessage() const throw();
	std::vector<std::string> getErrorOjbects() const throw();
};
