#pragma once

class GuiMessage {
public:
	int _wtf;				// 0
	int _code;				// 4
	std::string _sender;	// 8
	std::string _message;	// 12
	std::string _wtf2;		// 16

public:
	GuiMessage(const std::string &, const std::string &, int);
};
