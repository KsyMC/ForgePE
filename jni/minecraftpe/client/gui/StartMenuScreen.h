#pragma once

#include "minecraftpe/client/gui/Screen.h"
#include "minecraftpe/client/gui/TButton.h"

class ImageWithBackground;

namespace Touch {
class StartMenuScreen : public Screen {
public:
	static int currentSplash;

public:
	// Size : 496
	Touch::TButton _playButton;			// 200
	Touch::TButton _realmButton;		// 328
	ImageWithBackground *_optionButton;	// 456
	char filler1[36];					// 460

public:
	StartMenuScreen();
	virtual ~StartMenuScreen();
	virtual void render(int, int, float);
	virtual void init();
	virtual void setupPositions();
	virtual bool handleBackEvent(bool);
	virtual void tick();
	virtual bool isInGameScreen();
	virtual void buttonClicked(Button *);
	virtual void controllerDirectionChanged(int, Controller::StickDirection);

public:
	typedef void (*InitReal)(StartMenuScreen *);
	typedef void (*SetupPositionsReal)(StartMenuScreen *);
	typedef void (*ButtonClickedReal)(StartMenuScreen *, Button *);

	static InitReal init_real;
	static SetupPositionsReal setupPositions_real;
	static ButtonClickedReal buttonClicked_real;
	static Touch::TButton *_optionSMButton;

	static void initHooks(void *);
	void init_hook();
	void setupPositions_hook();
	void buttonClicked_hook(Button *);
};
}
