#pragma once

class Token {
public:
	enum Type {};

public:
	// Size : 16
	char filler1[8];	// 0
	Token::Type _type;	// 8
	char filler2[4];	// 12

public:
	Token(const std::string &);
	bool compatibleWith(Token::Type) const;
	bool getBool(bool) const;
	const std::string &getText(const std::string &) const;
	int getValue(int) const;
	void _parseRandom();
	static Token tokenize(const std::string &);
};
