#pragma once

#include "minecraftpe/client/settings/Options.h"
#include "minecraftpe/client/gui/GuiElement.h"

namespace Touch {
class TButton;
}
class Screen;

class TextBox : public GuiElement {
public:
	// Size : 168
	static const char *extendedAcsii;
	static const char *numberChars;

public:
	int _key;					// 108
	Touch::TButton *_doneButton;// 112
	char filler1[12];			// 116
	std::string _text;			// 128
	std::string _titleText;		// 132
	bool _isFocus;				// 136
	char filler2[7];			// 137
	const char *_validChars;	// 144
	uint _charsLength;			// 148
	char filler3[16];			// 152

public:
	TextBox(MinecraftClient *, const Options::Option *, const std::string &);
	TextBox(MinecraftClient *, const std::string &, int, const char *, int, Screen *, void (Screen::*)(int), int);
	virtual void tick(MinecraftClient *);
	virtual void render(MinecraftClient *, int, int);
	virtual void topRender(MinecraftClient *, int, int);
	virtual void mouseClicked(MinecraftClient *, int, int, int);
	virtual void mouseReleased(MinecraftClient *, int, int, int);
	virtual void focusuedMouseClicked(MinecraftClient *, int, int, int);
	virtual void focusuedMouseReleased(MinecraftClient *, int, int, int);
	virtual void keyPressed(MinecraftClient *, int);
	virtual void keyboardNewChar(MinecraftClient *, std::string, bool);
	virtual bool backPressed(MinecraftClient *, bool);
	virtual bool suppressOtherGUI();
	virtual void setTextboxText(const std::string &);
	virtual void setFocus(MinecraftClient *);
	virtual void loseFocus(MinecraftClient *);
	int getKey();
	std::string getText() const;
	void setText(const std::string &);
	void setValidChars(char const *, uint);
};
