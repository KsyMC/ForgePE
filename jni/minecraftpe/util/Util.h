#pragma once

#include <string>
#include <vector>

class Util {
public:
	static const std::string EMPTY_STRING;

public:
	static std::string toString(float);
	static std::string toString(int);
	static std::string toLower(const std::string &);
	static std::string toNiceString(int);
	static std::string removeIllegalChars(const std::string &);
	static std::vector<std::string> split(const std::string &, char);
	static bool startsWith(const std::string &, const std::string &);
	static void stringReplace(std::string &, const std::string &, const std::string &, int);
	static void stringTrim(const std::string &);
};
