#pragma once

#include "minecraftpe/client/gui/Screen.h"

namespace Touch {
class THeader;
class TButton;
}
class TextBox;
class Label;
class NinePatchLayer;

class ServerManagerOptionScreen : public Screen {
public:
	Touch::THeader *_titleHeader;
	Label *_nameLabel;
	Label *_portLabel;
	Label *_maxPlayersLabel;
	TextBox *_nameTextBox;
	TextBox *_portTextbox;
	TextBox *_maxPlayersTextBox;
	Touch::TButton *_backButton;
	Touch::TButton *_saveButton;
	NinePatchLayer *_backgroundLayer;

public:
	ServerManagerOptionScreen();
	virtual ~ServerManagerOptionScreen();
	virtual void render(int, int, float);
	virtual void init();
	virtual void setupPositions();
	virtual bool handleBackEvent(bool);
	virtual void buttonClicked(Button *);
	void closeScreen();
};
