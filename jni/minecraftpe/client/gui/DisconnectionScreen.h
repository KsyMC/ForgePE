#pragma once

#include "minecraftpe/client/gui/Screen.h"

namespace Touch {
class TButton;
}

class DisconnectionScreen : public Screen {
public:
	// Size : 208
	std::string _text;			// 200
	Touch::TButton *_okButton;	// 204

public:
	DisconnectionScreen(std::string text) {
		_text = text;
		_okButton = NULL;
	}
	virtual ~DisconnectionScreen();
	virtual void render(int, int, float);
	virtual void init();
	virtual bool isInGameScreen();
	virtual void buttonClicked(Button *);
};
