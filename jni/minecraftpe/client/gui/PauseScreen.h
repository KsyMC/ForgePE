#pragma once

#include "minecraftpe/level/LevelListener.h"
#include "minecraftpe/client/gui/Screen.h"

namespace Touch {
class TButton;
}
class Label;

class PauseScreen : public Screen, public LevelListener {
public:
	// Size : 140
	//void **vtable;				// 200
	char filler1[12];				// 204
	Touch::TButton *_backButton;	// 216
	Touch::TButton *_quitButton;	// 220
	Touch::TButton *_quitCopyButton;// 224
	Touch::TButton *_optionButton;	// 228
	Label *_gameMenuLabel;			// 232
	Label *_playerList;				// 236

public:
	PauseScreen(bool);
	virtual ~PauseScreen();
	virtual void render(int, int, float);
	virtual void init();
	virtual void setupPositions();
	virtual bool handleBackEvent(bool);
	virtual void tick();
	virtual bool renderGameBehind();
	virtual void buttonClicked(Button *);
	virtual void controllerDirectionChanged();
	virtual void onEntityAdded();
	virtual void onEntityRemoved();
};
